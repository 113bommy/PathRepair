#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
int t;
int n, m, k;
struct node {
  int x, y;
  bool operator<(const node& a) const {
    if (x == a.x) return y < a.y;
    return x < a.x;
  }
} A[2005];
long long dp[2005];
long long jc[500020], jcinv[500020];
long long qpow(long long a, long long b) {
  long long ans = 1 % mod;
  for (; b; b >>= 1ll) {
    if (b & 1ll) ans = ans * a % mod;
    a = a * a % mod;
  }
  return ans;
}
long long inv(long long a) { return qpow(a, mod - 2); }
void init(int n) {
  jc[1] = 1;
  jcinv[1] = inv(1);
  for (int i = 2; i <= n; i++) {
    jc[i] = jc[i - 1] * i % mod;
    jcinv[i] = inv(jc[i]);
  }
}
long long C(int n, int m) {
  if (n == 0)
    return 1;
  else if (n == m)
    return 1;
  return jc[m] % mod * jcinv[n] % mod * jcinv[m - n] % mod;
}
int main() {
  init(500005);
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d%d", &A[i].x, &A[i].y);
    A[i].x--, A[i].y--;
  }
  A[k].x = n - 1, A[k].y = m - 1;
  ++k;
  sort(A, A + k);
  for (int i = 0; i < k; ++i) {
    dp[i] = C(A[i].x, A[i].x + A[i].y);
    for (int j = 0; j < i; ++j) {
      if (A[i].y >= A[j].y)
        dp[i] = (dp[i] - dp[j] * C(A[i].x - A[j].x,
                                   A[i].x - A[j].x + A[i].y - A[j].y)) %
                mod;
    }
  }
  printf("%lld\n", ((dp[k - 1]) % mod + mod) % mod);
}
