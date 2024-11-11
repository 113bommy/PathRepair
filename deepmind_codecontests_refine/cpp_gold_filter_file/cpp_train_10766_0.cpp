#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, dp[75][75][75], mark[75][75][75];
string s[75];
queue<pair<pair<int, int>, int> > q;
pair<pair<int, int>, int> p[75][75][75];
int main() {
  cin >> n >> a >> b >> c;
  for (int i = 0; i < n; i++) cin >> s[i];
  q.push({{a, b}, c});
  p[a][b][c] = {{a, b}, c};
  mark[a][b][c] = 1;
  dp[a][b][c] = 0;
  int v1c, v2c, v3c, v1, v2, v3;
  while (q.size()) {
    v1 = q.front().first.first, v2 = q.front().first.second,
    v3 = q.front().second;
    v1c = v1, v2c = v2, v3c = v3;
    if (v1c > v2c) swap(v1c, v2c);
    if (v2c > v3c) swap(v2c, v3c);
    if (v1c > v2c) swap(v1c, v2c);
    if (v1c == 1 && v2c == 2 && v3c == 3) break;
    q.pop();
    for (int i = 1; i <= n; i++) {
      if (i != v1 && i != v2 && i != v3) {
        if (s[i - 1][v1 - 1] == s[v2 - 1][v3 - 1] && !mark[i][v2][v3]) {
          q.push({{i, v2}, v3});
          mark[i][v2][v3] = 1;
          dp[i][v2][v3] = dp[v1][v2][v3] + 1;
          p[i][v2][v3] = {{v1, v2}, v3};
        }
        if (s[i - 1][v2 - 1] == s[v1 - 1][v3 - 1] && !mark[v1][i][v3]) {
          q.push({{v1, i}, v3});
          mark[v1][i][v3] = 1;
          dp[v1][i][v3] = dp[v1][v2][v3] + 1;
          p[v1][i][v3] = {{v1, v2}, v3};
        }
        if (s[i - 1][v3 - 1] == s[v1 - 1][v2 - 1] && !mark[v1][v2][i]) {
          q.push({{v1, v2}, i});
          mark[v1][v2][i] = 1;
          dp[v1][v2][i] = dp[v1][v2][v3] + 1;
          p[v1][v2][i] = {{v1, v2}, v3};
        }
      }
    }
  }
  vector<int> ans;
  if (v1c == 1 && v2c == 2 && v3c == 3) {
    cout << dp[v1][v2][v3] << endl;
    while (p[v1][v2][v3].first.first != v1 ||
           p[v1][v2][v3].first.second != v2 || p[v1][v2][v3].second != v3) {
      int v1s = p[v1][v2][v3].first.first, v2s = p[v1][v2][v3].first.second,
          v3s = p[v1][v2][v3].second;
      if (v1s != v1) {
        ans.push_back(v1s);
        ans.push_back(v1);
      }
      if (v2s != v2) {
        ans.push_back(v2s);
        ans.push_back(v2);
      }
      if (v3s != v3) {
        ans.push_back(v3s);
        ans.push_back(v3);
      }
      v1 = v1s;
      v2 = v2s;
      v3 = v3s;
    }
  } else
    cout << -1;
  for (int i = ans.size() - 1; i >= 0; i -= 2) {
    cout << ans[i - 1] << " " << ans[i] << endl;
  }
  return 0;
}
