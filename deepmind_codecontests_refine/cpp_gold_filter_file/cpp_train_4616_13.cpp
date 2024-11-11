#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC target("avx,avx2")
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t, class... A>
inline void read(t &x, A &...a) {
  read(x);
  read(a...);
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
long long A, B, C, S, ansA, ansB, ansC, ansS, pw[505][505], V, n, v[10005];
void dfs2(long long x, long long b, long long a) {
  if (1.0 * b * b > V / a) return;
  if (x > n) {
    B = max(B, b);
    return;
  }
  for (long long i = v[x]; ~i; i--) dfs2(x + 1, b * pw[x][i], a);
}
void dfs1(long long x, long long a) {
  if (1.0 * a * a * a > V) return;
  if (x > n) {
    long long bc = V / a, lim = 4 * a * sqrt(bc) + 2 * bc;
    if (lim >= ansS) return;
    B = 0;
    A = a;
    dfs2(1, 1, A);
    C = V / A / B;
    S = (A * B + B * C + A * C) << 1;
    if (S < ansS) {
      ansS = S;
      ansA = A;
      ansB = B;
      ansC = C;
    }
    return;
  }
  for (long long i = v[x]; ~i; i--) {
    v[x] -= i;
    dfs1(x + 1, a * pw[x][i]);
    v[x] += i;
  }
}
void doit() {
  read(n);
  V = 1;
  for (long long i = 1, x, y; i <= n; i++) {
    read(x, y);
    v[i] = y;
    pw[i][0] = 1;
    for (long long j = 1; j <= y; j++) pw[i][j] = pw[i][j - 1] * x;
    V *= pw[i][y];
  }
  ansS = 1ll << 62;
  dfs1(1, 1);
  write(ansS);
  putchar(' ');
  write(ansA);
  putchar(' ');
  write(ansB);
  putchar(' ');
  write(ansC);
  puts("");
}
signed main() {
  long long t;
  read(t);
  while (t--) doit();
}
