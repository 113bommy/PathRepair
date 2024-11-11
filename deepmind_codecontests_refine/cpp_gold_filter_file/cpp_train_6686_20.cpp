#include <bits/stdc++.h>
using std::cin;
using std::cout;
int n, m, k, a[50 + 2][20000 + 1], psum[50 + 1][20000 + 2],
    prmax[50 + 1][20000 + 1], psmax[50 + 1][20000 + 1], dp[50 + 1][20000 + 1];
int min(int a, int b) { return (b < a) ? b : a; }
int max(int a, int b) { return (a < b) ? b : a; }
int asum(int i, int j) {
  return psum[i][j + k] - psum[i][j] + psum[i + 1][j + k] - psum[i + 1][j];
}
void in() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      psum[i][j + 1] = psum[i][j] + a[i][j];
    }
}
void prs() {
  for (int j = 1; j + k - 1 <= m; ++j) dp[1][j] = asum(1, j);
  for (int j = 1; j + k - 1 <= m; ++j)
    prmax[1][j] = max(prmax[1][j - 1], dp[1][j]);
  for (int j = m - k + 1; j >= 1; --j)
    psmax[1][j] = max(psmax[1][j + 1], dp[1][j]);
  int b = min(m - k + 1, 1 + k);
  for (int i = 2; i <= n; ++i) {
    std::deque<int> dq1, dq2;
    for (int l = 2; l <= b; ++l) {
      while (!dq1.empty() &&
             dp[i - 1][dq1.back()] - (psum[i][1 + k] - psum[i][dq1.back()]) <=
                 dp[i - 1][l] - (psum[i][1 + k] - psum[i][l]))
        dq1.pop_back();
      dq1.push_back(l);
    }
    dq2.push_back(1);
    int mx = dp[i - 1][1] - psum[i][1 + k];
    if (!dq1.empty())
      mx = max(
          mx, dp[i - 1][dq1.front()] - (psum[i][1 + k] - psum[i][dq1.front()]));
    if (k + 1 <= m - k + 1) mx = max(mx, psmax[i - 1][k + 1]);
    dp[i][1] = asum(i, 1) + mx;
    for (int j = 2; j + k - 1 <= m; ++j) {
      if (!dq1.empty() && dq1.front() == j) dq1.pop_front();
      if (j + k <= m - k + 1) {
        while (!dq1.empty() &&
               dp[i - 1][dq1.back()] - (psum[i][j + k] - psum[i][dq1.back()]) <=
                   dp[i - 1][j + k])
          dq1.pop_back();
        dq1.push_back(j + k);
      }
      if (dq2.front() == j - k) dq2.pop_front();
      while (!dq2.empty() &&
             dp[i - 1][dq2.back()] - (psum[i][dq2.back() + k] - psum[i][j]) <=
                 dp[i - 1][j] - (psum[i][j + k] - psum[i][j]))
        dq2.pop_back();
      dq2.push_back(j);
      int mx = dp[i - 1][dq2.front()] - (psum[i][dq2.front() + k] - psum[i][j]);
      if (!dq1.empty())
        mx = max(mx, dp[i - 1][dq1.front()] -
                         (psum[i][j + k] - psum[i][dq1.front()]));
      if (j > k) mx = max(mx, prmax[i - 1][j - k]);
      if (j + k <= m - k + 1) mx = max(mx, psmax[i - 1][j + k]);
      dp[i][j] = mx + asum(i, j);
    }
    for (int j = 1; j + k - 1 <= m; ++j)
      prmax[i][j] = max(prmax[i][j - 1], dp[i][j]);
    for (int j = m - k + 1; j >= 1; --j)
      psmax[i][j] = max(psmax[i][j + 1], dp[i][j]);
  }
}
void out() { cout << psmax[n][1]; }
void run() {
  in();
  prs();
  out();
}
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  run();
  return 0;
}
