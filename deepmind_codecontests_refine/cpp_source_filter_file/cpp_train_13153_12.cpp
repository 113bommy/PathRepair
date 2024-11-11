#include <bits/stdc++.h>
using namespace std;
const int N = 505;
vector<pair<int, int>> v[N];
int n1, n2, m, kk, clr[N], deg[N], cur[N], idx;
void dfs(int pos, int c1, int c2) {
  clr[v[pos][c1].second] = c2;
  swap(v[pos][c1], v[pos][c2]);
  if (v[pos][c2].first) dfs(v[pos][c2].first, c2, c1);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n1 >> n2 >> m >> kk;
  for (int i = 1; i <= m; i++) {
    int t1, t2;
    cin >> t1 >> t2;
    t2 += n1;
    if (deg[t1] % kk == 0) v[cur[t1] = ++idx].resize(kk);
    ++deg[t1];
    t1 = cur[t1];
    if (deg[t2] % kk == 0) v[cur[t2] = ++idx].resize(kk);
    ++deg[t2];
    t2 = cur[t2];
    int c1 = -1;
    for (int i = 0; i < kk; i++)
      if (!v[t1][i].first) c1 = i;
    if (v[t2][c1].first) {
      int c2 = -1;
      for (int i = 0; i < kk; i++)
        if (!v[t2][i].first) c2 = i;
      dfs(t2, c1, c2);
    }
    v[t1][c1] = {t2, i};
    v[t2][c1] = {t1, i};
    clr[i] = c1;
  }
  int ans = 0;
  for (int i = 1; i <= n1 + n2; i++) ans += !!(deg[i] % kk);
  cout << ans << endl;
  for (int i = 1; i <= m; i++) cout << clr[i] + 1 << ' ';
  return 0;
}
