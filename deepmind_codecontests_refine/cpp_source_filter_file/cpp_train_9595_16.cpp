#include <bits/stdc++.h>
int read() {
  int ans = 0, c, f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') f *= -1;
  do ans = ans * 10 + c - '0';
  while (isdigit(c = getchar()));
  return ans * f;
}
const int N = 1050;
const int K = 1050;
const int mod = 998244353;
int n, A[N], f[N][K];
inline void add(int &x, int y) {
  if ((x += y) >= mod) x -= mod;
}
int main() {
  n = read();
  int k = read();
  for (int i = 1; i <= n; ++i) A[i] = read();
  A[0] = -10000000;
  std::sort(A, A + n + 1);
  int ans = 0;
  for (int u = 1; u * k <= 100000; ++u) {
    int j = 0;
    for (int i = 1; i <= n; ++i) {
      while (A[j + 1] + u <= A[i]) ++j;
      for (int t = 0; t <= k; ++t) {
        f[i][t] = f[i - 1][t];
        if (t) add(f[i][t], f[j][t - 1]);
      }
      if ((++f[i][1]) >= mod) f[i][1] -= mod;
    }
    add(ans, f[n][k]);
  }
  printf("%d\n", ans);
}
