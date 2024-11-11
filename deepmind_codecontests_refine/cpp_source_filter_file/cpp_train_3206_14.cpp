#include <bits/stdc++.h>
using namespace std;
long long int a,b,k;
int main(){
	cin>>a>>b>>k;
	if(a>k) cout<<a-k<<" "<<b;
	else if(k>(a+b))cout<<"0 0";
	else cout<<"0 "<<a+b-k;6 
	return 0;
}