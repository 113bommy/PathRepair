#include <bits/stdc++.h>
using namespace std;
void solve() {}
const long long maxn = 100500;
const long long maxd = 1005000;
const long long INF = 1e10;
vector<pair<long long, long long> > go[maxd], ret[maxd];
long long l[maxd], r[maxd];
long long mi[maxn];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long i = 1; i <= m; i++) {
    long long d, f, t, c;
    cin >> d >> f >> t >> c;
    if (t == 0) {
      go[d].emplace_back(f, c);
    } else {
      ret[d].emplace_back(t, c);
    }
  }
  for (long long i = 1; i <= n; i++) mi[i] = INF;
  long long cur = INF * n;
  for (long long i = 0; i <= 1e6; i++) {
    if (i <= 10)
      if (false) cerr << "on " << i << '\n';
    for (pair<long long, long long> x : go[i]) {
      if (false) cerr << x.first << " " << x.second << '\n';
      if (mi[x.first] > x.second) {
        long long reduced = mi[x.first] - x.second;
        cur -= reduced;
        if (false) cerr << "will reduce by " << reduced << '\n';
        mi[x.first] = x.second;
      }
    }
    if (i <= 10)
      if (false) cerr << ("cur") << " is " << (cur) << '\n';
    l[i] = cur;
  }
  for (long long i = 1; i <= n; i++) mi[i] = INF;
  cur = INF * n;
  for (long long i = 1e6; i >= 0; i--) {
    for (pair<long long, long long> x : ret[i]) {
      if (mi[x.first] > x.second) {
        long long reduced = mi[x.first] - x.second;
        cur -= reduced;
        mi[x.first] = x.second;
      }
    }
    r[i] = cur;
  }
  long long ans = 1e18;
  for (long long i = 1; i + k <= 1e6; i++) {
    ans = min(ans, l[i - 1] + r[i + k]);
  }
  if (ans > INF) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
}
