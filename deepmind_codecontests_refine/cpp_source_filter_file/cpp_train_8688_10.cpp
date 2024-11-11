#include <bits/stdc++.h>
using namespace std;
const int N = 2500;
vector<pair<int, int> > ad[N][N];
int a[2][N], b[2][N];
const int Inf = 2500;
int mark[N][N];
int d[N][N], dp[N][N];
bool cyc = 0;
void bfs(int h, int t) {
  queue<pair<int, int> > q;
  d[h][t] = 1;
  q.push({h, t});
  while (q.size()) {
    pair<int, int> v = q.front();
    q.pop();
    for (auto i : ad[v.first][v.second])
      if (!d[i.first][i.second])
        q.push(i), d[i.first][i.second] = d[v.first][v.second] + 1;
  }
}
void dfs(pair<int, int> u) {
  mark[u.first][u.second] = 1;
  for (auto i : ad[u.first][u.second]) {
    if (!mark[i.first][i.second]) dfs(i);
    if (mark[i.first][i.second] == 1) cyc = 1;
    dp[u.first][u.second] =
        max(dp[u.first][u.second], dp[i.first][i.second] + 1);
  }
  mark[u.first][u.second] = 2;
  return;
}
void make(int r, int n, int m) {
  for (int i = 0; i <= r; i++) {
    for (int j = 0; j <= r; j++) {
      if (i + j <= r) {
        for (int k = 1; k <= min(i, n); k++)
          ad[i][j].push_back({i - k + a[0][k], j + b[0][k]});
        for (int k = 1; k <= min(m, j); k++)
          ad[i][j].push_back({i + a[1][k], j - k + b[1][k]});
      }
    }
  }
}
int main() {
  int h, t, r, n, m, mx = 0;
  cin >> h >> t >> r;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[0][i] >> b[0][i];
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> a[1][i] >> b[1][i];
  make(r, n, m);
  bfs(h, t);
  if (d[0][0] - 1 > 0 && d[0][0] < Inf)
    return cout << "Ivan" << endl << d[0][0] - 1 << endl, 0;
  dfs({h, t});
  if (cyc) return cout << "Draw" << endl, 0;
  cout << "Zmey" << endl << dp[h][t] << endl;
}
