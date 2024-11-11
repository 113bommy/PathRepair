#include <bits/stdc++.h>
using namespace std;
int vv[12010], nxt[12010], h[6010], e;
vector<int> vec;
void add(int u, int v) {
  vv[e] = v, nxt[e] = h[u], h[u] = e++;
  vv[e] = u, nxt[e] = h[v], h[v] = e++;
}
int a[6010], dp[6010][6010];
int ans;
void dfs(int u, int f) {
  int pos = lower_bound(vec.begin(), vec.end(), a[u]) - vec.begin();
  int tmp = -1;
  if (pos == vec.size())
    vec.push_back(a[u]);
  else
    tmp = vec[pos], vec[pos] = a[u];
  ans = max(ans, (int)vec.size());
  for (int i = h[u]; i + 1; i = nxt[i]) {
    int v = vv[i];
    if (v == f) continue;
    dfs(v, u);
  }
  if (tmp == -1)
    vec.pop_back();
  else
    vec[pos] = tmp;
}
int main() {
  int n, u, v;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  memset(h, -1, sizeof(h)), e = 0;
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &u, &v);
    add(u, v);
  }
  for (int i = 1; i <= n; ++i) dfs(1, 0);
  printf("%d\n", ans);
}
