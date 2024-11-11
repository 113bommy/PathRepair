#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
const int mod=1e9+7;
typedef long long ll;
ll a[maxn];
int main(){
	int n;
	cin>>n;
	ll sum=0;
	for(int i=0;i<n;i++)
	scanf("%lld",&a[i]);
	for(int i=0;i<=60;i++){
		int cnd=0;
		for(int j=0;j<n;j++){
			if((a[j]>>i)&1) cnd++;
		}
		sum=(sum+(1ll<<i)%mod*cnt%mod*(n-cnd))%mod;
	}
	cout<<sum%mod;
	return 0;
} 