#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const long long inf = 1e15;
vector<long long> f[3], g[3];
long long cap;
long long get(long long type, long long st) {
  long long id =
      lower_bound(g[type].begin(), g[type].end(), st) - g[type].begin();
  return f[type][id] + max(g[type][id] - st - cap, 0ll);
}
void solve() {
  long long n, m, last;
  cin >> last >> cap >> n >> m;
  for (long long i = 0; i < n; i++) {
    long long ty, v;
    cin >> ty >> v;
    if (v > last) continue;
    for (long long j = ty - 1; j >= 0; j--) g[j].emplace_back(v);
  }
  for (long long i = 0; i < 3; i++) {
    g[i].emplace_back(last);
    sort(g[i].begin(), g[i].end());
    f[i].resize(((long long)g[i].size()) + 1);
    for (long long j = ((long long)g[i].size()) - 1; j >= 0; j--) {
      f[i][j] = f[i][j + 1] + max(0ll, g[i][j + 1] - g[i][j] - cap);
    }
  }
  for (long long i = 0; i < m; i++) {
    long long v;
    cin >> v;
    if (get(0, v))
      cout << "-1 -1" << endl;
    else {
      long long tmp = get(1, v);
      cout << tmp << " " << get(2, v) - tmp << endl;
    }
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cout.precision(3);
  solve();
}
