#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int num[30];
int dp[30010], ftt[30010];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    string s;
    cin >> s;
    set<int> ft;
    memset(num, 0, sizeof(num));
    for (int i = 0; i < k; ++i) {
      num[s[i] - 'A']++;
      ft.insert(s[i] - 'A');
    }
    if (n < m) {
      swap(n, m);
    }
    long long ans = -1;
    for (auto &x : ft) {
      memset(dp, 0, sizeof(dp));
      dp[0] = 1;
      int max_n = 0, max_m = 0;
      for (auto &y : ft) {
        if (x == y) {
          continue;
        }
        for (int j = n; j >= 0; --j) {
          if (dp[j] > 0) {
            if (j + num[y] <= n) {
              dp[j + num[y]] = 1;
            }
          }
        }
      }
      ftt[n] = -1;
      for (int j = n - 1; j > -1; --j) {
        if (dp[j] > 0) {
          ftt[j] = j;
        } else {
          ftt[j] = ftt[j + 1];
        }
      }
      for (int j = 0; j <= num[x]; ++j) {
        if (ftt[n - j] >= 0) {
          long long ret = 0;
          int left = (k - num[x] - ftt[n - j]);
          if (k - ftt[n - j] - j >= m) {
            ;
            ;
            if (left >= m) {
              ret = 0;
            } else {
              ret = (long long)j * (num[x] - left);
            };
            ;
            if (ans < 0 || ans > ret) {
              ans = ret;
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
}
