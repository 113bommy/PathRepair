#include <bits/stdc++.h>
using namespace std;
int k, a[20000], b[20000];
int ans;
int lx, ly;
string s;
int dp[2][20000], best[20000];
inline void upd(int &c, int d, pair<int, int> &a, pair<int, int> b) {
  if (d > c) {
    a = b;
    c = d;
  }
}
inline int f(int first, int second) {
  if (a[first] + b[second] < k)
    return a[first] + b[second];
  else
    return a[first] + b[second] - k;
}
inline pair<int, int> calc(int p, int q, int l, int c) {
  int tot = (l - p + c - q) / 2;
  pair<int, int> ans = {0, 0};
  int cost = -1;
  dp[0][c] = 0;
  for (int i = c - 1; i >= q; i--) {
    dp[0][i] = dp[0][i + 1] + f(l, i + 1);
    if (i - q + l - p == tot) best[i] = dp[0][i];
  }
  for (int i = l - 1, w = 1; i >= p; i--, w ^= 1) {
    dp[w][c] = dp[1 - w][c] + f(i + 1, c);
    if (i - p + c - q == tot) best[c] = dp[w][c];
    for (int j = c - 1; j >= q; j--) {
      dp[w][j] = max(dp[1 - w][j] + f(i + 1, j), dp[w][j + 1] + f(i, j + 1));
      if (i - p + j - q == tot) best[j] = dp[w][j];
    }
  }
  dp[0][q] = 0;
  for (int i = q + 1; i <= c; i++) {
    dp[0][i] = dp[0][i - 1] + f(p, i);
    if (i - q == tot) upd(cost, best[i] + dp[0][i], ans, {p, i});
  }
  for (int i = p + 1, w = 1; i <= l; i++, w ^= 1) {
    dp[w][q] = dp[1 - w][q] + f(i, q);
    if (i - p == tot) upd(cost, best[q] + dp[w][q], ans, {i, q});
    for (int j = q + 1; j <= c; j++) {
      dp[w][j] = f(i, j) + max(dp[w][j - 1], dp[1 - w][j]);
      if (i - p + j - q == tot) upd(cost, best[j] + dp[w][j], ans, {i, j});
    }
  }
  return ans;
}
void solve(int p, int q, int l, int c) {
  if (l == p && c == q) {
    if (lx == p && ly == q - 1) {
      ans += f(p, q);
      s.push_back('S');
      ly++;
    } else if (lx == p - 1 && ly == q) {
      ans += f(p, q);
      s.push_back('C');
      lx++;
    }
  } else if (l - p + c - q == 1) {
    solve(p, q, p, q);
    solve(l, c, l, c);
  } else {
    pair<int, int> m = calc(p, q, l, c);
    solve(p, q, m.first, m.second);
    solve(m.first, m.second, l, c);
  }
}
int main() {
  int n, m;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= k;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    b[i] %= k;
  }
  solve(0, 0, n - 1, m - 1);
  cout << ans + f(0, 0) << '\n' << s << '\n';
  return 0;
}
