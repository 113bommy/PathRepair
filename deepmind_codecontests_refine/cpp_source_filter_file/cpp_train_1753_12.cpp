#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
unsigned long long k,k,a;
int ans;
int main(){
	cin>>k>>a>>b;
	if(a>=k){
		cout<<"1\n";
		return 0;
	}
	if(b>=a){
		cout<<"-1\n";
		return 0;
	}
	if((k-a)%(a-b)>=1) ans=1;
	cout<<((k-a)/(a-b)+ans)*2+1<<endl;
 	return 0;
}