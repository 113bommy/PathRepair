#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e3 + 10, inf = 1e9 + 10;
int dp[MAXN][MAXN], dp2[MAXN][MAXN], b[MAXN];
bool mark[MAXN];
pair<int, int> a[MAXN], par[MAXN][MAXN];
vector<int> ans1, ans2;
set<pair<int, int> > s2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, p, s;
  cin >> n >> p >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a, a + n);
  reverse(a, a + n);
  memset(dp2, -63, sizeof dp2);
  memset(dp, -63, sizeof dp);
  dp2[n][0] = 0;
  for (int i = n - 1; i >= 0; i--) {
    dp2[i][0] = 0;
    for (int j = 1; j <= n - i; j++)
      dp2[i][j] = max(dp2[i + 1][j], dp2[i + 1][j - 1] + b[a[i].second]);
  }
  dp[0][0] = a[0].first;
  dp[0][1] = b[a[0].second];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= i + 1; j++) {
      int ind = a[i].second;
      dp[i][j] = dp[i - 1][j] + a[i].first;
      par[i][j] = make_pair(i - 1, j);
      if (j == 0) continue;
      if (dp[i - 1][j - 1] + b[ind] > dp[i][j]) {
        dp[i][j] = dp[i - 1][j - 1] + b[ind];
        par[i][j] = make_pair(i - 1, j - 1);
      }
    }
  }
  int mx = 0, ind = 0;
  for (int i = p - 1; i < s + p; i++) {
    int val = dp[i][i - p + 1] + dp2[i + 1][s - (i - p) - 1];
    if (val > mx) {
      mx = val;
      ind = i;
    }
  }
  cout << mx << '\n';
  int x1 = ind, x2 = ind - p + 1;
  for (int i = 0; i < ind - p + 1;) {
    int y1 = par[x1][y1].first, y2 = par[x1][y1].second;
    if (y2 == x2 - 1) {
      ans2.push_back(a[x1].second);
      i++;
      mark[a[x1].second] = true;
    }
    x1 = y1;
    x2 = y2;
  }
  for (int i = 0; i <= ind; i++)
    if (!mark[a[i].second]) ans1.push_back(a[i].second);
  for (int i = n - 1; i > ind; i--)
    s2.insert(make_pair(inf - b[a[i].second], a[i].second));
  int cnt = 0;
  for (auto y : s2) {
    if (cnt == s - (ind - p + 1)) break;
    cnt++;
    ans2.push_back(y.second);
  }
  for (auto c1 : ans1) cout << c1 + 1 << " ";
  cout << '\n';
  for (auto c2 : ans2) cout << c2 + 1 << " ";
  return 0;
}
