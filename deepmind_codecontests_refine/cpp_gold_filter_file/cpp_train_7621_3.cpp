#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int N = 1e2 + 20;
const long long mod = 998244353;
const long long inf = 8e18;
const int LOG = 22;
long long pw(long long a, long long b, long long M) {
  return (!b ? 1
             : (b & 1 ? (a * pw(a * a % M, b / 2, M)) % M
                      : pw(a * a % M, b / 2, M)));
}
long long dp[N][N][N], ps[N][N], L[N], R[N], I[N], Z = 1;
vector<long long> cm;
long long E(long long r, long long n) {
  if (r > n || r < 0) return 0ll;
  if (r == 0 || r == n) return 1ll;
  long long ret = 1;
  for (long long i = n; i > n - r; i--) ret = ret * i % mod;
  for (long long i = 1; i <= r; i++) ret = ret * I[i] % mod;
  return ret;
}
long long calc(int i, int k) {
  int z = cm[i] - cm[i - 1] - 1;
  return E(k, z + k);
}
int main() {
  for (int i = 1; i < N; i++) I[i] = pw(i, mod - 2, mod);
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &L[i], &R[i]);
    R[i]++;
    cm.push_back(L[i]), cm.push_back(R[i]);
    Z = (Z * (R[i] - L[i])) % mod;
  }
  sort((cm).begin(), (cm).end());
  cm.resize(unique((cm).begin(), (cm).end()) - cm.begin());
  m = (int)cm.size();
  for (int j = 1; j < m; j++) {
    if (L[1] <= cm[j - 1] && cm[j] <= R[1]) {
      dp[1][j][1] = 1;
    }
  }
  for (int j = m - 1; ~(j - 1); j--) {
    ps[1][j] = ps[1][j + 1] + dp[1][j][1] * calc(j, 1);
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < m; j++) {
      if (!(L[i] <= cm[j - 1] && cm[j] <= R[i])) continue;
      for (int k = 1; k <= i; k++) {
        if (k > 1) {
          dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % mod;
        } else {
          dp[i][j][k] = (dp[i][j][k] + ps[i - 1][j + 1]) % mod;
        }
      }
    }
    for (int j = m - 1; ~(j - 1); j--) {
      ps[i][j] = ps[i][j + 1];
      for (int k = 1; k <= i; k++) {
        ps[i][j] = (ps[i][j] + dp[i][j][k] * calc(j, k)) % mod;
      }
    }
  }
  printf("%lld", ps[n][1] * pw(Z, mod - 2, mod) % mod);
  return 0;
}
