#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int i, j, n, ans = 0, k1, k2;
    cin >> n;
    long long int arr[n];
    vector<vector<long long int> > vec(26);
    for (i = 0; i < n; i++) {
      cin >> arr[i];
      vec[arr[i] - 1].push_back(i);
    }
    long long int dp1[n][26], dp2[n][26];
    for (i = 0; i < n; i++)
      for (j = 0; j < 26; j++) {
        dp1[i][j] = 0;
        dp2[i][j] = 0;
      }
    dp1[0][arr[0] - 1]++;
    for (i = 1; i < n; i++) {
      for (j = 0; j < 26; j++)
        if (arr[i] == j + 1)
          dp1[i][j] += dp1[i - 1][j] + 1;
        else
          dp1[i][j] += dp1[i - 1][j];
    }
    dp2[n - 1][arr[n - 1] - 1]++;
    for (i = n - 2; i >= 0; i--) {
      for (j = 0; j < 26; j++)
        if (arr[i] == j + 1)
          dp2[i][j] += dp2[i + 1][j] + 1;
        else
          dp2[i][j] += dp2[i + 1][j];
    }
    for (i = 0; i < 26; i++) {
      long long int dd = vec[i].size();
      ans = max(ans, dd);
    }
    for (i = 0; i < 26; i++) {
      for (k1 = 0; k1 < vec[i].size(); k1++) {
        for (k2 = k1; k2 < vec[i].size(); k2++) {
          long long int d1 = vec[i][k1], d2 = vec[i][k2];
          for (j = 0; j < 26; j++)
            if (i != j)
              ans = max(ans, k2 - k1 + 1 + 2 * min(dp1[d1][j], dp2[d2][j]));
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
