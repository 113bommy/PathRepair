#include <bits/stdc++.h>
const int N = 1e5 + 10, inf = 0x3f3f3f3f;
inline void chk(int &a, int b) { a = std::min(a, b); }
char L[N], R[N];
struct SegmentTree {
  static const int N = 4e5 + 10;
  int m, f[N][4][2][2], c[N][2][2][2], tag[N];
  inline void write(int k, int l, int r) {
    printf("%d %d %d\n", k, l, r);
    for (int a = (0); a <= (1); ++a)
      for (int b = (0); b <= (1); ++b)
        printf("lc = %d, rc = %d, Min = %d\n", a, b, f[k][1][a][b]);
    puts("");
  }
  inline void New(int k, int a, int b) {
    f[k][0][0][0] = a + b, f[k][0][1][1] = (a ^ 1) + (b ^ 1);
    f[k][0][1][0] = f[k][0][0][1] = inf;
    f[k][1][0][0] = (a ^ 1) + b, f[k][1][1][1] = a + (b ^ 1);
    f[k][1][1][0] = f[k][1][0][1] = inf;
    f[k][2][0][0] = a + (b ^ 1), f[k][2][1][1] = (a ^ 1) + b;
    f[k][2][1][0] = f[k][2][0][1] = inf;
    f[k][3][0][0] = (a ^ 1) + (b ^ 1), f[k][3][1][1] = a + b;
    f[k][3][1][0] = f[k][3][0][1] = inf;
    c[k][0][0][a] = c[k][0][1][b] = c[k][1][0][a ^ 1] = c[k][1][1][b ^ 1] = 1;
    c[k][1][0][a] = c[k][1][1][b] = c[k][0][0][a ^ 1] = c[k][0][1][b ^ 1] = 0;
  }
  inline void upd(int k) {
    int u = k << 1, v = k << 1 | 1;
    for (int r = (0); r <= (1); ++r)
      for (int x = (0); x <= (1); ++x)
        for (int a = (0); a <= (1); ++a)
          c[k][r][x][a] = c[u][r][x][a] + c[v][r][x][a];
    memset(f[k], 0x3f, sizeof(f[k]));
    for (int r = (0); r <= (3); ++r)
      for (int a = (0); a <= (1); ++a)
        for (int b = (0); b <= (1); ++b)
          for (int x = (0); x <= (1); ++x)
            for (int y = (0); y <= (1); ++y)
              chk(f[k][r][a][b], f[u][r][a][x] + f[v][r][y][b] + (x != y) * m);
  }
  inline void build(int k, int l, int r) {
    if (l == r) return New(k, L[l] == 'R', R[l] == 'R');
    build(k << 1, l, ((l + r) >> 1)), build(k << 1 | 1, ((l + r) >> 1) + 1, r),
        upd(k);
  }
  inline void down(int k, int dat) {
    tag[k] ^= dat;
    if (dat & 1) {
      std::swap(c[k][0][0][0], c[k][1][0][0]);
      std::swap(c[k][0][0][1], c[k][1][0][1]);
      std::swap(f[k][0], f[k][1]), std::swap(f[k][2], f[k][3]);
    }
    if (dat & 2) {
      std::swap(c[k][0][1][0], c[k][1][1][0]);
      std::swap(c[k][0][1][1], c[k][1][1][1]);
      std::swap(f[k][0], f[k][2]), std::swap(f[k][1], f[k][3]);
    }
  }
  inline void down(int k) {
    if (tag[k]) {
      down(k << 1, tag[k]);
      down(k << 1 | 1, tag[k]);
      tag[k] = 0;
    }
  }
  inline void Mod(int k, int l, int r, int ql, int qr, int dat) {
    if (l > r || ql > r || l > qr) return;
    if (ql <= l && r <= qr) return down(k, dat);
    down(k);
    Mod(k << 1, l, ((l + r) >> 1), ql, qr, dat),
        Mod(k << 1 | 1, ((l + r) >> 1) + 1, r, ql, qr, dat), upd(k);
  }
} T1, T2;
inline void solve() {
  int res = inf;
  for (int a = (0); a <= (1); ++a)
    for (int b = (0); b <= (1); ++b) {
      chk(res, T1.f[1][0][a][b] + T2.c[1][0][0][a ^ 1] + T2.c[1][0][1][b ^ 1]);
      chk(res, T2.f[1][0][a][b] + T1.c[1][0][0][a ^ 1] + T1.c[1][0][1][b ^ 1]);
    }
  std::cout << res << std::endl;
}
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  int n, m, q;
  std::cin >> n >> m >> q;
  std::cin >> L + 1 >> R + 1;
  T1.m = m, T1.build(1, 1, n);
  std::cin >> L + 1 >> R + 1;
  T2.m = n, T2.build(1, 1, m);
  solve();
  for (int T = 1; T <= q; ++T) {
    char op;
    int l, r;
    std::cin >> op >> l >> r;
    if (op == 'L') T1.Mod(1, 1, n, l, r, 1);
    if (op == 'R') T1.Mod(1, 1, n, l, r, 2);
    if (op == 'U') T2.Mod(1, 1, m, l, r, 1);
    if (op == 'D') T2.Mod(1, 1, m, l, r, 2);
    solve();
  }
  return 0;
}
