#include <bits/stdc++.h>
using namespace std;
const int MX = 5e3 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
long long F[MX], invF[MX];
long long power(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ret;
}
void init() {
  F[0] = 1;
  for (int i = 1; i < MX; i++) {
    F[i] = (F[i - 1] * i) % mod;
  }
  invF[MX - 1] = power(F[MX - 1], mod - 2);
  for (int i = MX - 2; i >= 0; i--) {
    invF[i] = invF[i + 1] * (i + 1) % mod;
  }
}
long long C(int n, int m) {
  if (n < 0 || m < 0 || m > n) return 0;
  if (m == 0 || m == n) return 1;
  return F[n] * invF[n - m] % mod * invF[m] % mod;
}
int n, m;
char s[MX];
long long sum[MX], num[MX][26];
int solve() {
  long long ret = 0;
  sum[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int len = n; len >= 1; len--) {
      int id = s[i] - 'a', last = num[len][id];
      num[len][id] = (sum[len - 1] - num[len - 1][id]) % mod;
      sum[len] = (sum[len] - last + num[len][id]) % mod;
    }
  }
  for (int len = 1; len <= n; len++) {
    sum[len] = (sum[len] + mod) % mod;
    ret = (ret + C(m - 1, len - 1) * sum[len]) % mod;
  }
  return ret;
}
int main() {
  init();
  scanf("%d%s", &n, s + 1);
  m = n;
  n = unique(s + 1, s + 1 + n) - s - 1;
  printf("%d\n", solve());
  return 0;
}
