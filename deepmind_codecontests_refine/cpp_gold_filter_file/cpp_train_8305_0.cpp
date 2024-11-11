#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;

ll n, ans, a[200005];
multiset<ll> st = {-1, -1};
int main() {
	ll i, t;
	multiset<ll>::iterator x, y, w, v;
	cin >> n;
	for(i=0; i<n; i++) scanf("%lld", &t), a[t] = i;
	st.insert(n);
	st.insert(n);
	for(i=n; i; i--) {
		x = st.lower_bound(a[i]);
		y = next(x);
		w = prev(x);
		v = prev(w);
		ans += i * ((*y-*x) * (a[i]-*w) + (*w-*v) * (*x-a[i]));
		st.insert(a[i]);
	}
	cout << ans;
	return 0;
}
