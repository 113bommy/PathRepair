#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 2e5 + 5;

int n, d, a;
pii m[MAXN];
int endEff[MAXN];

int main() {
	cin >> n >> d >> a;
	for (int i = 0; i < n; i++) {
		cin >> m[i].first >> m[i].second;
	}
	sort(m, m + n);
	long long res = 0, cur = 0;
	for (int i = 0; i < n; i++) {
		cur -= endEff[i];
		if (cur * a < m[i].second) {
			long long h = m[i].second - cur * a;
			long long need = (h + a - 1) / a;
			res += need;
			cur += need;
			// st = i, end = n
			int nxt = upper_bound(m + i, m + n, make_pair(m[i].first + 2 * d, 0)) - m;
			endEff[nxt] += need;
		}
	}
	cout << res << endl;
	return 0;
}
