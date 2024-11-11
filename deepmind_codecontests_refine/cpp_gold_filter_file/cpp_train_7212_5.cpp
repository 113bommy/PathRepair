#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
const long long inf = 1000000000000000000;
const long long KOK = 100000;
const long long LOG = 30;
const long long li = 3002;
const long long mod = 1000000007;
long long n, m, b[li], a[li], k, flag, t, topl[li];
long long cev;
string s;
vector<long long> v[li];
inline void f(long long bas, long long son, vector<long long> dp) {
  if (bas == son) {
    long long say = 0;
    for (long long i = 0; i < b[bas]; i++) {
      say += v[bas][i];
      if (k - i - 1 < 0) continue;
      cev = max(cev, dp[k - i - 1] + say);
    }
    cev = max(cev, dp[k]);
    return;
  }
  vector<long long> dp1 = dp;
  for (long long i = ((bas + son) / 2) + 1; i <= son; i++) {
    for (long long j = k; j >= 1; j--) {
      if (j < b[i]) continue;
      dp1[j] = max(dp1[j], dp1[j - b[i]] + topl[i]);
    }
  }
  f(bas, ((bas + son) / 2), dp1);
  dp1 = dp;
  for (long long i = bas; i <= ((bas + son) / 2); i++) {
    for (long long j = k; j >= 1; j--) {
      if (j < b[i]) continue;
      dp1[j] = max(dp1[j], dp1[j - b[i]] + topl[i]);
    }
  }
  f(((bas + son) / 2) + 1, son, dp1);
}
int32_t main(void) {
  scanf("%lld %lld", &n, &k);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &b[i]);
    for (long long j = 1; j <= b[i]; j++) {
      long long x;
      scanf("%lld", &x);
      v[i].push_back(x);
      topl[i] += x;
    }
  }
  vector<long long> vv(k + 2);
  for (long long i = 0; i <= k; i++) vv[i] = 0;
  f(1, n, vv);
  printf("%lld\n", cev);
  return 0;
}
