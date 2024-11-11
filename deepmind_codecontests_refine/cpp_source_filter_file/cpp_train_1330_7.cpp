#include<iostream>
using namespace std;
int mai(){
  int N=0;
  cin>>N;
  int a=N%10;
  	if(a==3) cout<<"bon";
  	else if(a==0||a==1||a==6||a==8) cout<<"pon";
  	else cout<<"hon";
}