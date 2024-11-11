#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

int N,a[4],S,L,cnt;

int main(){
	while(1){
		cnt=0;
		cin>>N;
		if(N==0){break;}
		if(N%1111==0){
			cout<<"NA"<<endl;
			continue;
		}
		while(N!=6174){
			a[0]=N/1000;
			a[1]=(N%1000)/100;
			a[2]=(N%100)/10;
			a[3]=N%10;
			sort(a,a+4);
			L=a[3]*1000+a[2]*100+a[1]*10+a[0];
			S=a[0]*1000+a[1]*100+a[2]*10+a[3];
			N=L-S;
			cnt++;
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}