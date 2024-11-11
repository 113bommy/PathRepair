#include <bits/stdc++.h>
using namespace std;
const int N = 40, C = 20;
int n, k, dp[1 << C];
long long adj[N];
inline int read() {
  int s = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') s = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return s * x;
}
int maxc() {
  for (int i = 0; i < n; i++) {
    for (int j = 0, x; j < n; j++) {
      x = read(), adj[i] |= (long long)(x || i == j) << j;
    }
  }
  for (int i = 1; i < (1 << max(0, n - C)); i++) {
    int x = i;
    for (int j = 0; j < C; j++) {
      if ((i >> j) & 1) x &= adj[j + C] >> C;
    }
    if (x == i) dp[i] = __builtin_popcount(i);
  }
  for (int i = 1; i < (1 << max(0, n - C)); i++) {
    for (int j = 0; j < C; j++) {
      if ((i >> j) & 1) dp[i] = max(dp[i], dp[i ^ (1 << j)]);
    }
  }
  int ret = 0;
  for (int i = 0; i < (1 << min(C, n)); i++) {
    int x = i, y = (1 << max(0, n - C)) - 1;
    for (int j = 0; j < min(C, n); j++) {
      if ((i >> j) & 1) x &= adj[j] & ((1 << C) - 1), y &= adj[j] >> C;
    }
    if (x != i) continue;
    ret = max(ret, __builtin_popcount(i) + dp[y]);
  }
  return ret;
}
int main() {
  n = read(), k = read();
  int c = maxc();
  long double x = (long double)k / c;
  return 0 * printf("%.8lf\n", x * x * c * (c - 1) / 2);
}
