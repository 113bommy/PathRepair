#include <bits/stdc++.h>
using namespace std;
const long long int N = 100007;
vector<vector<pair<long long int, long long int> > > g(N);
long long int num[N], down[N], up[N];
long long int lucky(long long int n) {
  while (n) {
    long long int x = n % 10;
    if ((x != 4) && (x != 7)) return 0;
    n /= 10;
  }
  return 1;
}
void dfs(long long int idx, long long int push = -1, long long int w = 0) {
  num[idx] = 1;
  for (auto it : g[idx])
    if (it.first != push) {
      dfs(it.first, idx, it.second);
      num[idx] += num[it.first];
      if (it.second == 1)
        down[idx] += num[it.first];
      else
        down[idx] += down[it.first];
    }
}
void dfs2(long long int n, long long int idx, long long int push = -1,
          long long int w = 0) {
  if (push != -1) {
    if (w == 1)
      up[idx] = n - num[idx];
    else
      up[idx] = down[push] - down[idx] + up[push];
  }
  for (auto it : g[idx])
    if (it.first != push) dfs2(n, it.first, idx, it.second);
}
long long int compute(long long int a, long long int b) {
  return (a * (a - 1)) + (b * (b - 1)) + 2 * a * b;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, i, j, u, v, w, ans = 0;
  cin >> n;
  for (i = 0; i < n - 1; i++) {
    cin >> u >> v >> w;
    w = lucky(w);
    g[u].push_back({v, w}), g[v].push_back({u, w});
  }
  dfs(1);
  dfs2(n, 1);
  for (i = 1; i <= n; i++) ans += compute(down[i], up[i]);
  cout << ans << '\n';
  return 0;
}
