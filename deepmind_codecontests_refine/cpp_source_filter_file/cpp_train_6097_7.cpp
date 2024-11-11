#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 - '0' + c, c = getchar();
  x *= f;
}
template <class T>
inline void wrt(T x) {
  if (x < 0) {
    putchar('-'), wrt(-x);
    return;
  }
  if (x >= 10) wrt(x / 10);
  putchar(x % 10 + '0');
}
const int N = 2e5 + 10;
struct EI {
  int v, to, id;
};
vector<EI> G[N];
struct ed {
  int x, y, w, c, t, id;
} e[N];
struct itm {
  int id, v;
  friend bool operator<(itm a, itm b) { return a.v < b.v; }
} mx[N][19];
int p[N][19], fa[N], dep[N], n, m;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
bool cmp(ed a, ed b) { return a.w < b.w; }
void dfs(int u, int last) {
  p[u][0] = last, dep[u] = dep[last] + 1;
  for (int j = 1; j <= 18; j++)
    p[u][j] = p[p[u][j - 1]][j - 1],
    mx[u][j] = max(mx[u][j - 1], mx[p[u][j - 1]][j - 1]);
  int siz = G[u].size();
  for (int i = 0; i < siz; i++) {
    int v = G[u][i].to;
    if (v == last) continue;
    mx[v][0] = (itm){G[u][i].id, G[u][i].v};
    dfs(v, u);
  }
}
itm query(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  itm ans = (itm){0, 0};
  for (int j = 18; j >= 0; j--)
    if (dep[x] - (1 << j) >= dep[y]) ans = max(mx[x][j], ans), x = p[x][j];
  if (x == y) return ans;
  for (int j = 18; j >= 0; j--)
    if (p[x][j] != p[y][j])
      ans = max(ans, max(mx[x][j], mx[y][j])), x = p[x][j], y = p[y][j];
  return max(ans, max(mx[x][0], mx[y][0]));
}
int main() {
  read(n), read(m);
  for (int i = 1; i <= m; i++) read(e[i].w);
  for (int i = 1; i <= m; i++) read(e[i].c);
  for (int i = 1; i <= m; i++)
    read(e[i].x), read(e[i].y), e[i].t = 0, e[i].id = i;
  sort(e + 1, e + m + 1, cmp);
  for (int i = 1; i <= n; i++) fa[i] = i;
  long long tot = 0;
  for (int i = 1; i <= m; i++)
    if (find(e[i].x) != find(e[i].y)) {
      fa[find(e[i].x)] = find(e[i].y), e[i].t = 1, tot += e[i].w;
      G[e[i].x].push_back((EI){e[i].w, e[i].y, e[i].id}),
          G[e[i].y].push_back((EI){e[i].w, e[i].x, e[i].id});
    }
  dfs(1, 0);
  long long S, ans = tot;
  int ps1, ps2 = 0, wt = 0;
  read(S);
  for (int i = 1; i <= m; i++)
    if (e[i].t) {
      if (tot - S / e[i].c < ans)
        ans = tot - S / e[i].c, ps1 = e[i].id, ps2 = 0,
        wt = e[i].w - S / e[i].c;
    } else {
      itm tp = query(e[i].x, e[i].y);
      long long tmp = tot - tp.v + e[i].w - S / e[i].c;
      if (tmp < ans)
        ans = tmp, ps1 = e[i].id, ps2 = tp.id, wt = e[i].w - S / e[i].c;
    }
  wrt(ans), putchar('\n');
  wrt(ps1), putchar(' '), wrt(wt), putchar('\n');
  for (int i = 1; i <= m; i++)
    if (e[i].id != ps2 && e[i].id != ps1 && e[i].t)
      printf("%d %d\n", e[i].id, e[i].w);
  return 0;
}
