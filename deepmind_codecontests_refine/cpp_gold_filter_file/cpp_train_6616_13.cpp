#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 20, inf = 2e9 + 20, mod = 1e9 + 7;
const string YN[] = {"NO", "YES"};
long long n, a[maxn], b[maxn], dp[maxn][maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < 0 + n; ++i) {
    cin >> a[i];
    b[i] = (a[i] -= i);
  }
  sort(b, b + n);
  for (int i = 0; i < 0 + n; ++i) {
    for (int j = 0; j < 0 + n; ++j) {
      if (i)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = 0;
      dp[i][j] += abs(a[i] - b[j]);
      if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
    }
  }
  cout << dp[n - 1][n - 1];
  cout << endl;
  exit(0);
  ;
}
