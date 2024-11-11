#include <bits/stdc++.h>
using namespace std;
char buf[1 << 20], *p1, *p2;
template <typename T>
inline void read(T &t) {
  register int v =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2)
           ? EOF
           : *p1++);
  T f = 1;
  t = 0;
  while (!isdigit(v)) {
    if (v == '-') f = -1;
    v = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  while (isdigit(v)) {
    t = t * 10 + v - 48;
    v = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  t *= f;
}
template <typename T, typename... Args>
inline void read(T &t, Args &...args) {
  read(t);
  read(args...);
}
const int N = 1e5 + 10;
vector<int> G[N];
int n, siz[N], wei[N], cent[2], p, fa[N];
void dfs(int x, int f) {
  siz[x] = 1, wei[x] = 0, fa[x] = f;
  for (int i = 0; i < G[x].size(); ++i) {
    int y = G[x][i];
    if (y != f) {
      dfs(y, x);
      siz[x] += siz[y];
      wei[x] = max(wei[x], siz[y]);
    }
  }
  wei[x] = max(wei[x], n - siz[x]);
  if (wei[x] <= n / 2) {
    if (cent[0])
      cent[1] = x;
    else
      cent[0] = x;
  }
}
void dfs1(int x, int f) {
  if (G[x].size() == 1) {
    p = x;
    return;
  }
  for (int i = 0; i < G[x].size(); ++i) {
    int y = G[x][i];
    if (y != f) {
      dfs1(y, x);
    }
  }
}
void solve() {
  read(n);
  memset(siz, 0, sizeof siz);
  memset(wei, 0, sizeof wei);
  cent[0] = cent[1] = 0;
  for (int i = 1; i <= n; ++i) G[i].clear(), fa[i] = 0;
  for (int i = 1; i < n; ++i) {
    int x, y;
    read(x, y);
    G[x].push_back(y), G[y].push_back(x);
  }
  dfs(1, 0);
  if (!cent[1]) {
    printf("1 %d\n1 %d\n", G[1][0], G[1][0]);
    return;
  }
  if (fa[cent[1]] != cent[0]) swap(cent[0], cent[1]);
  dfs1(cent[1], cent[0]);
  printf("%d %d\n%d %d\n", p, fa[p], p, cent[0]);
}
signed main() {
  int T;
  read(T);
  while (T--) solve();
  return 0;
}
