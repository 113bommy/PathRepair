#include <bits/stdc++.h>
#define x first
#define y second
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define xmod 1000000007
using namespace std;

ll n,dp[200005],a[200005],c,q[200005],l,r;
ll sqr(ll x){
	return x*x;
}
bool m(ll a1,ll a2,ll now){
	if ((dp[a2]+sqr(a[a2]))-(dp[a1]+sqr(a[a1])) < 2*a[now]*(-a[a1]+a[a2]))
	return true;
	return false;
}
bool m2(ll a1,ll a2,ll a3){
	if ((double)((dp[a2]+sqr(a[a2]))-(dp[a1]+sqr(a[a1])))/(double)(-a[a1]+a[a2]) < (double)((dp[a3]+sqr(a[a3]))-(dp[a2]+sqr(a[a2])))/(double)(-a[a2]+a[a3]))
	return true;
	return false;
}
int main(){ 
	ios::sync_with_stdio(false);
	cin >> n >> c; 
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	q[1]=1; l=1; r=1;
	for (int i=2;i<=n;i++){
		while (r-l >= 1 && m(q[l],q[l+1],i)){
			l++;
		}
		dp[i]=dp[q[l]]+sqr(a[i]-a[q[l]])+c;
		while (r-l >= 1 && m2(i,q[r],q[r-1])){
			r--;
		}
		r++;
		q[r]=i;
	}
	cout << dp[n] << "\n";
    return 0; 
} 