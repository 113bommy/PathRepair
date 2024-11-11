#include <bits/stdc++.h>
using namespace std;
const int MN = 2000;
bool mp[MN][MN];
int mark[MN][MN];
bool good[MN][MN];
int n, m;
vector<pair<int, int> > all;
vector<int> rays;
int cc = 0;
bool isg(int x, int y) {
  int cnt = 0;
  for (int i = x - 2; i <= x + 2; i++) {
    for (int j = y - 2; j <= y + 2; j++) {
      if (i >= 0 && j >= 0 && i < n && j < m && mp[i][j] && mark[i][j] == 1)
        cnt++;
    }
  }
  return cnt <= 11;
}
void dfs1(int x, int y) {
  mark[x][y] = 1;
  all.push_back(pair<int, int>(x, y));
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      if (i >= 0 && j >= 0 && i < n && j < m && mp[i][j] && mark[i][j] == 0)
        dfs1(i, j);
    }
  }
}
void dfs2(int x, int y) {
  mark[x][y] = 2;
  cc++;
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      if (i >= 0 && j >= 0 && i < n && j < m && mp[i][j] && mark[i][j] == 1 &&
          good[i][j])
        dfs2(i, j);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> mp[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mark[i][j] == 0 && mp[i][j] == 1) {
        int cnt = 0;
        all.clear();
        dfs1(i, j);
        for (int k = 0; k < all.size(); k++) {
          int x = all[k].first, y = all[k].second;
          good[x][y] = isg(x, y);
        }
        for (int k = 0; k < all.size(); k++)
          if (good[all[k].first][all[k].second] &&
              mark[all[k].first][all[k].second] == 1) {
            cc = 0;
            dfs2(all[k].first, all[k].second);
            if (cc >= 3) cnt++;
          }
        for (int k = 0; k < all.size(); k++)
          mark[all[k].first][all[k].second] = 3;
        rays.push_back(cnt);
      }
    }
  }
  sort(rays.begin(), rays.end());
  cout << rays.size() << endl;
  for (int i = 0; i < rays.size(); i++) cout << rays[i] << " ";
  cout << endl;
  return 0;
}
