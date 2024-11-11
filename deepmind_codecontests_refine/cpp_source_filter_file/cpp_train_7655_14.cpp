#include <bits/stdc++.h>
using namespace std;
long long int n, lv[200005], timer, l, tin[200005], tout[200005],
    up[200005][22];
vector<long long int> nb[200005];
void dfs(long long int st, long long int pr) {
  tin[st] = ++timer;
  up[st][0] = pr;
  for (long long int i = 1; i <= l; ++i) up[st][i] = up[up[st][i - 1]][i - 1];
  for (long long int i = 0; i <= nb[st].size() - 1; ++i) {
    if (nb[st][i] == pr) continue;
    lv[nb[st][i]] = lv[st] + 1;
    dfs(nb[st][i], st);
  }
  tout[st] = ++timer;
}
bool upper(long long int a, long long int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}
long long int lca(long long int a, long long int b) {
  if (upper(a, b)) return a;
  if (upper(b, a)) return b;
  for (long long int i = l; i >= 0; --i)
    if (!upper(up[a][i], b)) a = up[a][i];
  return up[a][0];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long int a;
  for (long long int i = 2; i <= n; ++i)
    cin >> a, nb[i].push_back(a), nb[a].push_back(i);
  l = 1;
  while ((1 << l) <= n) ++l;
  dfs(1, 1);
  cout << 1 << " ";
  long long int u = 1, v = 2, ans = 1;
  for (long long int i = 3; i <= n; ++i) {
    long long int lc1 = lca(u, i), lc2 = lca(v, i), tem = v;
    if (ans < lv[i] + lv[u] - 2 * lv[lc1]) {
      ans = lv[i] + lv[u] - 2 * lv[lc1];
      v = i;
    }
    if (ans < lv[i] + lv[v] - 2 * lv[lc2]) {
      ans = lv[i] + lv[v] - 2 * lv[lc2];
      u = i;
      v = tem;
    }
    cout << ans << " ";
  }
}
