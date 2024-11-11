#include <bits/stdc++.h>
using namespace std;
const long long N = 1e2 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9,
                inf = 1e18 + 7;
const long long infll = 1e18 + 7;
long long n, k, ans;
long long a[N];
vector<pair<pair<long long, long long>, long long>> b[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    long long t = 0;
    for (long long j = 0; j < a[i]; j++) {
      long long x, y;
      cin >> x >> y;
      t += y;
      b[i].push_back({{x, y}, t});
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      long long l = 0, r = 0, cur = 0, posl = 0, posr = 0;
      long long lead = 0;
      while (l != a[i] && r != a[j]) {
        long long newcur = min(b[i][l].second, b[j][r].second);
        long long newposl = posl + (newcur - cur) * b[i][l].first.first;
        long long newposr = posr + (newcur - cur) * b[j][r].first.first;
        if (lead == 1 && newposl < newposr) {
          ans++;
        }
        if (lead == 2 && newposl > newposr) {
          ans++;
        }
        if (newposl > newposr) {
          lead = 1;
        }
        if (newposl < newposr) {
          lead = 2;
        }
        if (b[i][l].second == newcur) l++;
        if (b[j][r].second == newcur) r++;
        cur = newcur;
        posl = newposl;
        posr = newposr;
      }
    }
  }
  cout << ans << '\n';
}
