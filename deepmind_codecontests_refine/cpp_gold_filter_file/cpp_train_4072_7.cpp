#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, MOD = 1e9 + 7, S = 8;
int n, f[N], cnt[N], C[N][S], dp[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    f[x] = 1;
  }
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      cnt[i] += f[j];
    }
  }
  for (int i = 0; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= min(S - 1, i); ++j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      if (C[i][j] >= MOD) C[i][j] -= MOD;
    }
  }
  for (int s = 1; s < 8; ++s) {
    for (int v = N - 1; v > 0; --v) {
      dp[v] = C[cnt[v]][s];
      for (int i = 2 * v; i < N; i += v) {
        dp[v] -= dp[i];
        if (dp[v] < 0) dp[v] += MOD;
      }
    }
    if (dp[1] > 0) {
      cout << s << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
