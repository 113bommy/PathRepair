#include"bits/stdc++.h"
using namespace std;
int main(){
	long long ans,n,k;
	cin>>n>>k;
	ans=k;
	for(int i=1;i!=n;++i)
		ans*=k-1;
	cout<<ans;
}
