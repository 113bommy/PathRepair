#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	map<int,int> f;
	rep(i,n){ int a; cin>>a; ++f[a]; }

	int ans=0;
	for(auto x:f) ans+=x.second%2;
	cout<<ans<<endl;

	return 0;
}
