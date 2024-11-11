#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &res) {
  res = 0;
  T f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    res = res * 10 + c - '0';
    c = getchar();
  }
  res *= f;
}
template <class T>
void out(T x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x >= 10) {
    out(x / 10);
  }
  putchar('0' + x % 10);
}
const int MOD = 998244353;
int N, M;
int all, sa, sb, a[200005], w[200005];
int f[3005][3005], g[3005][3005];
int inv[6005];
int inc(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }
int mul(int a, int b) { return 1LL * a * b % MOD; }
void update(int &x, int y) { x = inc(x, y); }
int fpow(int x, int c) {
  int res = 1, t = x;
  while (c) {
    if (c & 1) res = mul(res, t);
    t = mul(t, t);
    c >>= 1;
  }
  return res;
}
void Solve() {
  read(N);
  read(M);
  for (int i = 1; i <= N; ++i) {
    read(a[i]);
  }
  for (int i = 1; i <= N; ++i) {
    read(w[i]);
    all += w[i];
    if (a[i])
      sa += w[i];
    else
      sb += w[i];
  }
  for (int i = -M; i <= M; ++i) {
    if (all + i > 0) {
      inv[i + 3000] = fpow(all + i, MOD - 2);
    }
  }
  for (int i = M; i >= 0; --i) {
    f[i][M - i] = g[i][M - i] = 1;
    for (int j = min(M - i - 1, sb); j >= 0; --j) {
      int iv = inv[i - j + 3000];
      f[i][j] = inc(mul(mul(sa + i + 1, iv), f[i + 1][j]),
                    mul(mul(sb - j, iv), f[i][j + 1]));
      g[i][j] = inc(mul(mul(sa + i, iv), g[i + 1][j]),
                    mul(mul(sb - j - 1, iv), g[i][j + 1]));
    }
  }
  for (int i = 1; i <= N; ++i) {
    if (a[i] == 1)
      out(mul(f[0][0], w[i]));
    else
      out(mul(g[0][0], w[i]));
    putchar('\n');
  }
}
int main() {
  Solve();
  return 0;
}
