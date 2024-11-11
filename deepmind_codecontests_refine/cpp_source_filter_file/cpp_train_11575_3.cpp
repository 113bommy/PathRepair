#include <bits/stdc++.h>
using namespace std;
const int maxn = 300;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1},
          dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int t, n, m;
char a[maxn][maxn];
bool vis[maxn][maxn];
vector<pair<int, int> > v;
void dfs(int x, int y) {
  vis[x][y] = 1;
  v.push_back(make_pair(x, y));
  for (int i = 0; i < 8; i++) {
    int tx = x + dx[i], ty = y + dy[i];
    if (tx >= 0 && tx < n && ty >= 0 && ty < n && !vis[tx][ty] &&
        a[tx][ty] == '1') {
      dfs(tx, ty);
    }
  }
}
bool check_side_square() {
  int x = v[0].first, y = v[0].second, sz = (int)v.size() / 4;
  vector<pair<int, int> > s;
  for (int i = x; i < x + sz; i++) {
    s.push_back(make_pair(i, y));
  }
  for (int i = x; i < x + sz; i++) {
    s.push_back(make_pair(i + 1, y + sz));
  }
  for (int i = y; i < y + sz; i++) {
    s.push_back(make_pair(x, i + 1));
  }
  for (int i = y; i < y + sz; i++) {
    s.push_back(make_pair(x + sz, i));
  }
  sort(s.begin(), s.end());
  return s == v;
}
bool check_diagonal_square() {
  int x = v[0].first, y = v[0].second, sz = (int)v.size() / 4;
  vector<pair<int, int> > s;
  int cy = y;
  for (int i = x; i < x + sz; i++) {
    s.push_back(make_pair(i, cy));
    cy--;
  }
  for (int i = x + sz; i < x + sz + sz; i++) {
    s.push_back(make_pair(i, cy));
    cy++;
  }
  cy = y;
  for (int i = x; i < x + sz; i++) {
    cy++;
    s.push_back(make_pair(i + 1, cy));
  }
  for (int i = x + sz + 1; i <= x + sz + sz; i++) {
    cy--;
    s.push_back(make_pair(i, cy));
  }
  sort(s.begin(), s.end());
  return s == v;
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }
  memset(vis, 0, sizeof(vis));
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j] && a[i][j] == '1') {
        v.clear();
        dfs(i, j);
        if ((int)v.size() % 4) {
          continue;
        }
        sort(v.begin(), v.end());
        if (v[0].first == v[1].first) {
          if (check_side_square()) {
            cnt++;
          }
        } else {
          if (check_diagonal_square()) {
            cnt++;
          }
        }
      }
    }
  }
  printf("%d\n", cnt);
}
int main() {
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
