#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops,inline,no-stack-protector")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
using namespace std;
const int MAXN = 4050;
int dp[MAXN][MAXN];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> L(n), S(n), H(MAXN);
  for (int i = 0; i < n; i++) cin >> L[i];
  for (int i = 0; i < n; i++) cin >> S[i];
  vector<int> C(MAXN);
  for (int i = 1; i <= n + m; i++) cin >> C[i];
  for (int i = 0; i < MAXN; i++) {
    for (int j = 0; j < MAXN; j++) {
      dp[i][j] = -1e6;
    }
  }
  for (int i = 0; i <= n + m; i++) {
    dp[i][0] = 0;
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int k = H[L[i]]; k >= 0; k--) {
      dp[L[i]][k + 1] = max(dp[L[i]][k + 1], dp[L[i]][k] - S[i] + C[L[i]]);
    }
    H[L[i]]++;
    for (int j = L[i]; j <= n + m; j++) {
      for (int k = H[j]; k >= 0; k--) {
        if (dp[j][k] > -5e5) {
          dp[j + 1][k / 2] =
              max(dp[j + 1][k / 2], dp[j][k] + (k / 2) * C[j + 1]);
          H[j + 1] = max(H[j + 1], k / 2);
        }
      }
    }
  }
  cout << dp[n + m][0];
}
