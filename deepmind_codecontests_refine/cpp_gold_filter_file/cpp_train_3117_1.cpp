#include<iostream>
using namespace std;

int main(){
	while(1){
		int m,nmin,nmax;
		cin>>m>>nmin>>nmax;
		if(m==0&&nmin==0&&nmax==0){
			break;
		}
		int P[200];
		for(int i=0;i<m;i++){
			cin>>P[i];
		}
		int gap=-1;
		int n=-1;
		for(int i=nmin;i<=nmax;i++){
			int g=P[i-1]-P[i];
			if(gap<=g){
				gap=g;
				n=i;
			}
		}
		cout<<n<<endl;
	}
	return 0;
}
