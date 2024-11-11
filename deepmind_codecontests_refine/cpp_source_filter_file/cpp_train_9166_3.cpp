#include <iostream>
using namespace std;

int itp1_9c(void)
{
	int n, sc1=0,sc2=0;
	string card1,card2;
	cin>>n;
	for (;n--;){
		cin>>card1>>card2;
		if (card1>card2){
			sc1+=3;
		}else if (card2>card1){
			sc2+=3;
		}else if (card1==card2){
			sc1++;
			sc2++;
		}
	}
	cout<<sc1<<" "<<sc2<<endl;
	return 0;
}