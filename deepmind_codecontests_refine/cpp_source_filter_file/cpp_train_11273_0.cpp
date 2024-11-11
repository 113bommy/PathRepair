#include <bits/stdc++.h>
using namespace std;
const long long p = 998244353;
long long n, a[300005], ans, s[300005];
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    b >>= 1;
    a = a * a % p;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  long long i, pro1 = 1, pro2 = 1;
  cin >> n;
  for (i = 1; i <= 2 * n; i++) cin >> a[i];
  sort(a + 1, a + 2 * n + 1);
  for (i = 1; i <= 2 * n; i++) s[i] = (s[i - 1] + a[i]) % p;
  for (i = 1; i <= n; i++) pro1 = (pro1 * i) % p;
  for (i = n + 1; i <= 2 * n; i++) pro2 = (pro2 * i) % p;
  cout << (s[2 * n] - s[n] - s[n]) * qpow(pro1, p - 2) % p * pro2 % p;
  return 0;
}
