#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long fpow(long long b, long long x) {
  long long res = 1;
  while (x) {
    if (x & 1) res = (res * b) % MOD;
    b = (b * b) % MOD;
    x >>= 1;
  }
  return res;
}
long long c(long long k, long long r) {
  if (r < 0) return 0;
  if (r == 0) return 1;
  return c(k, r - 1) * (k - r + 1) % MOD * fpow(r, MOD - 2) % MOD;
}
int main() {
  long long n, m, g;
  cin >> n >> m >> g;
  if (m == 1) {
    if (m & 1) {
      if (g)
        cout << (m - 1) / 2 << endl;
      else
        cout << (m - 1) / 2 + 2 << endl;
    } else {
      if (g)
        cout << m / 2 + 2 << endl;
      else
        cout << m / 2 << endl;
    }
    return 0;
  }
  if (m == 0) {
    if (g == !(m & 1))
      printf("1\n");
    else
      printf("0\n");
    return 0;
  }
  if (n == 0) {
    if (g)
      printf("0\n");
    else
      printf("1\n");
    return 0;
  }
  long long k = 1 + g;
  long long C = c(n + m - k, m - 1);
  long long ans = C;
  for (k = k + 2; k <= n + 1; k += 2) {
    C = C * (n - k + 2) % MOD * (n - k + 3) % MOD *
        fpow(n + m - k + 2, MOD - 2) % MOD * fpow(n + m - k + 1, MOD - 2) % MOD;
    ans = (ans + C) % MOD;
  }
  cout << ans << endl;
  return 0;
}
