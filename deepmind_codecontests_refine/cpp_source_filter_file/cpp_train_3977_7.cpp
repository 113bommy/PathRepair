#include <bits/stdc++.h>
using namespace std;
const int MAXn = 100 + 10;
const long long inf = 1e18 + 1;
int ar[MAXn][MAXn], n, m, hp[MAXn * 2], sz;
long long k, dp[MAXn * 2][MAXn * 2];
char ans[2 * MAXn];
pair<int, int> p[2 * MAXn];
long long count() {
  for (int i = 0; i < 2 * MAXn; i++)
    for (int j = 0; j < 2 * MAXn; j++) dp[i][j] = 0;
  if (ans[0] == 0) {
    dp[0][1] = 1;
  } else if (ans[0] == '(') {
    dp[0][1] = 1;
  } else {
    return 0;
  }
  for (int i = 1; i < sz; i++) {
    if (ans[i] == 0) {
      dp[i][0] = dp[i - 1][1];
      for (int j = 1; j <= i + 3; j++)
        dp[i][j] = min(inf, dp[i - 1][j - 1] + dp[i - 1][j + 1]);
    } else if (ans[i] == '(') {
      for (int j = 1; j <= i + 3; j++) dp[i][j] = dp[i - 1][j - 1];
    } else {
      for (int j = 0; j <= i + 3; j++) dp[i][j] = dp[i - 1][j + 1];
    }
  }
  return dp[sz - 1][0];
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> ar[i][j];
  sz = n + m - 1;
  for (int i = 0; i < sz; i++) hp[i] = 2 * MAXn;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) hp[i + j] = min(hp[i + j], ar[i][j]);
  for (int i = 0; i < sz; i++) p[i] = pair<int, int>(hp[i], i);
  sort(p, p + sz);
  for (int i = 0; i < sz; i++) ans[i] = 0;
  for (int i = 0; i < sz; i++) {
    ans[p[i].second] = '(';
    long long sal = count();
    if (sal < k) {
      k -= sal;
      ans[p[i].second] = ')';
    }
  }
  for (int i = 0; i < n; i++, cout << '\n')
    for (int j = 0; j < m; j++) cout << ans[i + j];
}
