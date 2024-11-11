#include <bits/stdc++.h>
using namespace std;
long long ans, c0, c1;
int n, md, ret, d[100010], a[100010], f[100010], c[10000010];
vector<int> e[100010];
void dfs(int u, int dep) {
  d[u] = dep, md = max(md, dep);
  for (int i = 0; i < (e[u].size() - 1 + 1); i++) dfs(e[u][i], dep + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < (n + 1); i++) cin >> a[i];
  for (int i = 2; i < (n + 1); i++) cin >> f[i], e[f[i]].push_back(i);
  dfs(1, 1);
  for (int i = 1; i < (n + 1); i++) {
    if ((md - d[i]) & 1)
      c1++;
    else
      c0++, c[a[i]]++, ret ^= a[i];
  }
  if (ret) {
    for (int i = 1; i < (n + 1); i++)
      if (((md - d[i]) & 1) && (ret ^ a[i]) <= 10000000) ans += c[ret ^ a[i]];
  } else {
    ans = c0 * (c0 - 1) + c1 * (c1 - 1), ans >>= 1;
    for (int i = 1; i < (n + 1); i++)
      if ((md - d[i]) & 1) ans += c[a[i]];
  }
  cout << ans;
  return 0;
}
