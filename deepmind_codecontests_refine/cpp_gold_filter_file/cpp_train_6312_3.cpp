#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return x * f;
}
const long long mod = 1e9 + 7;
long long x, y, ans, tmp;
long long cnt, fac[114514];
long long qpow(long long n, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = res * n % mod;
    n = n * n % mod, k >>= 1;
  }
  return res;
}
void dfs(long long u, long long stp, long long now) {
  if (u == cnt + 1) {
    if (stp)
      (ans += qpow(2, now - 1)) %= mod;
    else
      (ans -= qpow(2, now - 1)) %= mod;
    return;
  }
  dfs(u + 1, stp ^ 1, now / fac[u]);
  dfs(u + 1, stp, now);
}
signed main() {
  cin >> x >> y;
  if (y % x) return cout << 0, 0;
  y /= x, tmp = y;
  for (long long i = 2; i * i <= tmp; ++i) {
    if (tmp % i) continue;
    ++cnt, fac[cnt] = i;
    while (tmp % i == 0) tmp /= i;
  }
  if (tmp > 1) fac[++cnt] = tmp;
  dfs(1, 1, y);
  cout << (ans + mod) % mod << endl;
  return 0;
}
