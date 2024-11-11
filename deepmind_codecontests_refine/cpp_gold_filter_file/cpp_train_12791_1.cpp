#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(){
	int n;
	cin>>n;
	double xa,ya,xb,yb,ra,rb;
	for(int i=0;i<n;i++){
		cin>>xa>>ya>>ra>>xb>>yb>>rb;
		if(abs(ra+rb)<sqrt(pow(xa-xb,2)+pow(ya-yb,2))){cout<<0<<endl;}
		else if(abs(ra+rb)>=sqrt(pow(xa-xb,2)+pow(ya-yb,2)) && abs(ra-rb)<=sqrt(pow(xa-xb,2)+pow(ya-yb,2))){cout<<1<<endl;}
		else{if(ra>rb){cout<<2<<endl;}else{cout<<-2<<endl;}}
	}
	return 0;
}