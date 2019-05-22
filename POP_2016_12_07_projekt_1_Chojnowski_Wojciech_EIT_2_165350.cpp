/* POP 2016-12-07 projekt 1 Chojnowski Wojciech EIT 2 165350
Dev-C++ 5.11*/
#include<iostream>
#include<cstdlib>
#include<string>
#include <sstream>

using namespace std;



	const int MaxPrzedmiot=15;
	const int MaxDzien=105; /*{35 tygodni*3 dni weekendowe do 1.10.2017, czyli nowego semestru}*/

	struct Przedmiot
		{
			string Nazwa;
			string Skrot;
			int Poprz1,Poprz2;
			int DataP,DataK;
			int Konieczne,Zrobione;
		};

string CzytajStr(string S, int min, int max)
{
	string Str = "";
	do
	{
		
		cout<<S;
		cin.sync();
		getline(cin, Str);
	}
	while(Str.length()<min || Str.length()>max);


	return Str;
}


int CzytajInt(string S,int min, int max)
{
	int I;

	do
	{
		cout<<S;
		cin>>I;
	}while(I>max || I<min);
	return I;
}


int CzytajPoprz(string S, int Ile,struct Przedmiot T[],int P1)
{
	int Nr;
	cout<<S;
	cout<<endl;
	cout<<"0. Brak poprzedniego przedmiotu"<<endl;
	for(int i=1; i<=Ile;i++)
	{
		if(i!=P1)
		{
			cout<<i<<". "<<T[i].Nazwa<<endl;
		}
	}
	do
	{
		cin>>Nr;
	}while(((Nr>Ile) || (Nr==0) || (Nr==P1)) && Nr>0);



	return Nr;
}


string Data(int Dzien)
{
	int D=3;
	int M=2;
	int DoW=5;
	string L1,L2;

	for(int i=2;i<=Dzien;i++)
	{
		++DoW;
		if(DoW==8)
		{
			DoW=5;
			D=D+5;
		}
		else
		{
			D=D+1;
		}
		switch(M)
		{
			case 2:
				if(D>28)
				{
					D=D-28;
					M=M+1;
				}
			break;

			case 3:
				if(D>31)
				{
					D=D-31;
					M=M+1;
				}
			break;

			case 4:
				if(D>30)
				{
					D=D-30;
					M=M+1;
				}
			break;

			case 5:
				if(D>31)
				{
					D=D-31;
					M=M+1;
				}
			break;

			case 6:
				if(D>30)
				{
					D=D-30;
					M=M+1;
				}
			break;

			case 7:
				if(D>31)
				{
					D=D-31;
					M=M+1;
				}
			break;

			case 8:
				if(D>31)
				{
					D=D-31;
					M=M+1;
				}
			break;

			case 9:
				if(D>30)
				{
					D=D-30;
					M=M+1;
				}
			break;
		}
	}
	stringstream stringStream;
	stringStream << D;
	L1=stringStream.str();
    stringStream.str("");
	stringStream << M;
	L2=stringStream.str();
	return (L1+"."+L2+".2017");
}


int main()
{

    struct Przedmiot T[MaxPrzedmiot];
	int N=0;
	int D1;
	char Zn,Pop;
	string L,L1;
	bool Mozna,Skonczone;
	int o;
	string koniec="";
	do
	 {
	 cout<<"MENU"<<endl;
	 cout<<"1.Wprowadz informacje o planowanych przedmiotach"<<endl;
	 cout<<"2.Wyswietl informacje o przedmiotach"<<endl;
	 cout<<"3.Wyswietl terminy realizacji zajec"<<endl;
	 cout<<"4.Wyjscie z programu"<<endl;
	 cout<<endl;
	 cout<<"Wybierz opcje:";
	 cin>>o;

	 cout<<endl;

		 switch(o)
		 {
		 	case 1:
		 		cout<<"Wprowadzanie informacji o planowanych przedmiotach";
				cout<<endl;
				N=CzytajInt("Podaj ilosc przedmiotow (2...15): ",2,15);
				for(int i=1;i<=N;i++)
				{
				cout<<endl;
                    cout<<"Przedmiot nr "<<i<<endl;
                    T[i].Nazwa=CzytajStr("Podaj nazwe przedmiotu (5...30 znakow): ",5,30);
                    T[i].Skrot=CzytajStr("Podaj skrocona nazwe przedmiotu (2...4 znaki): ",2,4);
                    T[i].Konieczne=CzytajInt("Podaj ilosc dni realizacji (1...15): ",1,15);
                    T[i].Zrobione = 0;
                    T[i].Poprz1 = 0;
                    T[i].Poprz2 = 0;
                    T[i].DataP = 0;
                    T[i].DataK = 0;

					if(i!=1)
					{
						T[i].Poprz1=CzytajPoprz("Podaj identyfikator poprzedniego przedmiotu: ",i-1,T,0);
						if(i>2 && T[i].Poprz1!=0)
						{
							T[i].Poprz2=CzytajPoprz("Podaj identyfikator poprzedniego przedmiotu (2): ",i-1,T,T[i].Poprz1);
						}
					}
					cout<<endl;

				}
			break;

			case 2:
		 		

		 		if(N==0)
		 		{
		 			cout<<"Brak wpisanych przedmiotow"<<endl;
		 			cout<<endl;
				}
				else
				{
					cout<<"Lista przedmiotow:"<<endl;
		 			cout<<endl;
		 			cout<<"------------------------------------------"<<endl;
		 			cout<<"| PRZEDMIOT | Il. dni | Przedmiot poprz  |"<<endl;
		 			cout<<"------------------------------------------"<<endl;
					
					for(int i=1;i<=N;i++)
					{
						L="| "+T[i].Skrot;
						D1=L.length();
						for(int j=D1;j<=11;j++)
						{
							L=L+" ";
						}
						stringstream stringStream;
						stringStream << T[i].Konieczne;
						L1=stringStream.str();

						L=L+"|   "+L1+"    |  ";
						if(T[i].Poprz1<=0)

						{
							L=L+"      brak       |  ";
						}
						else
						{
							L=L+T[T[i].Poprz1].Skrot;
							if(T[i].Poprz2>0)
							{
								L=L+", "+T[T[i].Poprz2].Skrot;
							}
							D1=L.length();
							for(int j=D1;j<=40;j++)
							{
								L=L+" ";
							}
							L=L+"|";
						}
						cout<<L<<endl;
						cout<<"------------------------------------------"<<endl;
						cout<<endl;
					}
				}
			break;

			case 3:
			Skonczone=0;
			if(N==0)
			{
				cout<<"Brak wpisanych przedmiotow"<<endl;
			}
			else
			{
				for(int i=1;i<=N;i++) 
				{
                 T[i].Zrobione=0;
                 T[i].DataK=0;
                 T[i].DataP=0;
                }
				for(int Dzien=1;Dzien<=MaxDzien;Dzien++)
				{
					for(int i=1;i<=N;i++)
					{
						Mozna=0;
						if((T[i].Poprz1<=0) && (T[i].Poprz2<=0))
						{
							Mozna=1;
						}
						else
						{
							switch(T[i].Poprz2)
							{
								case 0:
									if(T[T[i].Poprz1].Konieczne==T[T[i].Poprz1].Zrobione)
									{
										if(T[T[i].Poprz1].DataK!=Dzien)
										{
											Mozna=1;
										}
								break;
									}
								default:
									{
										if((T[T[i].Poprz2].Konieczne==T[T[i].Poprz2].Zrobione) && (T[T[i].Poprz1].Konieczne==T[T[i].Poprz1].Zrobione))
										{
											if((T[T[i].Poprz1].DataK!=Dzien) && (T[T[i].Poprz2].DataK!=Dzien))
											{
												Mozna=1;
											}
										}
									}
								break;
							}
						}
						if((Mozna==1)&& (T[i].Konieczne!=T[i].Zrobione))
						{
							if(T[i].DataP<=0)
							{
								T[i].DataP=Dzien;
							}
							++(T[i].Zrobione);
							T[i].DataK=Dzien;
						}
					}
					Skonczone=1;
					for(int j=1;j<=N;j++)
					{
						if(T[j].Konieczne!=T[j].Zrobione)
						{
							Skonczone=0;
						}

						if(Skonczone==1)
						{
							break;
						}
					}
				}
			}
			if(Skonczone==1)
			{
				cout<<"Terminy Realizacji kolejnych zajec:"<<endl;
				cout<<endl;
				cout<<"------------------------------------------"<<endl;
				cout<<"| PRZEDMIOT |  Poczatek   |    Koniec    |"<<endl;
				cout<<"------------------------------------------"<<endl;

				for(int i=1;i<=N;i++)
				{
					L="| "+T[i].Skrot;
					D1=L.length();

					for(int j=D1;j<=11;j++)
					{
						L=L+" ";
					}

					L=L+"|  "+Data(T[i].DataP);
					D1=L.length();

					for(int j=D1;j<=25;j++)
					{
						L=L+" ";
					}

					L=L+"|   "+Data(T[i].DataK)+"  |";
					D1=L.length();

					for(int j=D1;j<=40;j++)
					{
						L=L+" ";
					}

					cout<<L<<endl;
					cout<<"------------------------------------------"<<endl;
					cout<<endl;
				}
			}
			
			for(int i=1;i<=N;i++)
			{
				koniec=Data(T[i].DataK);
				if(i==N)
				{
				cout<<"Studia beda trwaly do "<<koniec<<endl;
				}	
			}
			cout<<endl;

			break;

			case 4:
				cout<<"Wybrales wyjscie z programu"<<endl;
			break;
		 }
	}while(o!=4);

	return 0;
}



