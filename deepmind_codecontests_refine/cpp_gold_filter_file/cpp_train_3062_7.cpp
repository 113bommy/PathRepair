#include <bits/stdc++.h>
using namespace std;
vector<int> squares[100005];
int n, k;
int total = 0;
int dp0[2000], dp1[2000], mindp0[2000], mindp1[2000], topsum[2000];
int main() {
  cin >> n >> k;
  int x = min(n, (int)(sqrt(6 * k) + 5));
  for (int i = 0; i < 2000; ++i) {
    dp0[i] = dp1[i] = topsum[i] = 0;
    mindp0[i] = mindp1[i] = 1e9;
  }
  dp0[0] = 0;
  mindp0[0] = 0;
  for (int i = 0; i < k; ++i) {
    int g, h;
    cin >> g >> h;
    if (g < n - x + 1) {
      total += 3;
      continue;
    }
    squares[n - g + h].push_back(n + 1 - g);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= x; ++j) topsum[j] = 0;
    for (int j = 0; j < squares[i].size(); ++j) topsum[squares[i][j]] = 1;
    for (int j = min(i, x); j >= 0; --j) topsum[j] += topsum[j + 1];
    for (int j = min(i, x); j >= 1; --j) {
      dp1[j] = 1e9;
      dp1[j] = min(((j == 1) ? 3 : j) + 3 * topsum[j + 1] + dp0[j - 1],
                   j * (j + 1) / 2 + 2 + 3 * topsum[j + 1] + mindp0[j]);
      mindp1[j] = min(dp1[j], mindp1[j + 1]);
    }
    dp1[0] = mindp0[0] + 3 * topsum[1];
    mindp1[0] = min(mindp1[1], dp1[0]);
    for (int j = 0; j <= min(i, x); ++j) {
      dp0[j] = dp1[j];
      mindp0[j] = mindp1[j];
    }
  }
  int mini = 1e9;
  for (int j = 0; j <= min(n, x); ++j) mini = min(dp0[j], mini);
  cout << total + mini << endl;
}
