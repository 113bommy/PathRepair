#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int n, k, x, y;
int ok[maxn], size[maxn], f[maxn], a[maxn];
bool up[maxn], ck;
vector<int> g[maxn];
void dfs(int x, int fa, int m) {
  ok[x] = a[x] >= m;
  size[x] = 1;
  for (int i = 0, v; i < (int)g[x].size(); i++)
    if ((v = g[x][i]) != fa) {
      dfs(v, x, m);
      size[x] += size[v];
      ok[x] += ok[v];
    }
}
void DFS(int x, int fa, int m) {
  int tt = 0, t1 = 0, t2 = 0;
  for (int i = 0, v; i < (int)g[x].size(); i++)
    if ((v = g[x][i]) != fa) {
      if (up[x] && ok[x] - ok[v] == size[x] - size[v]) up[v] = 1;
      DFS(v, x, m);
      if (a[x] < m) continue;
      if (size[v] == ok[v])
        tt += ok[v];
      else {
        if (f[v] > t1)
          t2 = t1, t1 = f[v];
        else if (f[v] > t2)
          t2 = f[v];
      }
    }
  if (a[x] < m) return;
  if (tt + t1 + t2 + up[x] * (n - size[x]) + 1 >= k) ck = 1;
  f[x] = tt + t1 + 1;
}
int check(int m) {
  memset(ok, 0, sizeof(ok));
  memset(up, 0, sizeof(up));
  memset(f, 0, sizeof(f));
  ck = 0;
  dfs(1, 0, m);
  up[1] = a[x] >= m;
  DFS(1, 0, m);
  return ck;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 2; i <= n; i++) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int l = 1, r = 1000001;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (check(m))
      l = m;
    else
      r = m;
  }
  cout << l;
  return 0;
}
