#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int MAXN = 1e6 + 10;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
const long long INF = 8e18;
const int LOG = 22;
long long pw(long long a, long long b, long long mod) {
  return (!b ? 1
             : (b & 1 ? (a * pw(a * a % mod, b / 2, mod)) % mod
                      : pw(a * a % mod, b / 2, mod)));
}
long long dp[2][(1 << 20)], Dp[(1 << 20)];
int X[MAXN], K[MAXN], B[MAXN];
bool comp(int a, int b) { return K[a] < K[b]; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m, b;
  cin >> n >> m >> b;
  vector<int> N;
  for (int i = 0; i < n; i++) N.push_back(i);
  for (int i = 0; i < n; i++) {
    int T, cu = 0;
    cin >> X[i] >> K[i] >> T;
    for (int i = 0; i < T; i++) {
      int a;
      cin >> a;
      a--;
      cu |= (1 << a);
    }
    B[i] = cu;
  }
  sort((N).begin(), (N).end(), comp);
  for (int mask = 0; mask < (1 << 20); mask++) {
    Dp[mask] = dp[1][mask] = dp[0][mask] = 5e18;
  }
  int z = dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < (1 << m); mask++) {
      dp[1 - z][mask] = dp[z][mask];
    }
    int cu = N[i];
    for (int mask = 0; mask < (1 << m); mask++) {
      int new_mask = (mask | B[cu]);
      dp[1 - z][new_mask] = min(dp[1 - z][new_mask], dp[z][mask] + X[cu]);
    }
    for (int mask = 0; mask < (1 << m); mask++) {
      Dp[mask] = min(Dp[mask], dp[1 - z][mask] + (1ll) * K[cu] * b);
    }
    z = 1 - z;
  }
  if (Dp[(1 << m) - 1] >= 5e18) {
    return cout << -1, 0;
  }
  cout << Dp[(1 << m) - 1];
  return 0;
}
