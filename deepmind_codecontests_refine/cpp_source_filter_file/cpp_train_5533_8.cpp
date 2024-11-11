#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = LONG_LONG_MAX;
const long long mod = 1e9 + 7;
const int N = 1e5 + 50;
vector<long long> factor[N];
long long mu[N], pri[N], dp[N], m;
int cnt = 0;
bool vis[N];
void getmu() {
  mu[1] = 1;
  for (int i = 2; i <= (int)1e5; i++) {
    if (!vis[i]) pri[++cnt] = i, mu[i] = -1;
    for (int j = 1; j <= cnt && pri[j] * i <= (int)1e5; j++) {
      vis[i * pri[j]] = true;
      if (i % pri[j] == 0) {
        mu[i * pri[j]] = 0;
        break;
      } else
        mu[i * pri[j]] = -mu[i];
    }
  }
}
long long getinv(long long x) {
  long long y = mod - 2, ans = 1;
  while (y) {
    if (y & 1) ans *= x, ans %= mod;
    x *= x, x %= mod;
    y >>= 1;
  }
  return ans;
}
void getfactor() {
  for (long long i = 1; i <= (long long)1e5; i++)
    for (long long j = i; j <= (long long)1e5; j += i) factor[j].push_back(i);
}
long long gsum(long long x, long long d) {
  long long sum = 0;
  for (auto t : factor[x / d]) sum += mu[t] * (m / (d * t)), sum %= mod;
  return sum;
}
int main() {
  getmu();
  getfactor();
  scanf("%lld", &m);
  dp[1] = 0;
  long long ans = 0;
  for (long long i = 2; i <= m; i++) {
    long long rhs = m;
    for (auto fac : factor[i]) {
      if (fac == i) continue;
      long long sum = gsum(i, fac);
      rhs += dp[fac] * sum;
      rhs %= mod;
    }
    dp[i] = rhs * getinv(m - m / i), dp[i] %= mod;
    ans += dp[i], ans %= mod;
  }
  printf("%lld\n", 1 + ans * getinv(m));
  return 0;
}
