#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXD = 2002;
int main() {
  int n;
  cin >> n;
  vector<int> T(n), D(n), P(n);
  for (int i = (0); i < (n); i++) cin >> T[i] >> D[i] >> P[i];
  vector<int> indexes;
  for (int i = (0); i < (n); i++) indexes.push_back(i);
  sort(indexes.begin(), indexes.end(),
       [=](int i, int j) { return D[i] < D[j]; });
  vector<vector<int>> dp(n + 1, vector<int>(MAXD * 2, 0));
  for (int i = (0); i < (n); i++)
    for (int t = (0); t < (MAXD); t++) {
      if (dp[i + 1][t] < dp[i][t]) {
        dp[i + 1][t] = dp[i][t];
      }
      if (t + T[indexes[i]] < D[indexes[i]]) {
        if (dp[i + 1][t + T[indexes[i]]] < dp[i][t] + P[indexes[i]]) {
          dp[i + 1][t + T[indexes[i]]] = dp[i][t] + P[indexes[i]];
        }
      }
    }
  int time = -1;
  int max_p = 0;
  for (int t = (0); t < (MAXD); t++)
    if (max_p < dp[n][t]) {
      max_p = dp[n][t];
      time = t;
    }
  vector<int> item_order;
  while (time > 0 and n > 0) {
    if (dp[n - 1][time] == dp[n][time]) {
      --n;
      continue;
    } else {
      item_order.push_back(indexes[n - 1]);
      time -= T[indexes[n - 1]];
      --n;
    }
  }
  reverse(item_order.begin(), item_order.end());
  cout << max_p << endl;
  cout << item_order.size() << endl;
  for (auto itm : item_order) printf("%d ", itm);
  cout << endl;
  return 0;
}
