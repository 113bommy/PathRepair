#include <bits/stdc++.h>
using namespace std;
inline long long getint() {
  long long ssum = 0, ff = 1;
  char ch;
  for (ch = getchar(); !isdigit(ch) && ch != '-'; ch = getchar())
    ;
  if (ch == '-') ff = -1, ch = getchar();
  for (; isdigit(ch); ch = getchar()) ssum = ssum * 10 + ch - '0';
  return ssum * ff;
}
const long long M = 3e6 + 5, up = 3e6, mod = 1e9 + 7;
long long fac[M], inv[M], pri[M], cntp, vis[M], n, m;
inline long long ksm(long long x, long long mi) {
  long long res = 1;
  while (mi) {
    if (mi & 1) res = res * x % mod;
    x = x * x % mod;
    mi >>= 1;
  }
  return res;
}
void Build() {
  for (long long i = 2; i <= up; i++) {
    if (!vis[i]) pri[++cntp] = i;
    for (long long j = 1; j <= cntp && pri[j] * i <= up; j++) {
      vis[i * pri[j]] = 1;
      if (i % pri[j] == 0) break;
    }
  }
  fac[0] = 1;
  for (long long i = 1; i <= up; i++) fac[i] = fac[i - 1] * i % mod;
  inv[up] = ksm(fac[up], mod - 2);
  for (long long i = up - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
inline long long C(long long x, long long y) {
  return fac[x] * inv[y] % mod * inv[x - y] % mod;
}
signed main() {
  Build();
  long long T;
  cin >> T;
  while (T--) {
    n = getint();
    m = getint();
    long long ans = 1, nn = n;
    for (long long i = 1; pri[i] * pri[i] <= nn; i++) {
      long long cnt = 0;
      while (n % pri[i] == 0) {
        cnt++;
        n /= pri[i];
      }
      ans = ans * C(cnt + m - 1, m - 1) % mod;
      if (n == 1) break;
    }
    if (n != 1) ans = ans * C(1 + m - 1, m - 1) % mod;
    ans = ans * ksm(2, m - 1) % mod;
    cout << ans << "\n";
  }
  return 0;
}
