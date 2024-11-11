#include <bits/stdc++.h>
using namespace std;
const int max_n = 100111, max_h = 780, inf = 1e9 + 100;
int dp[max_h];
int dpp[max_h];
vector<int> col[max_n];
int n, k;
int sum(int a) { return a * (a + 1) / 2; }
int main() {
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    int r, c;
    scanf("%d%d", &r, &c);
    r = n - r + 1;
    c = n - c;
    col[c].push_back(r);
  }
  for (int i = 0; i < n; ++i) {
    sort(col[i].begin(), col[i].end());
  }
  if (!col[0].empty()) {
    dpp[0] = 3;
  }
  for (int i = 1; i < n; ++i) {
    int cnt1 = 0;
    vector<int>& c = col[i];
    int maxj = min(i + 1, max_h - 1);
    while (!c.empty() && c.back() > maxj) {
      ++cnt1;
      c.pop_back();
    }
    int val = inf;
    for (int j = maxj; j >= 0; --j) {
      dp[j] = cnt1 * 3 + dpp[max(0, j - 1)];
      dp[j] = min(dp[j], val);
      val = min(val, cnt1 * 3 + 2 + sum(j) + dpp[max(0, j - 1)]);
      if (!c.empty() && c.back() == j) {
        c.pop_back();
        ++cnt1;
      }
    }
    memcpy(dpp, dp, sizeof(dp));
  }
  cout << dp[0] << endl;
  return 0;
}
