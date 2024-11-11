#include <bits/stdc++.h>
using namespace std;
int a1[2005], a2[2005], dp[2005][2005];
int main() {
  int n;
  cin >> n;
  vector<int> a, v;
  int now;
  int t1 = 0, t2 = 0;
  for (int i = 0; i < n; ++i) {
    cin >> now;
    a.push_back(now);
    if (now == 1)
      t1++;
    else
      t2++;
  }
  int t11 = 0, t22 = t2;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) t11++;
    a1[i] = t11;
    a2[i] = t22;
    if (a[i] == 2) t22--;
  }
  for (int i = 0; i < a.size(); ++i) dp[i][i] = 1;
  for (int i = a.size() - 1; i >= 0; --i) {
    for (int j = i - 1; j >= 0; --j) {
      if (a[j] == 1) {
        dp[j][i] = max(dp[j + 1][i], a1[i] - a1[j] + 1);
      } else {
        dp[j][i] = dp[j + 1][i] + 1;
      }
    }
  }
  int mx = 0;
  for (int i = 0; i < a.size(); ++i) {
    for (int j = i; j < a.size(); ++j) {
      int now = 0;
      if (i - 1 >= 0) now += a1[i - 1];
      if (j + 1 < a.size()) now += a2[j + 1];
      now += dp[i][j];
      mx = max(mx, now);
    }
  }
  cout << mx << endl;
}
