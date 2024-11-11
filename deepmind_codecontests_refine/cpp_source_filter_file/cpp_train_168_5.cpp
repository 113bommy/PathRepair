#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
int n, m, h;
int c[N];
vector<int> to[N];
int bz[N], vis[N], sta[N];
int fa[N], dfn[N], top[N], f[N], p[N], du[N];
int tot, cnt, ans;
void tj(int x) {
  dfn[x] = top[x] = ++tot;
  sta[++sta[0]] = x;
  int sz = to[x].size();
  for (int i = (0); i <= (sz - 1); ++i) {
    int tt = to[x][i];
    if (!dfn[tt]) tj(tt);
    top[x] = min(top[x], top[tt]);
  }
  if (dfn[x] == top[x]) {
    ++cnt;
    for (int now = sta[sta[0]--]; now != x; now = sta[sta[0]--])
      ++p[f[now] = cnt];
    ++p[f[x] = cnt];
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &h);
  for (int i = (1); i <= (n); ++i) scanf("%d", &c[i]);
  for (int i = (1); i <= (m); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (c[x] == (c[y] + 1) % h) to[y].push_back(x);
    if (c[y] == (c[x] + 1) % h) to[x].push_back(y);
  }
  ans = 0, p[0] = 2139062143;
  for (int i = (1); i <= (n); ++i)
    if (!dfn[i]) tj(i);
  for (int i = (1); i <= (n); ++i) {
    int sz = to[i].size();
    for (int l = (0); l <= (sz - 1); ++l)
      if (f[i] != f[to[i][l]]) ++du[to[i][l]];
  }
  for (int i = (1); i <= (cnt); ++i)
    if (du[i] == 0 && p[i] < p[ans]) ans = i;
  printf("%d\n", p[ans]);
  for (int i = (1); i <= (n); ++i)
    if (f[i] == ans) printf("%d ", i);
  return 0;
}
