#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
void solve(){
	ll n,k;
	cin>>n>>k;
	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];
	ll prod=1;
	sort(a.begin(),a.end());
	if(a[n-1]==0&&k%2==1) {cout<<0;return;}
	if(a[n-1]<0&&k&1){
		for(ll i=n-1;i>=n-k;i--){
			prod=(a[i]*prod)%mod;
		}
	}
	cout<<((prod%mod)+mod)%mod;return;
	}
	ll i=0;ll j=n-1;
	if(a[n-1]>0&&k&1){
		prod=(prod*a[n-1])%mod;
		j--;k--;
	}
	k=k>>1;
	for(ll itr=0;itr<k;itr++){
		ll lprod=a[i]*a[i+1];
		ll rprod=a[j]*a[j-1];
		if(lprod>rprod){
			prod=prod*a[i]%mod*a[i+1]%mod;
			i+=2;
		}
		else{
			prod=prod*a[j]%mod*a[j-1]%mod;
			j-=2;
		}
	}
	if(prod<0) cout<<((prod%mod)+mod)%mod;
	else cout<<prod%mod;
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);	 
	int T=1;
	// cin>>T;
	while(T--){
		solve();
	}
	return 0;
}