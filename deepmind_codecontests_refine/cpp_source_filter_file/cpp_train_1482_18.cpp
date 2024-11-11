#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp, in, pref;
int main() {
  dp.clear();
  in.clear();
  pref.clear();
  int n, m, k;
  cin >> n >> m >> k;
  dp.resize(n + 2);
  in.resize(n + 2);
  pref.resize(n + 2);
  dp[0].assign(m + 1, 0);
  in[0].assign(m + 1, 0);
  pref[0].assign(m + 1, 0);
  dp[n + 1].assign(m + 1, 0);
  in[n + 1].assign(m + 1, 0);
  pref[n + 1].assign(m + 1, 0);
  for (int i = 0; i < n; i++) {
    pref[i + 1].assign(m + 1, 0);
    dp[i + 1].assign(m + 1, 0);
    in[i + 1].assign(m + 1, 0);
    for (int j = 0; j < m; j++) {
      cin >> in[i + 1][j + 1];
    }
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      pref[i][j] = in[i][j];
      pref[i][j] += (pref[i][j - 1]);
    }
  }
  vector<long long> maxleft, maxright;
  maxleft.assign(m + 1, 0);
  maxright.assign(m + 1, 0);
  for (int i = 1; i < n + 1; i++) {
    maxleft.assign(m + 1, 0);
    maxright.assign(m + 1, 0);
    for (int j = k + 1; j < m + 1; j++) {
      maxleft[j] = dp[i - 1][j - k];
      maxleft[j] = max(maxleft[j - 1], maxleft[j]);
    }
    for (int j = m - k; j > 0; j--) {
      maxright[j] = dp[i - 1][j + k];
      maxright[j] = max(maxright[j], maxright[j + 1]);
    }
    for (int j = 1; j < m - k + 2; j++) {
      int l = max(j - k, 1);
      int temp = pref[i + 1][j + k - 1] - pref[i + 1][j - 1];
      int temp2 = pref[i][j + k - 1] - pref[i][j - 1];
      while (l <= j) {
        dp[i][j] = max(dp[i][j],
                       dp[i - 1][l] + pref[i][j + k - 1] - pref[i][l + k - 1]);
        l++;
      }
      while (l + k <= m + 1 && l <= j + k) {
        dp[i][j] =
            max(dp[i][j], dp[i - 1][l] + pref[i][l - 1] - pref[i][j - 1]);
        l++;
      }
      dp[i][j] += temp;
      dp[i][j] = max(dp[i][j], temp + temp2 + maxleft[j]);
      dp[i][j] = max(dp[i][j], temp + temp2 + maxright[min(m, j + k - 1)]);
    }
  }
  long long temp = 0;
  for (int i = 0; i < m; i++) {
    temp = max(temp, dp[n][i + 1]);
  }
  cout << temp << endl;
  return 0;
}
