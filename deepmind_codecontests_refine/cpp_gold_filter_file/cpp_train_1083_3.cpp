#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const int inf = ~0U >> 1;
int n, m, k, s;
vector<pair<int, int> > p[10];
int var[10][4];
int note[200010];
int dis[20][20];
inline int max4(int a, int b, int c, int d) {
  return max(max(a, b), max(c, d));
}
int search(int u, int v) {
  int ret = 0;
  for (int i = 0; i < p[u].size(); ++i) {
    int x = p[u][i].first, y = p[u][i].second;
    ret = max(ret, max4(var[v][0] - (x + y), var[v][1] - (x - y),
                        var[v][2] - (-x + y), var[v][3] - (-x - y)));
  }
  return ret;
}
void init(int k) {
  fill(var[k], var[k] + 4, -inf);
  for (int i = 0; i < p[k].size(); ++i) {
    var[k][0] = max(var[k][0], p[k][i].first + p[k][i].second);
    var[k][1] = max(var[k][1], p[k][i].first - p[k][i].second);
    var[k][2] = max(var[k][2], -p[k][i].first + p[k][i].second);
    var[k][3] = max(var[k][3], -p[k][i].first - p[k][i].second);
  }
}
int main() {
  scanf("%d %d %d %d", &n, &m, &k, &s);
  for (int i = 1; i <= n; ++i)
    for (int j = 1, x; j <= m; ++j) {
      scanf("%d", &x);
      p[x].push_back(make_pair(i, j));
    }
  for (int i = 1; i <= k; ++i) init(i);
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= i; ++j) dis[j][i] = dis[i][j] = search(i, j);
  for (int i = 0; i < s; ++i) scanf("%d", note + i);
  int ans = 0;
  for (int i = 1; i < s; ++i) ans = max(ans, dis[note[i - 1]][note[i]]);
  cout << ans << endl;
  return 0;
}
