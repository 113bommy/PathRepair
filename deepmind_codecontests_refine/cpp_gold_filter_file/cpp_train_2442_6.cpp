#include <bits/stdc++.h>
using namespace std;
const int K = 7;
const int N = 2005;
int poz[K][N];
vector<int> s[N];
int dp[N], n, k;
int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      int temp;
      cin >> temp;
      --temp;
      if (i == 0) {
        poz[i][j] = temp;
      } else {
        poz[i][temp] = j;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    s[i] = vector<int>(k - 1);
    for (int j = 1; j < k; ++j) {
      s[i][j - 1] = poz[j][poz[0][i]];
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      bool canUse = true;
      for (int p = 0; p < (int)s[j].size(); p++) {
        if (s[i][p] <= s[j][p]) {
          canUse = false;
          break;
        }
      }
      if (canUse) {
        dp[i] = max(dp[j] + 1, dp[i]);
      }
    }
    res = max(res, dp[i]);
  }
  cout << res;
  return 0;
}
