#include <bits/stdc++.h>
using namespace std;
int n, m, s, t, x[2000005], y[2000005], fa[2000005], fl[2000005], dep[2000005],
    rd[2000005], cd[2000005], f[2000005], son[2000005], d[2000005];
int fst[2000005], to[2000005], nxt[2000005], l = 1;
vector<int> v[2000005];
void link(int x, int y) {
  to[++l] = y;
  nxt[l] = fst[x];
  fst[x] = l;
  to[++l] = x;
  nxt[l] = fst[y];
  fst[y] = l;
}
void dfs(int x) {
  dep[x] = dep[fa[x]] + 1;
  for (int i = fst[x]; i; i = nxt[i])
    if (to[i] != fa[x]) {
      if (!dep[to[i]]) {
        fa[to[i]] = x;
        f[to[i]] = i / 2;
        son[x] = to[i];
        dfs(to[i]);
      } else if (dep[to[i]] < dep[x])
        v[son[to[i]]].push_back(i);
    }
}
pair<int, int> q[2000005];
void work() {
  scanf("%d%d%d%d", &n, &m, &s, &t);
  for (int i = 1; i <= n; i++)
    fst[i] = fa[i] = fl[i] = cd[i] = rd[i] = dep[i] = 0, v[i].clear();
  l = 1;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x[i], &y[i]);
    d[i] = -1;
    link(x[i], y[i]);
  }
  dfs(s);
  int l = 0, r = 1;
  q[1] = make_pair(t, 0);
  while (l < r) {
    int i = q[++l].first, dr = q[l].second;
    for (; fa[i] && d[f[i]] == -1; i = fa[i]) {
      d[f[i]] = dr;
      for (int j : v[i]) {
        d[j / 2] = dr;
        q[++r] = make_pair(to[j ^ 1], dr ^ 1);
      }
    }
  }
  for (int i = 1; i <= m; i++)
    if (d[i] == -1) {
      puts("No");
      return;
    }
  puts("Yes");
  for (int i = 1; i <= m; i++) {
    if (dep[x[i]] < dep[y[i]] ^ d[i])
      printf("%d %d\n", x[i], y[i]);
    else
      printf("%d %d\n", y[i], x[i]);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) work();
}
