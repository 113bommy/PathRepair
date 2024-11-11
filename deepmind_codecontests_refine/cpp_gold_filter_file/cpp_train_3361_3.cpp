#include <bits/stdc++.h>
using namespace std;
void programm();
int main() {
  int t = 0;
  cin >> t;
  for (int i = 0; i < t; i++) {
    programm();
  }
}
void programm() {
  int n = 0;
  cin >> n;
  vector<int> data(n);
  for (auto& elem : data) cin >> elem;
  sort(data.begin(), data.end());
  int inf = 20000;
  vector<vector<int>> dp(n, vector<int>(2 * n, inf));
  for (int i = 0; i < 2 * n; i++) dp[0][i] = abs(data[0] - i - 1);
  for (int i = 0; i < n; i++) {
    dp[i][0] = inf;
  }
  dp[0][0] = data[0] - 1;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < 2 * n; j++) {
      int best = inf;
      for (int k = 0; k < j; k++) {
        if (dp[i - 1][k] < best) {
          best = dp[i - 1][k];
        }
      }
      int now = best + abs(data[i] - j - 1);
      dp[i][j] = now;
    }
  }
  int answ = inf;
  for (int i = 0; i < 2 * n; i++) {
    if (dp[n - 1][i] < answ) {
      answ = dp[n - 1][i];
    }
  }
  cout << answ << endl;
}
