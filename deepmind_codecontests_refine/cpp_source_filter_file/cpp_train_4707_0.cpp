#include <bits/stdc++.h>
using namespace std;
int dp[205][205][205];
pair<pair<int, int>, int> pv[205][205][205];
char s[205], t[205];
queue<int> q;
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%s%s", s + 1, t + 1);
  int n = strlen(s + 1), m = strlen(t + 1);
  dp[0][0][0] = 0;
  queue<pair<pair<int, int>, int> > q;
  q.push(pair<pair<int, int>, int>(pair<int, int>(0, 0), 0));
  while (!q.empty()) {
    int a = q.front().first.first, b = q.front().first.second,
        k = q.front().second;
    q.pop();
    int na = a, nb = b, nk = k + 1;
    if (s[a + 1] == '(') na++;
    if (t[b + 1] == '(') nb++;
    if (dp[na][nb][nk] == -1 && nk <= 200) {
      dp[na][nb][nk] = dp[a][b][k] + 1;
      pv[na][nb][nk] = pair<pair<int, int>, int>(pair<int, int>(a, b), k);
      q.push(pair<pair<int, int>, int>(pair<int, int>(na, nb), nk));
    }
    na = a, nb = b, nk = k - 1;
    if (s[a + 1] == ')') na++;
    if (t[b + 1] == ')') nb++;
    if (dp[na][nb][nk] == -1 && k >= 0) {
      dp[na][nb][nk] = dp[a][b][k] + 1;
      pv[na][nb][nk] = pair<pair<int, int>, int>(pair<int, int>(a, b), k);
      q.push(pair<pair<int, int>, int>(pair<int, int>(na, nb), nk));
    }
  }
  string ans = "";
  int a = n, b = m, k = 0;
  while (a != 0 || b != 0 || k != 0) {
    int na = pv[a][b][k].first.first, nb = pv[a][b][k].first.second,
        nk = pv[a][b][k].second;
    if (k + 1 == nk)
      ans += ')';
    else
      ans += '(';
    a = na;
    b = nb;
    k = nk;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << "\n";
}
