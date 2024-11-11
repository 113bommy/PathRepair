#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, a[N][N];
bitset<N> bs[N];
inline bool check(int x) {
  bool ok = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] >= x) bs[i][j] = 1;
    }
  }
  for (int i = 1; i <= n && !ok; ++i) {
    for (int j = 1; j < i && !ok; ++j) {
      if ((bs[i] & bs[j]).count() > 1) {
        ok = true;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] >= x) bs[i][j] = 0;
    }
  }
  return ok;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vector<int> g, p;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      g.push_back(a[i][j]);
    }
  }
  sort(g.begin(), g.end());
  for (int i = 0; i < g.size(); ++i) {
    if (!i || g[i] != g[i - 1]) p.push_back(g[i]);
  }
  int l = 0, r = p.size(), ans = 0;
  while (r >= l) {
    int m = l + r >> 1;
    if (check(p[m])) {
      ans = p[m];
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cout << ans << '\n';
}
