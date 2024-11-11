#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 5;
const int INF = 1e9;
char s[MAXN][MAXN];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
vector<pair<int, int> > g[MAXN * MAXN];
int d[MAXN * MAXN];
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  int fl = 0;
  for (int i = 0; i < n && !fl; i++) {
    for (int j = 0; j < m && !fl; j++) {
      if (s[i][j] == 'B') fl = 1;
    }
  }
  if (!fl) {
    cout << "0";
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 4; k++) {
        int i2 = i + dx[k], j2 = j + dy[k];
        if (i2 < 0 || i2 > n || j2 < 0 || j2 > m) continue;
        int w = (s[i][j] == s[i2][j2] ? 0 : 1);
        g[i * m + j].push_back(make_pair(i2 * m + j2, w));
      }
    }
  }
  int ans = INF;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int i2 = 0; i2 < n; i2++) {
        for (int j2 = 0; j2 < m; j2++) {
          d[i2 * m + j2] = INF;
        }
      }
      d[i * m + j] = 0;
      deque<int> q;
      q.push_front(i * m + j);
      while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        int sz = g[v].size();
        for (int k = 0; k < sz; k++) {
          int to = g[v][k].first;
          int w = g[v][k].second;
          if (d[to] > d[v] + w) {
            d[to] = d[v] + w;
            if (w)
              q.push_back(to);
            else
              q.push_front(to);
          }
        }
      }
      int mx = 0;
      for (int i2 = 0; i2 < n; i2++) {
        for (int j2 = 0; j2 < m; j2++) {
          if (s[i2][j2] == 'W') continue;
          mx = max(mx, d[i2 * m + j2]);
        }
      }
      ans = min(ans, mx + 1);
    }
  }
  cout << ans;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
