#include <bits/stdc++.h>
using namespace std;
int n, m;
long long inv[2000005] = {0, 1}, ans;
const long long mod = 998244353;
inline int read() {
  int f = 1, w = 0;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    w = (w << 1) + (w << 3) + ch - '0', ch = getchar();
  return f * w;
}
int main() {
  for (int i = 2; i <= 2000000; i++)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  n = read(), m = read();
  for (int i = 1; i <= n; i++) (ans += inv[i]) %= mod;
  printf("%lld\n", (ans * m % mod + 1) * (n * inv[m + 1] % mod + 1) % mod);
  return 0;
}
