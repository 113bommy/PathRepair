#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl "\n"

int32_t main()
{
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
  	cout.tie(nullptr);
  
	ll n;
	cin>>n ;
	ll ans=0;
	for(ll i=1;i<=n;i++)
		ans+=i*(n-i+1);

	for(ll i=1;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		ans-=x*(n-y+1);
	}

	cout<<ans<<endl;
 
	
	return 0;
}
