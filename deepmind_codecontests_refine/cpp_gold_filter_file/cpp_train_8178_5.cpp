#include <bits/stdc++.h>
using namespace std;
long long dp[200000] = {};
long long boom[200000][3] = {};
long long ans[200000] = {};
int main() {
  long long n;
  cin >> n;
  vector<long long> t;
  t.push_back(0);
  for (long long i = 0; i < n; ++i) {
    long long tmp;
    cin >> tmp;
    t.push_back(tmp);
  }
  t.push_back(8000000000000000000);
  for (long long i = 0; i < 3; ++i) {
    long long ticker = 90;
    if (i == 1)
      ticker = 180;
    else if (i == 2)
      ticker = 1440;
    long long now_look = 1;
    for (long long q = 0; q < n; ++q) {
      while (true) {
        if (t[now_look] - (t[q + 1] - 1) > ticker) break;
        now_look++;
      }
      boom[q][i] = now_look - 1;
    }
  }
  for (long long i = 0; i < 200000; ++i) {
    dp[i] = 8000000000000000000;
  }
  dp[0] = 1;
  for (long long i = 1; i <= n; ++i) {
    if (dp[i - 1] != 0) {
      dp[i] = min(dp[i], dp[i - 1] + 20);
      dp[boom[i - 1][0]] = min(dp[boom[i - 1][0]], dp[i - 1] + 50);
      dp[boom[i - 1][2]] = min(dp[boom[i - 1][2]], dp[i - 1] + 120);
    }
  }
  long long hoge = dp[n + 1];
  ans[n + 1] = hoge;
  for (long long i = n; i >= 0; --i) {
    hoge = min(hoge, dp[i]);
    ans[i] = hoge;
  }
  for (long long i = 1; i <= n; ++i) {
    cout << ans[i] - ans[i - 1] << endl;
  }
  return 0;
}
