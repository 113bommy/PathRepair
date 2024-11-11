#include<bits/stdc++.h>
using namespace std;
int main(){
	long long double a,b;
  cin>>a>>b;
  if(a>b){
  	cout<<"GREAT"<<endl;
  }
  else if(a<b){
  	cout<<"LESS"<<endl;
  }
  else if(a == b){
  	cout<<"EQUAL"<<endl;
  }

	return 0;
}