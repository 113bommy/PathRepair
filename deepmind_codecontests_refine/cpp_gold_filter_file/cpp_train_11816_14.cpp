#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
long long dp[MAXN];
long long f[MAXN];
pair<long long, long long> x[MAXN];
bool cmp(const pair<int, int> &A, const pair<int, int> &B) {
  if (A.first != B.first) return A.first < B.first;
  return A.second < B.second;
}
long long power(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret *= a;
    a *= a;
    b >>= 1;
    if (ret >= MOD) ret %= MOD;
    if (a >= MOD) a %= MOD;
  }
  return ret;
}
long long inv(long long x) { return power(x, MOD - 2); }
long long C(long long a, long long b) {
  long long ret = f[a];
  ret *= inv(f[b]);
  if (ret >= MOD) ret %= MOD;
  ret *= inv(f[a - b]);
  if (ret >= MOD) ret %= MOD;
  return ret;
}
long long ways(long long x, long long y, long long fx, long long fy) {
  return C(x + y - fx - fy, x - fx);
}
int main() {
  f[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    f[i] = f[i - 1] * 1LL * i;
    if (f[i] >= MOD) f[i] %= MOD;
  }
  int h, w, n;
  cin >> h >> w >> n;
  for (int i = 1; i <= n; i++) cin >> x[i].first >> x[i].second;
  sort(x + 1, x + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    int px = x[i].first, py = x[i].second;
    dp[i] = ways(px, py, 1, 1);
    for (int j = i - 1; j >= 1; j--) {
      int ppx = x[j].first, ppy = x[j].second;
      if (ppx <= px and ppy <= py) {
        long long temp = dp[j];
        temp *= ways(px, py, ppx, ppy);
        if (temp >= MOD) temp %= MOD;
        dp[i] -= temp;
        if (dp[i] < 0) dp[i] += MOD;
      }
    }
  }
  long long ans = ways(h, w, 1, 1);
  for (int i = 1; i <= n; i++) {
    long long temp = dp[i];
    temp *= ways(h, w, x[i].first, x[i].second);
    if (temp >= MOD) temp %= MOD;
    ans -= temp;
    if (ans < 0) ans += MOD;
  }
  cout << ans << endl;
  return 0;
}
