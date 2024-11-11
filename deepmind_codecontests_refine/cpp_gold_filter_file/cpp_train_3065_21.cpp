#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int a[maxN], b[maxN], n, m, s, e;
int d[maxN][300 + 10];
vector<int> pos[maxN];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> s >> e;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    pos[b[i]].push_back(i);
  }
  for (int i = 0; i < maxN; i++)
    for (int j = 0; j < 310; j++) d[i][j] = INT_MAX;
  int res = 0;
  for (int i = 0; i < n; i++) {
    d[i][0] = 0;
    for (int j = 1; j <= min(i + 1, 300); j++) {
      if (i > 0)
        d[i][j] = d[i - 1][j];
      else
        d[i][j] = INT_MAX;
      int x;
      if (i > 0)
        x = d[i - 1][j - 1];
      else
        x = 0;
      if (pos[a[i]].size() == 0) continue;
      int idx = lower_bound(pos[a[i]].begin(), pos[a[i]].end(), x) -
                pos[a[i]].begin();
      if (idx == pos[a[i]].size()) continue;
      int ind = pos[a[i]][idx] + 1;
      d[i][j] = min(d[i][j], ind);
      if (j * e + (i + 1 + d[i][j]) <= s) res = max(res, j);
    }
  }
  cout << res << endl;
  return 0;
}
