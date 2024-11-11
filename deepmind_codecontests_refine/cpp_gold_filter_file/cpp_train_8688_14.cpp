#include <bits/stdc++.h>
using namespace std;
const int M = 2e2 + 5;
int mark[M][M];
pair<int, int> ct[M];
pair<int, int> ch[M];
vector<pair<int, int> > adj[M][M];
bool loop = 0;
int dis[M][M];
int dp[M][M];
int st[M][M], ft[M][M];
int timer = 1;
int ans = 0;
void dfs(int h, int t) {
  st[h][t] = timer++;
  mark[h][t] = 1;
  for (int i = 0; i < adj[h][t].size(); i++) {
    int childt = adj[h][t][i].second;
    int childh = adj[h][t][i].first;
    if (!mark[childh][childt])
      dfs(childh, childt);
    else if (st[childh][childt] <= st[h][t] && !ft[childh][childt])
      loop = 1;
    dp[h][t] = max(dp[h][t], dp[childh][childt] + 1);
  }
  ft[h][t] = timer++;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int h, t, r;
  cin >> h >> t >> r;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> ch[i].first >> ch[i].second;
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> ct[i].first >> ct[i].second;
  for (int i = 0; i <= r; i++)
    for (int j = 0; i + j <= r; j++) {
      for (int k = 1; k <= n; k++)
        if (i + j + ch[k].first + ch[k].second - k <= r && k <= i)
          adj[i][j].push_back(make_pair(i + ch[k].first - k, j + ch[k].second));
      for (int k = 1; k <= m; k++) {
        if (i + j + ct[k].first + ct[k].second - k <= r && k <= j) {
          adj[i][j].push_back(make_pair(i + ct[k].first, j + ct[k].second - k));
        }
      }
    }
  queue<pair<int, int> > q;
  q.push(make_pair(h, t));
  mark[h][t] = 1;
  while (!q.empty()) {
    int hnow = q.front().first;
    int tnow = q.front().second;
    if (hnow == 0 && tnow == 0) {
      cout << "Ivan\n" << dis[hnow][tnow];
      return 0;
    }
    for (int i = 0; i < adj[hnow][tnow].size(); i++) {
      int childh = adj[hnow][tnow][i].first;
      int childt = adj[hnow][tnow][i].second;
      if (!mark[childh][childt]) {
        dis[childh][childt] = dis[hnow][tnow] + 1;
        mark[childh][childt] = 1;
        q.push(make_pair(childh, childt));
      }
    }
    q.pop();
  }
  for (int i = 0; i <= r; i++)
    for (int j = 0; i + j <= r; j++) mark[i][j] = 0;
  dfs(h, t);
  if (loop)
    cout << "Draw" << endl;
  else
    cout << "Zmey\n" << dp[h][t] + 1 << endl;
  return 0;
}
