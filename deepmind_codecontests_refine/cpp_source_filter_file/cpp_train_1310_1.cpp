#include <bits/stdc++.h>
using namespace std;
int64_t ans;
int n, m, ve, ts[1000001], nn[1000001], t, cut[1000001], p[1000001],
    vis[1000001], low[1000001];
vector<int> e[1000001];
void dfs(int i) {
  low[i] = ts[i] = ++t;
  vis[i] = 1;
  for (auto&& x : e[i])
    if (!vis[x]) {
      p[x] = i;
      dfs(x);
      low[i] = min(low[i], low[x]);
      if (low[x] > ts[i]) cut[x] = 1;
    } else if (x != p[i])
      low[i] = min(low[i], low[x]);
}
int main() {
  scanf("%d%d", &n, &m);
  if (m < 2) return puts("0"), 0;
  for (int _ = 0; _ < m; ++_) {
    int s, t;
    scanf("%d%d", &s, &t);
    if (s == t)
      ++nn[s];
    else
      e[s].push_back(t), e[t].push_back(s);
  }
  for (int i = 1; i <= n; ++i)
    if (e[i].size()) {
      dfs(i);
      break;
    }
  for (int i = 1; i <= n; ++i)
    if ((nn[i] || e[i].size()) && !vis[i]) return puts("0"), 0;
  int64_t slc = accumulate(nn, nn + n + 1, 0);
  ans = slc * (slc - 1);
  for (int i = 1; i <= n; ++i) {
    int no = nn[i];
    nn[i] = 0;
    nn[i] = e[i].size();
    ans += nn[i] * (nn[i] - 1);
    ans += slc * nn[i];
  }
  cout << ans / 2;
}
