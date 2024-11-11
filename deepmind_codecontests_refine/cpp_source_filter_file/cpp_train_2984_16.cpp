#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int a[MAXN + 1], t[MAXN + 1], cnt[MAXN + 1], used[MAXN], res[MAXN + 1];
vector<vector<int> > g(MAXN);
int dfs(int v) {
  used[v] = 1;
  int res = 0;
  for (size_t i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (used[to]) continue;
    res = res + dfs(to);
  }
  return res + 1;
}
int main() {
  int n, m, u, v, k = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    a[dfs(i)]++;
  }
  for (int i = 1, x; i <= n; i++) {
    if (!a[i]) continue;
    x = a[i];
    for (int j = 0; (1 << j) <= x; x -= (1 << j), j++) {
      t[k] = (1 << j) * i;
      cnt[k] = (1 << j);
      k++;
    }
    if (x) {
      t[k] = x * i;
      cnt[k] = x;
      k++;
    }
  }
  for (int i = 0; i < k; i++)
    for (int j = n - t[i]; j >= 0; j--) {
      if (j && !res[j]) continue;
      res[j + t[i]] =
          res[j + t[i]] ? min(res[j + t[i]], res[j] + cnt[i]) : res[j] + cnt[i];
    }
  int best = n + 1;
  for (int i = 1, x; i <= n; i++) {
    for (x = i; x > 0; x /= 10)
      if (x % 10 != 4 && x % 10 != 7) break;
    if (x % 10 || !res[i]) continue;
    best = min(best, res[i]);
  }
  if (best == n + 1)
    cout << -1;
  else
    cout << best - 1;
  return 0;
}
