#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 100010
ll n,m,h[N],ma[N];
//ma[i]计算的是i有连接的点的最大值 
int main(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>h[i];
	for(ll i=1;i<=m;i++){
		ll x,y;
		cin>>x>>y;
		ma[x]=max(ma[x],h[y]);
		ma[y]=max(ma[y],h[x]);
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ans+=h[i]>ma[i];
	}
	cout<<ans<<endl;
	return 0;
}
