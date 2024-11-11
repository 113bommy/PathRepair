#include <bits/stdc++.h>
using namespace std;
long long fact[2000005], inv[2000005];
long long modexp(long long a, long long b) {
  long long ans = 1LL;
  while (b) {
    if (b & 1) ans = (ans * a) % (long long)(1000000007);
    a = (a * a) % (long long)(1000000007);
    b >>= 1LL;
  }
  return ans;
}
void pre() {
  fact[0] = fact[1] = 1;
  for (long long i = 2; i < 2000005; i++) {
    fact[i] = (fact[i - 1] * i) % (long long)(1000000007);
  }
  for (long long i = 0; i < 2000005; i++)
    inv[i] = modexp(fact[i], (long long)(1000000007) - 2LL);
}
long long perm(long long a, long long b) {
  if (a < 0 || b < 0) return 0;
  return ((fact[a + b] * inv[a]) % (long long)(1000000007) * inv[b]) %
         (long long)(1000000007);
}
long long func(long long x1, long long y1, long long x2, long long y2) {
  return perm(x2 - x1, y2 - y1);
}
long long dp[2000005];
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  pre();
  long long h, w, n;
  cin >> h >> w >> n;
  vector<pair<long long, long long> > v;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }
  v.push_back({h, w});
  sort(v.begin(), v.end());
  for (long long i = 0; i < v.size(); i++) {
    dp[i] = func(1, 1, v[i].first, v[i].second);
    long long a = 0;
    for (long long j = i - 1; j >= 0; j--) {
      a = (a + dp[j] * func(v[j].first, v[j].second, v[i].first, v[i].second)) %
          (long long)(1000000007);
    }
    dp[i] = (dp[i] - a + (long long)(1000000007)) % (long long)(1000000007);
  }
  cout << dp[v.size() - 1];
  return 0;
}
