#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;

ll n, a, mn=4e18, s[200005];
int main() {
	cin >> n;
	for(ll i=1; i<=n; i++) {
		scanf("%lld", &a);
		s[i] = s[i-1] + a;
	}
	for(ll i=1; i<=n; i++) {
		mn = min(mn, (ll)abs(2*s[i] - s[n]));
	}
	cout << mn;
	return 0;
}
