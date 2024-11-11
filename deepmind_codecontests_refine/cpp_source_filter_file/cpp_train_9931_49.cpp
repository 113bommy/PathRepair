#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void smn(T &a, const T &b) {
  if (b < a) a = b;
}
template <class T>
inline void smx(T &a, const T &b) {
  if (b > a) a = b;
}
template <class T>
inline T _rev(const T &a) {
  T _ = a;
  reverse(_.begin(), _.end());
  return _;
}
const double eps = 1e-8;
const long double leps = 1e-14;
const int MN = 2000;
bool mp[MN][MN];
int mark[MN][MN];
bool good[MN][MN];
int n, m;
vector<pair<int, int> > all;
vector<int> rays;
int cc = 0;
bool av(int x, int y) {
  int cnt = 0;
  for (int i = x - 2; i <= x + 2; i++)
    for (int j = y - 2; j <= y + 2; j++)
      if (i >= 0 && j >= 0 && i < n && j < m && mp[i][j] && mark[i][j] == 1)
        cnt++;
  return cnt <= 11;
}
void dfs(int x, int y) {
  mark[x][y] = 1;
  all.push_back(pair<int, int>(x, y));
  for (int i = x - 1; i <= x + 1; i++)
    for (int j = y - 1; j <= y + 1; j++)
      if (i >= 0 && j >= 0 && i < n && j < m && mp[i][j] && !mark[i][j])
        dfs(i, j);
}
void dfs2(int x, int y) {
  cc++;
  mark[x][y] = 2;
  for (int i = x - 1; i <= x + 1; i++)
    for (int j = y - 1; j <= y + 1; j++)
      if (i >= 0 && j >= 0 && i < n && j < m && mp[i][j] && mark[i][j] == 1 &&
          good[i][j])
        dfs2(i, j);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> mp[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (mark[i][j] == 0 && mp[i][j] == 1) {
        int cnt = 0;
        all.clear();
        dfs(i, j);
        for (int k = 0; k < all.size(); k++) {
          int x = all[k].first, y = all[k].second;
          good[x][y] = av(x, y);
        }
        for (int k = 0; k < all.size(); k++)
          if (good[all[k].first][all[k].second] &&
              mark[all[k].first][all[k].second] == 1) {
            cc = 0;
            dfs2(all[k].first, all[k].second);
            if (cc >= 1) cnt++;
          }
        for (int k = 0; k < all.size(); k++)
          mark[all[k].first][all[k].second] = 3;
        rays.push_back(cnt);
      }
  sort(rays.begin(), rays.end());
  cout << rays.size() << '\n';
  for (int i = 0; i < rays.size(); i++) cout << rays[i] << " ";
  cout << '\n';
  return 0;
}
