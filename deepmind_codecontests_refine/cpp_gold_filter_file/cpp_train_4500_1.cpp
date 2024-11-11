#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 1;
int n;
long long c[N], h[N], par[N];
long long d[N][N], pre[N][N], len[N][N];
vector<int> node[N];
deque<pair<int, int> > qu;
void Init(int x, int y) {
  qu.push_back(make_pair(x, y));
  qu.push_back(make_pair(y, x));
  pre[x][y] = x;
  len[x][y] = 1;
  d[x][y] = (n - c[y]) * c[y];
  pre[y][x] = y;
  len[y][x] = 1;
  d[y][x] = (n - c[y]) * c[y];
}
void Dfs_Init(int x) {
  c[x] = 1;
  for (int i = 0; i <= node[x].size() - 1; i++) {
    int y = node[x][i];
    if (par[x] == y) continue;
    h[y] = h[x] + 1;
    par[y] = x;
    Dfs_Init(y);
    c[x] += c[y];
    Init(x, y);
  }
}
void Solve(int x, int y) {
  for (int i = 0; i <= node[y].size() - 1; i++) {
    int y_new = node[y][i];
    if (pre[x][y] == y_new) continue;
    long long counts = 0;
    if (h[y] < h[y_new])
      counts = c[y_new];
    else
      counts = n - c[y];
    if (h[x] < h[pre[y][x]])
      counts *= n - c[pre[y][x]];
    else
      counts *= c[x];
    len[x][y_new] = len[x][y] + 1;
    d[x][y_new] = d[x][y] - len[x][y] * counts + len[x][y_new] * counts;
    d[x][y_new] = max(d[x][y_new], d[y_new][x]);
    d[y_new][x] = max(d[x][y_new], d[y_new][x]);
    pre[x][y_new] = y;
    pre[y_new][x] = pre[y][x];
    qu.push_front(make_pair(x, y_new));
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    cin >> x >> y;
    node[x].push_back(y);
    node[y].push_back(x);
  }
  h[1] = 1;
  Dfs_Init(1);
  while (!qu.empty()) {
    int sz = qu.size();
    for (int i = 1; i <= sz; i++) {
      int x = qu.back().first, y = qu.back().second;
      qu.pop_back();
      Solve(x, y);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) ans = max(ans, d[i][j]);
  cout << ans;
}
