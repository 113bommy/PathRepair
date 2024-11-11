#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << ' ' << H;
  debug_out(T...);
}
const int INF = 1e9;
const long long MOD = 1e9 + 7;
const int MAXN = 5e2 + 5;
int P[MAXN * MAXN], DP[MAXN][MAXN];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  P[0] = 1;
  for (int i = 1; i < MAXN * MAXN; i++) P[i] = (P[i - 1] << 1) % MOD;
  DP[0][0] = 1;
  for (int i = 1; i < MAXN; i++) {
    for (int j = 1; j <= i; j++) {
      for (int l = 0; l < i; l++) {
        DP[i][j] = (DP[i][j] + 1LL * (P[i - l] - 1) * P[(i - l) * l] % MOD *
                                   DP[l][j - 1] % MOD) %
                   MOD;
      }
    }
  }
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 0; i <= n; i++)
    ans = (ans + 1LL * P[i * (n - i)] * DP[i][k] % MOD);
  cout << ans << '\n';
  return 0;
}
