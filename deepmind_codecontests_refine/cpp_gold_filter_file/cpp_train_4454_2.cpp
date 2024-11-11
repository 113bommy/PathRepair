#include<iostream>
using namespace std;
int main(){
	string a;
  cin>>a;
    long long r=0,n=a.size();
  for(long long i=0;i<n;i++){
  	r+=(a[i]-48);
  }
  if(r%9)	cout<<"No";
  else	cout<<"Yes";
}