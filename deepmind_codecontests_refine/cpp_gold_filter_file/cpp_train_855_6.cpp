#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long power(long long a, long long n) {
  long long ret = 1;
  while (n) {
    if (n & 1) {
      ret = ret * a % mod;
    }
    a = a * a % mod;
    n >>= 1;
  }
  return ret;
}
vector<long long> st;
long long C(long long n, long long k) {
  long long ret = st[n];
  ret = ret * power(st[k], mod - 2) % mod;
  ret = ret * power(st[n - k], mod - 2) % mod;
  return ret;
}
long long solve(long long n, long long k) {
  if (k >= n) return 0;
  st.resize(n + 1, 1);
  for (long long i = 1; i <= n; i++) st[i] = st[i - 1] * i % mod;
  long long ret = 0, c = n - k;
  for (long long i = 0; i <= c; i++) {
    if ((i & 1) == (c & 1))
      ret = (ret + mod + (C(c, i) * power(i, n))) % mod;
    else
      ret = (ret + mod - (C(c, i) * power(i, n))) % mod;
  }
  ret = ret * C(n, c) % mod;
  return k > 0 ? ret * 2 % mod : ret;
}
int32_t main() {
  long long n, k;
  cin >> n >> k;
  cout << solve(n, k);
  return 0;
}
