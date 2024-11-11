#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int N = 510, M = 1e6 + 10;
int a[N][N], n, m, x1, _114514, x2, _1919810;
char tmp[N];
struct CatTree {
  bitset<N> f[11][N][N];
  int dep[N], id[N];
  void build(int k, int l, int r, int d) {
    dep[k] = d;
    int mid = l + r >> 1;
    for (int i = (1), iEND = (m); i <= iEND; i++)
      if (a[mid][i]) {
        f[d][mid][i][i] = 1;
        if (a[mid][i - 1]) f[d][mid][i] |= f[d][mid][i - 1];
      }
    for (int i = (mid + 1), iEND = (r); i <= iEND; i++)
      for (int j = (1), jEND = (m); j <= jEND; j++)
        if (a[i][j]) f[d][i][j] = f[d][i - 1][j] | f[d][i][j - 1];
    for (int i = (m), iEND = (1); i >= iEND; i--)
      if (a[mid][i]) {
        f[d][mid][i].reset();
        f[d][mid][i][i] = 1;
        if (a[mid][i + 1]) f[d][mid][i] |= f[d][mid][i + 1];
      }
    for (int i = (mid - 1), iEND = (l); i >= iEND; i--)
      for (int j = (m), jEND = (1); j >= jEND; j--)
        if (a[i][j]) f[d][i][j] = f[d][i + 1][j] | f[d][i][j + 1];
    if (l == r) return id[l] = k, void();
    build((k << 1), l, mid, d + 1), build((k << 1 | 1), mid + 1, r, d + 1);
  }
  bool query(int k1, int k2) {
    while (dep[k1] > dep[k2]) k1 >>= 1;
    while (dep[k2] > dep[k1]) k2 >>= 1;
    while (k1 ^ k2) k1 >>= 1, k2 >>= 1;
    return (f[dep[k1]][x1][_114514] & f[dep[k2]][x2][_1919810]).count();
  }
} T;
signed main() {
  n = read(), m = read();
  for (int i = (1), iEND = (n); i <= iEND; i++) {
    scanf("%s", tmp + 1);
    for (int j = (1), jEND = (m); j <= jEND; j++) a[i][j] = tmp[j] == '.';
  }
  T.build(1, 1, n, 0);
  int q = read();
  while (q--) {
    x1 = read(), _114514 = read(), x2 = read(), _1919810 = read();
    puts(T.query(T.id[x1], T.id[x2]) ? "Yes" : "No");
  }
  return 0;
}
