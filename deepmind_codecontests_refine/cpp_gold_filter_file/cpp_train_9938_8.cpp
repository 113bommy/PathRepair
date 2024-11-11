#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7, N = 5005;
long long ans[N][N];
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  memset(ans, 0, sizeof ans);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  for (int i = a; i <= n; ++i) ans[0][i] = 1;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1, d; j <= n; ++j) {
      if (j < b) {
        d = (b + j - 1) / 2;
        ans[i][j] = ans[i - 1][d];
      } else if (j > b) {
        d = (j + b + 2) / 2;
        ans[i][j] = (ans[i - 1][n] - ans[i - 1][d - 1] + M) % M;
      }
      ans[i][j] = (ans[i][j] - ans[i - 1][j] + ans[i - 1][j - 1] + M) % M;
      ans[i][j] = (ans[i][j] + ans[i][j - 1]) % M;
    }
  }
  cout << ans[k][n];
}
