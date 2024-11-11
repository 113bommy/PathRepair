#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const int mxN = 2005;
template <class T>
T gcd(T a, T b) {
  return ((b == 0) ? a : gcd(b, a % b));
}
string s[mxN];
pair<int, char> dp[mxN][mxN];
char lev[2 * mxN], be[mxN][mxN];
int p[mxN][mxN];
int vis[mxN][mxN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < (int)(n); i++) cin >> s[i];
  queue<array<int, 2>> q;
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++) dp[i][j] = {0, 'z'};
  for (int i = 0; i < (int)(2 * mxN); i++) lev[i] = 'z';
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++) be[i][j] = 'z';
  dp[0][0].first = k;
  dp[0][0].second = 'a';
  if (s[0][0] == 'a')
    q.push({0, 0});
  else {
    if (k)
      q.push({0, 0}), dp[0][0].first--;
    else
      q.push({0, 0}), dp[0][0].second = s[0][0];
  }
  vis[0][0] = 1;
  while (!q.empty()) {
    array<int, 2> cur = q.front();
    q.pop();
    int x = cur[0], y = cur[1];
    if ((x + y) > 0 && dp[x][y].second > lev[x + y]) continue;
    if (x < (n - 1)) {
      if (dp[x][y].second == 'a' && dp[x][y].first) {
        int nw = dp[x][y].first - (s[x + 1][y] != 'a');
        if (nw >= dp[x + 1][y].first) {
          dp[x + 1][y].first = nw;
          dp[x + 1][y].second = 'a';
          p[x + 1][y] = 1;
          if (!vis[x + 1][y]) q.push({x + 1, y});
          be[x + 1][y] = 'a';
          lev[x + 1 + y] = min(lev[x + 1 + y], 'a');
          vis[x + 1][y] = 1;
        }
      } else {
        if (dp[x][y].second < be[x + 1][y]) {
          p[x + 1][y] = 1;
          be[x + 1][y] = dp[x][y].second;
          dp[x + 1][y].second = s[x + 1][y];
          lev[x + 1 + y] = min(lev[x + 1 + y], dp[x + 1][y].second);
          if (!vis[x + 1][y]) q.push({x + 1, y});
          vis[x + 1][y] = 1;
        }
      }
    }
    if (y < (n - 1)) {
      if (dp[x][y].second == 'a' && dp[x][y].first) {
        int nw = dp[x][y].first - (s[x][y + 1] != 'a');
        if (nw >= dp[x][y + 1].first) {
          dp[x][y + 1].first = nw;
          dp[x][y + 1].second = 'a';
          p[x][y + 1] = 2;
          if (!vis[x][y + 1]) q.push({x, y + 1});
          be[x][y + 1] = 'a';
          lev[x + 1 + y] = min(lev[x + 1 + y], 'a');
          vis[x][y + 1] = 1;
        }
      } else {
        if (dp[x][y].second < be[x][y + 1]) {
          p[x][y + 1] = 2;
          be[x][y + 1] = dp[x][y].second;
          dp[x][y + 1].second = s[x][y + 1];
          lev[x + 1 + y] = min(lev[x + 1 + y], dp[x][y + 1].second);
          if (!vis[x][y + 1]) q.push({x, y + 1});
          vis[x][y + 1] = 1;
        }
      }
    }
  }
  int x = n - 1, y = n - 1;
  int pr = p[x][y];
  string ans = "";
  ans += s[n - 1][n - 1];
  while (pr) {
    if (pr == 1)
      x--;
    else
      y--;
    ans += s[x][y];
    pr = p[x][y];
  }
  reverse(ans.begin(), ans.end());
  int rem = k;
  for (int i = 0; i < (int)(ans.size()); i++) {
    if (!rem) break;
    if (ans[i] != 'a') ans[i] = 'a', rem--;
  }
  cout << ans << endl;
  return 0;
}
