#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    T t = bigmod(p, e / 2, M);
    return (t * t) % M;
  }
  return (bigmod(p, e - 1, M) * p) % M;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T multimod(T a, T b, T m) {
  T ans = 0ll;
  a %= m, b %= m;
  while (b) {
    if (b & 1ll) ans = m - ans > a ? (ans + a) : (ans + a - m);
    b >>= 1ll;
    a = (m - a) > a ? a + a : a + a - m;
  }
  return (T)ans;
}
int col[101];
long long dp[101][101][101];
long long cost[101][101];
int N, M, K;
long long solve(int ind, int pre, int k) {
  if (ind == N + 1) {
    if (k == K) return 0;
    return 10000000000000000ll;
  }
  long long &ret = dp[ind][pre][k];
  if (ret != -1ll) return ret;
  ret = 10000000000000000ll;
  if (col[ind]) {
    if (pre != col[ind])
      return ret = solve(ind + 1, col[ind], k + 1);
    else
      return ret = solve(ind + 1, col[ind], k + 1);
  }
  for (int i = 1; i <= M; i++) {
    ret = min(ret, cost[ind][i] + solve(ind + 1, i, k + (i != pre)));
  }
  return ret;
}
int main() {
  int cases = 1, tc, t, i, n, j, val, num;
  cin >> N >> M >> K;
  n = N;
  int m = M;
  for (i = 1; i <= n; i++) cin >> col[i];
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) cin >> cost[i][j];
  memset(dp, -1ll, sizeof dp);
  long long res = solve(1, 0, 0);
  if (res >= 10000000000000000ll)
    cout << -1 << endl;
  else
    cout << res << endl;
  return 0;
}
