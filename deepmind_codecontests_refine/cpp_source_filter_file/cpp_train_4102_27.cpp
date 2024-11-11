#include <bits/stdc++.h>
inline int Get() {
  char ch;
  while ((ch = getchar()) < '0' || ch > '9')
    ;
  int Num = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9')
    Num = (Num << 3) + (Num << 1) + ch - '0';
  return Num;
}
const int N = 1e6 + 6;
const int mod = 1e9 + 7;
int n, m, g[N], ans;
int main() {
  n = Get();
  for (int i = 1; i <= n; ++i) m += (Get() == 2);
  n -= m, g[0] = 1, g[1] = 1;
  for (int i = 2; i <= n; ++i)
    g[i] = ((long long)(i - 1) * g[i - 2] + g[i - 1]) % mod;
  ans = g[n];
  for (int i = 0; i < m; ++i) ans = (long long)ans * (n + 1 + i) % mod;
  printf("%I64d\n", ans);
  return 0;
}
