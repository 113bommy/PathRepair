#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 7;
ll a[N];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	ll ans1 = 2, ans2 = 2;
	for (int i = n; i >= 1; i--) {
		ans1 = (ans1 - 1) / a[i] + 1, ans2 = ans2 / a[i];
		if (ans1 > ans2) {
			puts("-1");
			return 0;
		}
		ans1 *= a[i];
		ans2 = ans2 * a[i] + a[i] - 1;
	}
	printf("%lld %lld\n", ans1, ans2);
	return 0;
}