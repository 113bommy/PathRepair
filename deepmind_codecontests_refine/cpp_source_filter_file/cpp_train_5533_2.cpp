#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const long long MOD = 1e9 + 7;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = 1e-8;
int _;
using namespace std;
long long dp[MAXN];
long long powermod(long long n, long long k, long long MOD) {
  long long ans = 1;
  while (k) {
    if (k & 1) {
      ans = ((ans % MOD) * (n % MOD)) % MOD;
    }
    n = ((n % MOD) * (n % MOD)) % MOD;
    k >>= 1;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int M;
  while (cin >> M) {
    memset(dp, 0, sizeof(dp));
    for (int i = M; i >= 2; --i) {
      int cnt = 0;
      for (int j = i; j <= M; j += i) {
        cnt++;
        dp[i] -= dp[j];
      }
      long long tmp = 1LL * cnt * powermod(M, MOD - 2, MOD);
      tmp = tmp * powermod(1 - tmp, MOD - 2, MOD) % MOD;
      dp[i] = (dp[i] + tmp + MOD) % MOD;
    }
    long long res = 1;
    for (int i = 1; i <= M; ++i) res = (res + dp[i] + MOD) % MOD;
    cout << res << endl;
  }
  return 0;
}
