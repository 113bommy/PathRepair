#include<bits/stdc++.h>
using namespace std;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;


int main(){
	int n,m;
	cin>>n>>m;
	ll ans=0,sum=0;
	map<ll,ll>s;
	s[sum]++;
	rep(i,n){
		ll a;
		cin>>a;
		sum=(sum+a)%m;
		s[sum]++;
	}

	for(auto i:s){
		ans+=i.second*(i.second-1)/2;
	}

	cout<<ans<<endl;
	return 0;
}
