#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 3;
const int MAX = 300 + 10;
int n, m, s, e, d[N][MAX], a[N], b[N], ans;
vector<int> ind[N];
int main() {
  cin >> n >> m >> s >> e;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    ind[b[i]].push_back(i);
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < MAX; ++j) d[i][j] = INF;
  int help, help1;
  for (int i = 0; i < n; ++i) {
    d[i][0] = 0;
    for (int j = 1; j < min(MAX, i + 1); ++j) {
      help1 = 0;
      if (i) d[i][j] = d[i - 1][j];
      if (ind[a[i]].size() == 0) continue;
      if (i) help1 = d[i - 1][j - 1];
      help = lower_bound(ind[a[i]].begin(), ind[a[i]].end(), help1) -
             ind[a[i]].begin();
      if (help == ind[a[i]].size()) continue;
      d[i][j] = min(d[i][j], ind[a[i]][help] + 1);
      if ((j * e + (d[i][j] + 1 + i)) <= s) ans = max(ans, j);
    }
  }
  cout << ans;
}
