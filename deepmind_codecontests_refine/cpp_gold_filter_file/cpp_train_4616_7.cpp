#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool f = 0;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = 1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return f ? -x : x;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writeln(long long x) {
  write(x);
  puts("");
}
void writep(long long x) {
  write(x);
  putchar(' ');
}
long long const N = 30 + 3;
long long n, V, ans, ansA, ansB, ansC, S, A, B, C, num[N], power[N][N];
void dfs2(long long x, long long b, long long a) {
  if (1.0 * b * b > V / a) return;
  if (x > n) {
    B = max(B, b);
    return;
  }
  for (long long i = num[x]; ~i; i--) dfs2(x + 1, b * power[x][i], a);
}
void dfs1(long long x, long long a) {
  if (1.0 * a * a * a > V) return;
  if (x > n) {
    if ((4 * a * sqrt(V / a) + 2 * (V / a)) >= ans) return;
    B = 0, A = a;
    dfs2(1, 1, a);
    C = V / A / B;
    S = (A * B + A * C + B * C) << 1;
    if (S < ans) {
      ans = S;
      ansA = A;
      ansB = B;
      ansC = C;
    }
    return;
  }
  for (long long i = num[x]; ~i; i--) {
    num[x] -= i;
    dfs1(x + 1, a * power[x][i]);
    num[x] += i;
  }
}
signed main() {
  for (long long t = read(); t; t--) {
    V = 1;
    n = read();
    for (long long i = 1; i <= n; i++) {
      long long x = read();
      num[i] = read();
      power[i][0] = 1;
      for (long long j = 1; j <= num[i]; j++) power[i][j] = power[i][j - 1] * x;
      V *= power[i][num[i]];
    }
    ans = 5e18;
    dfs1(1, 1);
    writep(ans);
    writep(ansA);
    writep(ansB);
    writeln(ansC);
  }
  return 0;
}
