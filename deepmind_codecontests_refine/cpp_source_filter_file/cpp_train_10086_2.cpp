#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

int w,sum;
string str;

int main(){
	while(1){
		cin>>>w;
		if(w==-1){break;}
		if(w<=10){cout<<4280-1150<<endl;}
		else if(w<=20){cout<<4280-(1150+(w-10)*125)<<endl;}
		else if(w<=30){cout<<4280-(1150+1250+(w-20)*140)<<endl;}
		else {cout<<4280-(1150+1250+1400+(w-30)*160)<<endl;}
	}
	
	return 0;
}