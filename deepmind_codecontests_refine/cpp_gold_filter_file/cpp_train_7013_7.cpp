#include <bits/stdc++.h>
using namespace std;
long long dp[55][55];
double comb[55];
int a[55];
int main(int argc, char **argv) {
  int n, p;
  int tot = 0;
  double res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tot += a[i];
  }
  cin >> p;
  if (tot <= p) {
    cout << n << endl;
    return 0;
  }
  comb[0] = 1;
  for (int i = 1; i <= n; i++) comb[i] = comb[i - 1] * i;
  for (int block = 0; block < n; block++) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
      if (i == block) continue;
      for (int j = p - a[i]; j >= 0; j--) {
        for (int k = 0; k < n - 1; k++) {
          dp[j + a[i]][k + 1] += dp[j][k];
        }
      }
    }
    for (int i = 0; i <= p; i++) {
      if (a[block] + i > p) {
        for (int j = 1; j <= n - 1; j++) {
          res += j * dp[i][j] * comb[j] * comb[n - 1 - j] / comb[n];
        }
      }
    }
  }
  cout << res << endl;
}
