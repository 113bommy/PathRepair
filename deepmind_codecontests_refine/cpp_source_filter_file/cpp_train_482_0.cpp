#include <bits/stdc++.h>
using namespace std;
template <class TH>
void _dbg(const char *sdbg, TH h) {
  if (0) cout << sdbg << "=" << h << "\n";
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',')
    if (0) cout << *sdbg++;
  if (0) cout << "=" << h << ",";
  _dbg(sdbg + 1, a...);
}
const int MX = 1e6 + 7, LG = 20;
int depth[MX];
int skok[MX][LG];
vector<int> G[MX];
bool tak[MX];
void predfs(int u, int p) {
  for (int v : G[u]) {
    if (v != p) {
      skok[v][0] = u;
      depth[v] = depth[u] + 1;
      predfs(v, u);
    }
  }
}
vector<int> ans;
int32_t main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  predfs(n, 0);
  for (int i = 1; i < LG; ++i)
    for (int j = 1; j <= n; ++j) skok[i][j] = skok[skok[j][i - 1]][i - 1];
  tak[n] = 1;
  tak[0] = 1;
  int zostaw = 1;
  for (int i = n - 1; i >= 1; --i) {
    if (!tak[i]) {
      int pom = i;
      for (int j = 19; j >= 0; --j)
        if (!tak[skok[pom][j]]) pom = skok[pom][j];
      pom = skok[pom][0];
      int dod = depth[i] - depth[pom];
      if (zostaw + dod <= n - k) {
        int t = i;
        while (t != pom) tak[t] = 1, t = skok[t][0];
        zostaw += dod;
      } else
        ans.push_back(i);
    }
  }
  sort(ans.begin(), ans.end());
  for (int x : ans) printf("%d ", x);
}
