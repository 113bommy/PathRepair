#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, L = 22, inf = 1e9 + 10;
int n;
int p[N], c[N];
vector<int> e[N];
int bg[N], ed[N], ver[N], dep[N], sz[N], son[N], val[N], ans[N];
int mp[1 << L];
int id;
void dfs1(int v, int x, int d) {
  sz[v] = 1;
  son[v] = 0;
  bg[v] = ++id;
  val[v] = x;
  dep[v] = d;
  ver[bg[v]] = v;
  for (int u : e[v]) {
    dfs1(u, x ^ (1 << c[u]), d + 1);
    if (sz[u] > sz[son[v]]) son[v] = u;
    sz[v] += sz[u];
  }
  ed[v] = id;
}
void dfs(int v, int kp) {
  ans[v] = 0;
  for (int u : e[v])
    if (u != son[v]) {
      dfs(u, 0);
      ans[v] = max(ans[v], ans[u]);
    }
  if (son[v]) {
    dfs(son[v], 1);
    ans[v] = max(ans[v], ans[son[v]]);
  }
  ans[v] = max(ans[v], mp[val[v]] - dep[v]);
  for (int i = 0; i < L; ++i)
    ans[v] = max(ans[v], mp[val[v] ^ (1 << i)] - dep[v]);
  mp[val[v]] = max(mp[val[v]], dep[v]);
  for (int u : e[v])
    if (u != son[v]) {
      for (int i = bg[u]; i <= ed[u]; ++i) {
        int x = ver[i];
        int y = val[x];
        ans[v] = max(ans[v], mp[y] + dep[x] - dep[v] * 2);
        for (int z = 0; z < L; ++z) {
          ans[v] = max(ans[v], mp[y ^ (1 << z)] + dep[x] - dep[u] * 2);
        }
      }
      for (int i = bg[u]; i <= ed[u]; ++i) {
        int x = ver[i];
        mp[val[x]] = max(mp[val[x]], dep[x]);
      }
    }
  if (!kp) {
    for (int i = bg[v]; i <= ed[v]; ++i) {
      int x = ver[i];
      mp[val[x]] = -inf;
    }
  }
}
int main() {
  fill(mp, mp + (1 << L), -inf);
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    char s[10];
    scanf("%d%s", p + i, s);
    c[i] = s[0] - 'a';
    e[p[i]].push_back(i);
  }
  dfs1(1, 0, 0);
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
  return 0;
}
