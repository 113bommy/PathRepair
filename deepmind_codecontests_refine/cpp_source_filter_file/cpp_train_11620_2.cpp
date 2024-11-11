#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1e18 + 10;
int n, k;
const int N = 4000;
int count_2[200];
int count_5[200];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int64_t a;
    cin >> a;
    int64_t t = a;
    while (t % 2 == 0) {
      count_2[i]++;
      t /= 2;
    }
    t = a;
    while (t % 5 == 0) {
      count_5[i]++;
      t /= 5;
    }
  }
  static int dp[210][10000];
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  int sum_5 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = k - 1; j >= 0; j--) {
      for (int l = count_5[i]; l >= 0; l--) {
        if (dp[j][l] != -1) {
          dp[j + 1][l + count_5[i]] =
              max(dp[j + 1][l + count_5[i]], dp[j][l] + count_2[i]);
        }
      }
    }
    sum_5 += count_5[i];
  }
  int ans = 0;
  for (int i = 0; i <= sum_5; i++) {
    ans = max(ans, min(i, dp[k][i]));
  }
  cout << ans << endl;
  return 0;
}
