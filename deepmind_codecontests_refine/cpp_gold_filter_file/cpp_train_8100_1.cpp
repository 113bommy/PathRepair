#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
typedef long long ll;
//orz yht
using namespace std;
ll n,sum1,sum2;
vector<ll>tot;
int main(){
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    vector<pair<ll,ll> >v(n);
    for(ll i=0;i<n;i++){
    	cin>>v[i].first>>v[i].second;
    	tot.push_back(v[i].first);
    	tot.push_back(v[i].second);
	}
	for(auto x : v){
		sum1+=x.first;
		sum2+=x.second;
	}
	ll ans=min(sum1,sum2);
	ll sum=0;
	sort(tot.begin(),tot.end());
	for(ll i=0;i<n;i++)
	sum+=tot[i];
	for(ll i=0;i<n;i++){
		ll mx=max(v[i].first,v[i].second);
		ll mn=min(v[i].first,v[i].second);
		if(mn>tot[n-1] || mx<tot[n-1]){
			cout<<sum;
			return 0;
		}
		ll tmp=sum;
		tmp+=mx-tot[n-1]+max(0ll,mn-tot[n-2]);
		ans=min(ans,tmp);
	}
	cout<<ans;
	return 0;
}