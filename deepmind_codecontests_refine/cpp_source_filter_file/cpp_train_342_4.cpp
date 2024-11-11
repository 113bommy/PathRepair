#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[201], b[9], d[201][201], dp[1 << 7][201];
pair<int, int> pre[1 << 7][201];
char ans[101][101];
int f(int S, int p) {
  int& res = dp[S][p];
  if (res > -1) return res;
  for (int i = 0; i < k; i++)
    if (S == (1 << i)) {
      if (b[i] == p) return res = a[p];
    }
  res = 1000000007LL;
  pair<int, int>& pr = pre[S][p];
  for (int T = (S - 1) & S; T > 0; T = (T - 1) & S) {
    int c = f(T, p) + f(T ^ S, p) - a[p];
    if (c < res) {
      res = c;
      pr = make_pair(T, p);
    }
  }
  for (int i = 0; i < n * m; i++)
    if (i != p) {
      int c = f(S, i) + d[p][i] - a[i];
      if (c < res) {
        res = c;
        pr = make_pair(S, i);
      }
    }
  return res;
}
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int id(int x, int y) { return x * m + y; }
void draw(int cur, int to) {
  ans[cur / m][cur % m] = 'X';
  if (cur == to) return;
  int x = cur / m, y = cur % m;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (0 <= nx && nx < n && 0 <= ny && ny < m &&
        a[cur] + d[id(nx, ny)][to] == d[cur][to]) {
      draw(id(nx, ny), to);
      break;
    }
  }
}
void g(int S, int p) {
  pair<int, int> P = pre[S][p];
  if (P.first == -1) {
    draw(p, p);
    return;
  }
  if (P.second != P.first) draw(p, P.second);
  g(P.first, P.second);
  if (P.first != S) g(S ^ P.first, p);
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n * m; i++) cin >> a[i];
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    b[i] = id(x - 1, y - 1);
  }
  for (int i = 0; i < n * m; i++)
    for (int j = 0; j < n * m; j++) d[i][j] = 1000000007LL;
  for (int i = 0; i < n * m; i++) d[i][i] = 0;
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < m; j++) {
      d[id(i, j)][id(i + 1, j)] = a[id(i + 1, j)];
      d[id(i + 1, j)][id(i, j)] = a[id(i, j)];
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m - 1; j++) {
      d[id(i, j)][id(i, j + 1)] = a[id(i, j + 1)];
      d[id(i, j + 1)][id(i, j)] = a[id(i, j)];
    }
  for (int ii = 0; ii < n * m; ii++)
    for (int i = 0; i < n * m; i++)
      for (int j = 0; j < n * m; j++) {
        d[i][j] = min(d[i][j], d[i][ii] + d[ii][j]);
      }
  memset(dp, -1, sizeof(dp));
  memset(pre, -1, sizeof(pre));
  for (int i = 0; i < n * m; i++)
    for (int j = 0; j < n * m; j++) d[i][j] += a[i];
  cout << f((1 << k) - 1, b[0]) << endl;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) ans[i][j] = '.';
  g((1 << k) - 1, b[0]);
  for (int i = 0; i < n; i++) cout << ans[i] << endl;
}
