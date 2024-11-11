#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int mod = 1e9 + 7;
int n;
long long m;
long long sum[MAXN], inv[MAXN], fra[MAXN], lim[MAXN];
long long power(long long a, long long b) {
  long long c = 1;
  while (b) {
    if (b % 2 == 1) {
      c = (c * a) % mod;
    }
    a = (a * a) % mod;
    b /= 2;
  }
  return c;
}
long long C(long long a, long long b) {
  if (b > a || b < 0) return 0;
  return (fra[a] * inv[b] % mod) * inv[a - b] % mod;
}
void init() {
  fra[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    fra[i] = fra[i - 1] * i % mod;
  }
  inv[200000] = power(fra[200000], mod - 2);
  for (int i = 199999; i >= 0; i--) {
    inv[i] = inv[i + 1] * (i + 1) % mod;
  }
}
void update(long long &val, long long down, int now, int fut) {
  if (fut > now) {
    for (int i = now + 1; i <= fut; i++) {
      val = (val + C(down, i)) % mod;
    }
  } else {
    for (int i = now; i >= fut + 1; i--) {
      val = (val - C(down, i)) % mod;
    }
    val = (val + mod) % mod;
  }
}
int main() {
  init();
  scanf("%d%lld", &n, &m);
  long long inv2 = (1 + mod) / 2, invBas = 1;
  long long ans = 0, pre = 0;
  lim[0] = -1;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &sum[i]);
    sum[i] += sum[i - 1];
    invBas = invBas * inv2 % mod;
    lim[i] = max(-1LL, min((long long)i, m - sum[i]));
    pre = (pre * 2 + C(i - 1, lim[i - 1] + 1)) % mod;
    update(pre, i, lim[i - 1] + 1, lim[i]);
    ans = (ans + pre * invBas % mod) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
