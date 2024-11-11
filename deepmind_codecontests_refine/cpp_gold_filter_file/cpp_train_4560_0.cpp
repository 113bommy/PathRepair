# include <bits/stdc++.h>
using namespace std;
# define ll long long
const int N = 2e5 + 10;
ll a[N] , b[N] , diff[N] , ans , k , n;
bool check(ll x){
	ll res = 0;
	for(int i = 0; i < n; i ++)
		res += max(0ll , a[i] - x / b[i]);
	return res <= k;
}
int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i ++) cin >> a[i];
	for(int i = 0; i < n; i ++) cin >> b[i];
	sort(a , a + n);
	sort(b , b + n);
	reverse(b , b + n);
	ll l = 0 , r = a[n - 1] * b[0];
	while(l <= r){
		ll m = (l + r) >> 1;
		if(check(m)) r = m - 1 , ans = m;
		else l = m + 1;
	}
	cout << ans << "\n";
}