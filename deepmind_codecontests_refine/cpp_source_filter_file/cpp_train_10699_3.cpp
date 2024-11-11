#include <bits/stdc++.h>
using namespace std;

const int maxn = 201;

int t, n;
long long a[maxn];
char s[maxn];
vector < long long > cur;

signed main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%lld", &a[i]);
		scanf("%s", &s);
		cur = {0};
		for (int i = n - 1; i >= 0; --i) {
			for (long long: cur)
				a[i] = min(a[i], a[i] ^ x);
			if (a[i] && s[i] == '1') {
				cur.clear();
				break;
			}
			else if (a[i])
				cur.push_back(a[i]);
		}
		printf("%d\n", int(cur.empty()));
	}
}
