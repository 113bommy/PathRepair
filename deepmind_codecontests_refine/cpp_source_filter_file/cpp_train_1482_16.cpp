#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 61, maxm = 20001;
int n, m, k;
int pf[maxn][maxm], dp[maxn][maxm];
int op[maxm];
int mono[maxm], head, tail;
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> pf[i][j], pf[i][j] += pf[i][j - 1];
  auto get = [&](int row, int l, int r) {
    return pf[row][min(m, r)] - pf[row][l - 1];
  };
  int res = 0;
  for (int j = 1; j <= n; ++j) dp[1][j] = get(1, j, j + k - 1);
  for (int i = 2; i <= n; ++i) {
    head = tail = 0;
    for (int j = 1; j <= m; ++j) {
      auto cal = [&](int pos) {
        return dp[i - 1][pos] + get(i, pos, j + k - 1);
      };
      while (tail - head && mono[head] + k <= j) ++head;
      while (tail - head && cal(mono[tail - 1]) <= cal(j)) --tail;
      mono[tail++] = j;
      dp[i][j] = cal(mono[head]);
    }
    head = tail = 0;
    for (int j = m; j >= 1; --j) {
      auto cal = [&](int pos) {
        return dp[i - 1][pos] + get(i, j, pos + k - 1);
      };
      while (tail - head && j + k - 1 < mono[head]) ++head;
      while (tail - head && cal(mono[tail - 1]) <= cal(j)) --tail;
      mono[tail++] = j;
      dp[i][j] = max(dp[i][j], cal(mono[head]));
    }
    for (int j = 1; j <= m; ++j)
      op[j] = max(op[j - 1], dp[i - 1][j] + get(i, j, j + k - 1));
    for (int j = k + 1; j <= m; ++j)
      dp[i][j] = max(dp[i][j], op[j - k] + get(i, j, j + k - 1));
    for (int j = m; j >= 1; --j)
      op[j] = max(op[j + 1], dp[i - 1][j] + get(i, j, j + k - 1));
    for (int j = m - k; j >= 1; --j)
      dp[i][j] = max(dp[i][j], op[j + k] + get(i, j, j + k - 1));
  }
  for (int i = 1; i <= m; ++i) res = max(res, dp[n][i]);
  cout << res << '\n';
}
