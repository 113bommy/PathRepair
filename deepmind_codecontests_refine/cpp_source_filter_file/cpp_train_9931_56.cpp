#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:33554432")
using namespace std;
const double PI = 2 * acos(0.0);
const double EPS = 1e-8;
const int INF = (1 << 30) - 1;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
int m, n;
int a[1700][1700];
vector<pair<int, int> > coords;
void dfs1(int r, int c) {
  if (a[r][c] != 1) return;
  coords.push_back(make_pair(r, c));
  a[r][c] = 2;
  for (int i = 0; i < 4; ++i) dfs1(r + dr[i], c + dc[i]);
}
int fillWith(int r, int c, int col1, int col2) {
  if (a[r][c] != col1) return 0;
  a[r][c] = col2;
  int res = 1;
  for (int i = 0; i < 4; ++i) res += fillWith(r + dr[i], c + dc[i], col1, col2);
  return res;
}
void buildCoords(int r, int c) {
  coords.clear();
  dfs1(r, c);
}
const int D = 5;
inline double getNeighborsShare(int r, int c) {
  int res = 0;
  for (int cr = max<int>(r - D, 0); cr <= min<int>(r + D, m - 1); ++cr) {
    for (int cc = max<int>(c - D, 0); cc <= min<int>(c + D, n - 1); ++cc) {
      if (a[cr][cc] != 0) ++res;
    }
  }
  return (res + 0.) / (2 * D + 1) / (2 * D + 1);
}
int getRays(int r, int c) {
  buildCoords(r, c);
  for (int i = 0; i < (int)((coords).size()); ++i) {
    int r = coords[i].first;
    int c = coords[i].second;
    if (getNeighborsShare(r, c) > 0.4) a[r][c] = 3;
  }
  int ans = 0;
  for (int i = 0; i < (int)((coords).size()); ++i)
    if (a[coords[i].first][coords[i].second] == 2) {
      if (fillWith(coords[i].first, coords[i].second, 2, 3) > 5) ++ans;
      ;
    }
  for (int i = 0; i < (int)((coords).size()); ++i)
    a[coords[i].first][coords[i].second] = 0;
  return ans;
}
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) scanf("%d", &a[i + 1][j + 1]);
  }
  m += 2;
  n += 2;
  vector<int> ans;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (a[i][j] != 0) ans.push_back(getRays(i, j));
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
  return 0;
};
