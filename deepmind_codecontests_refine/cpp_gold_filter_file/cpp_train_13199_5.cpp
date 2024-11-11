#include<bits/stdc++.h>
using namespace std;
long long n,ans=1e12;
int main(){
	cin>>n;
	for(int i=1;i<=sqrt(n);i++)
	    if(n%i==0) ans=min(ans,n/i+i-2);
	cout<<ans;
	return 0;
}