#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 9, lg = 19, MOD = 1e9 + 7, maxV = 1e6 + 9;
pair<int, int> arr[3];
int dp[maxN][maxN];
pair<int, int> auxi[maxN][maxN];
bool vi[maxN][maxN];
int dst(pair<int, int> one, pair<int, int> two) {
  return abs(one.first - two.first) + abs(two.second - one.second);
}
const int dr[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool ins(int x, int y) { return x < maxN && y < maxN && y >= 0 && x >= 0; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n = 3;
  for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
  pair<int, int> begi = pair<int, int>(min(arr[0].first, arr[1].first),
                                       min(arr[0].second, arr[1].second));
  pair<int, int> ende = pair<int, int>(max(arr[0].first, arr[1].first),
                                       max(arr[0].second, arr[1].second));
  pair<int, int> clos = begi;
  for (int i = begi.first; i <= ende.first; i++) {
    for (int j = begi.second; j <= ende.second; j++) {
      if (dst(arr[2], clos) > dst(arr[2], pair<int, int>(i, j))) {
        clos = pair<int, int>(i, j);
      }
    }
  }
  queue<pair<int, int> > q;
  q.push(clos);
  memset(dp, -1, sizeof dp);
  dp[clos.first][clos.second] = 0;
  auxi[clos.first][clos.second] = pair<int, int>(-1, -1);
  while (q.size()) {
    pair<int, int> cr = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int x = cr.first + dr[i][0], y = cr.second + dr[i][1];
      if (!ins(x, y) || dp[x][y] != -1) continue;
      dp[x][y] = dp[cr.first][cr.second] + 1;
      auxi[x][y] = cr;
      q.push(pair<int, int>(x, y));
    }
  }
  for (int i = 0; i < 3; i++) {
    pair<int, int> strt = arr[i];
    while (strt != pair<int, int>(-1, -1)) {
      vi[strt.first][strt.second] = 1;
      strt = auxi[strt.first][strt.second];
    }
  }
  vector<pair<int, int> > ans;
  for (int i = 0; i < maxN; i++)
    for (int j = 0; j < maxN; j++)
      if (vi[i][j]) ans.push_back(pair<int, int>(i, j));
  cout << ans.size() << '\n';
  for (pair<int, int> el : ans) cout << el.first << ' ' << el.second << '\n';
}
