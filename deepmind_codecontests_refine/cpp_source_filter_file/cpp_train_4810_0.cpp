#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 120, inf = 1e18 + 1, inf2 = 1e9;
int cnt, n, m, last, c[maxn][maxn], a[maxn], o[maxn];
long long int k, dp[maxn][maxn];
pair<int, int> p[2 * maxn];
char ch[maxn][maxn];
long long int func() {
  dp[0][1] = 0;
  if (a[0] != 2) dp[0][1] = 1;
  for (int i = 1; i < n + m - 1; i++) {
    dp[i][0] = 0;
    if (a[i] != 1) dp[i][0] += dp[i - 1][1];
    for (int j = 1; j < 110; j++) {
      dp[i][j] = 0;
      if (a[i] != 2) dp[i][j] += dp[i - 1][j - 1];
      if (dp[i][j] > inf) dp[i][j] = inf;
      if (a[i] != 1) dp[i][j] += dp[i - 1][j + 1];
      if (dp[i][j] > inf) dp[i][j] = inf;
    }
  }
  return dp[n + m - 2][0];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> c[i][j];
  for (int i = 0; i < m; i++) {
    int pos = i, pos2 = 0;
    o[i] = inf2;
    while (pos >= 0 && pos2 < n) o[i] = min(o[i], c[pos2++][pos--]);
    p[cnt++] = make_pair(o[i], i);
  }
  for (int i = 1; i < n; i++) {
    int pos = i, pos2 = m - 1;
    o[i + m - 1] = inf2;
    while (pos < n && pos2 >= 0)
      o[i + m - 1] = min(o[i + m - 1], c[pos++][pos2--]);
    p[cnt++] = make_pair(o[i + m - 1], i + m - 1);
  }
  sort(p, p + n + m - 1);
  last = n + m - 1;
  for (int j = 0; j < n + m - 1; j++) {
    a[p[j].second] = 1;
    long long int F = func();
    if (F < k) {
      a[p[j].second] = 2;
      k -= F;
    }
  }
  for (int i = 0; i < n + m - 1; i++) {
    char c = '(';
    if (a[p[i].second] == 2) c = ')';
    if (p[i].second < m)
      for (int j = p[i].second; j > -1; j--) ch[p[i].second - j][j] = c;
    else
      for (int j = p[i].second - m + 1; j < n; j++)
        ch[j][m - 1 - (j - (p[i].second - m + 1))] = c;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << ch[i][j];
    cout << endl;
  }
  return 0;
}
