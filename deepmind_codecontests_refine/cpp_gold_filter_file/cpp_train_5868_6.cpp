#include <bits/stdc++.h>
using namespace std;
int n, m, v[1000005];
long long ans;
inline int read() {
  int ret = 0;
  char c = getchar();
  while ((c < '0') || (c > '9')) c = getchar();
  while ((c >= '0') && (c <= '9'))
    ret = (ret << 1) + (ret << 3) + c - '0', c = getchar();
  return ret;
}
int main() {
  n = read();
  m = read();
  ans = 1LL * n * (n - 1) * (n - 2) / 6;
  for (int i = 1; i <= m; i++) v[read()]++, v[read()]++;
  ans -= 1LL * m * (n - 2);
  for (int i = 1; i <= n; i++) ans += 1LL * v[i] * (v[i] - 1) / 2;
  printf("%I64d", ans);
}
