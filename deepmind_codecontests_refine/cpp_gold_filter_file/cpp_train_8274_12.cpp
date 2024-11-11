#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f == 1 ? x : -x;
}
int mod;
inline int fix(int x) { return x + ((x >> 31) & mod); }
inline int add(int x, int y) { return fix(x + y - mod); }
inline int dec(int x, int y) { return fix(x - y); }
inline int mul(int x, int y) { return (long long)x * y % mod; }
inline void ADD(int &x, int y) { x = fix(x + y - mod); }
inline void DEC(int &x, int y) { x = fix(x - y); }
inline void MUL(int &x, int y) { x = (long long)x * y % mod; }
inline int ksm(int x, int r) {
  int ret = 1;
  for (int i = 0; (1ll << i) <= r; i++) {
    if ((r >> i) & 1) MUL(ret, x);
    MUL(x, x);
  }
  return ret;
}
const int N = 404;
int n, m, tot[2], pos[N * N], a[2][N][N];
char s[N][N];
namespace dsu {
int fa[N * N];
inline void clear(int n) {
  for (int i = 1; i <= n; i++) fa[i] = i;
}
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) {
    puts("0");
    exit(0);
  }
  fa[u] = v;
}
}  // namespace dsu
inline int id(int x, int y) { return x * (m + 1) + y + 1; }
inline void addedge(int r, int u, int v) {
  u = pos[u];
  v = pos[v];
  DEC(a[r][u][v], 1);
  DEC(a[r][v][u], 1);
  ADD(a[r][u][u], 1);
  ADD(a[r][v][v], 1);
}
inline int gauss(int r, int n) {
  int ret = 1, x, fl = 1;
  for (int i = 1; i <= n; i++) {
    if (!a[r][i][i])
      for (int j = i + 1; j <= n; j++)
        if (a[r][j][i]) {
          swap(a[r][i], a[r][j]);
          fl = mod - fl;
          break;
        }
    MUL(ret, a[r][i][i]);
    for (int j = i + 1; j <= n; j++) {
      x = mul(a[r][j][i], ksm(a[r][i][i], mod - 2));
      for (int k = i; k <= n; k++) DEC(a[r][j][k], mul(a[r][i][k], x));
    }
  }
  return mul(ret, fl);
}
int main() {
  n = read();
  m = read();
  mod = read();
  dsu::clear((n + 1) * (m + 1));
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for (int j = 1; j <= m; j++)
      if (s[i][j] != '*') {
        if (s[i][j] == '/')
          dsu::merge(id(i - 1, j), id(i, j - 1));
        else
          dsu::merge(id(i - 1, j - 1), id(i, j));
      }
  }
  for (int i = 0, r; i <= n; i++)
    for (int j = 0; j <= m; j++)
      if (dsu::find(id(i, j)) == id(i, j)) {
        r = (i + j) & 1;
        pos[id(i, j)] = ++tot[r];
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '*') {
        addedge((i + j + 1) & 1, dsu::find(id(i - 1, j)),
                dsu::find(id(i, j - 1)));
        addedge((i + j) & 1, dsu::find(id(i - 1, j - 1)), dsu::find(id(i, j)));
      }
  cout << add(gauss(0, tot[0] - 1), gauss(1, tot[1] - 1)) << "\n";
  return (0 - 0);
}
