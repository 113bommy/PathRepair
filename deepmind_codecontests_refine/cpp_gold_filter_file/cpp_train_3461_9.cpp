#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f;
const long long maxn = 501110;
const long long M = 998244353;
long long n, m, k, ok;
long long inv[maxn];
void init() {
  inv[1] = 1;
  for (long long i = 2; i < maxn; i++) {
    inv[i] = (M - M / i) * inv[M % i] % M;
  }
}
long long c(long long x, long long y) {
  if (y > x) return 0;
  long long res = 1;
  y = min(y, x - y);
  for (long long i = 1; i <= y; i++) {
    res = (res * (x - i + 1) % M * inv[i]) % M;
  }
  return res;
}
signed main() {
  init();
  cin >> n >> k;
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long res = n / i;
    res--;
    ans = (ans + c(res, k - 1)) % M;
  }
  cout << ans << endl;
  return 0;
}
