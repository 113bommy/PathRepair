#include <bits/stdc++.h>
using namespace std;
int i, j, n, m, a, b, c, d, op, maxi, mini, mij, ls, ld, ul, timp, k, maxl,
    rasp;
vector<int> v[100005];
int dp[100005][102];
queue<pair<int, pair<int, int> > > q;
vector<int> obiect[101];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int s;
  cin >> n >> m >> k >> s;
  for (i = 1; i <= n; i++) {
    cin >> a;
    q.push({a, {i, 1}});
  }
  for (i = 1; i <= m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  while (q.size()) {
    pair<int, pair<int, int> > now = q.front();
    q.pop();
    if (dp[now.second.first][now.first]) continue;
    dp[now.second.first][now.first] = now.second.second;
    for (auto vecin : v[now.second.first]) {
      q.push({now.first, {vecin, now.second.second + 1}});
    }
  }
  for (int i = 1; i <= n; i++) {
    sort(dp[i] + 1, dp[i] + 1 + k);
    rasp = -s;
    for (int j = 1; j <= s; j++) rasp += dp[i][j];
    cout << rasp << " ";
  }
  return 0;
}
