#include <bits/stdc++.h>
using namespace std;
vector<vector<bool> > pic, ray, vis;
vector<int> ans;
int cnt;
void floodfill(int x, int y) {
  if (vis[x][y] || !pic[x][y]) return;
  vis[x][y] = true;
  if (!pic[x - 2][y] && !pic[x + 2][y]) {
    if (!pic[x][y - 1] && (!pic[x - 2][y + 5] || !pic[x + 2][y + 5]))
      ray[x][y] = true;
    if (!pic[x][y + 1] && (!pic[x - 2][y - 5] || !pic[x + 2][y - 5]))
      ray[x][y] = true;
  }
  if (!pic[x][y - 2] && !pic[x][y + 2]) {
    if (!pic[x - 1][y] && (!pic[x + 5][y - 2] || !pic[x + 5][y + 2]))
      ray[x][y] = true;
    if (!pic[x + 1][y] && (!pic[x - 5][y - 2] || !pic[x - 5][y + 2]))
      ray[x][y] = true;
  }
  if (ray[x][y] && !ray[x - 1][y - 1] && !ray[x - 1][y + 1] &&
      !ray[x + 1][y - 1] && !ray[x + 1][y + 1])
    ++cnt;
  floodfill(x - 1, y);
  floodfill(x + 1, y);
  floodfill(x, y - 1);
  floodfill(x, y + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  pic = ray = vis = vector<vector<bool> >(n + 4, vector<bool>(m + 4));
  char c;
  n++, m++;
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j <= m; ++j) {
      cin >> c;
      pic[i][j] = (c == '1');
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j <= m; ++j) {
      if (pic[i][j] && !vis[i][j]) {
        cnt = 0;
        floodfill(i, j);
        ans.push_back(cnt);
        cout << endl;
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it)
    cout << *it << ' ';
  return 0;
}
