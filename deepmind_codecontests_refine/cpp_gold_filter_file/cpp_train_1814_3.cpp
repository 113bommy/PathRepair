#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
string inp[20];
char bombs[20][20];
vector<pair<int, int> > bomIndex;
vector<pair<int, int> > trsIndex;
int dist[20][20][1 << 8][1 << 8];
int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};
vector<int> tresVal;
int slope_den = 100, slope_num = 99;
bool Intersect(pair<int, int> src, pair<int, int> a, pair<int, int> b) {
  if (!(src.first <= min(a.first, b.first))) return 0;
  long long aa = 100LL * (a.second - src.second) - 99LL * (a.first - src.first);
  long long bb = 100LL * (b.second - src.second) - 99LL * (b.first - src.first);
  if (aa * bb < 0) return 1;
  return 0;
}
int getTresval(int ts, int t) {
  int val = 0;
  for (int i = 0; i < t; ++i) {
    if (ts & (1 << i)) val += tresVal[i];
  }
  return val;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < (n); ++i) cin >> inp[i];
  pair<int, int> Start;
  int b = 0, t = 0;
  trsIndex.resize(8);
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j) {
      if (inp[i][j] == 'S') Start = {i, j};
      if (inp[i][j] == 'B') {
        bomIndex.push_back({i, j});
        bombs[i][j] = b++;
      }
      if (inp[i][j] >= '1' and inp[i][j] <= '8') {
        inp[i][j] -= '1';
        trsIndex[inp[i][j]] = {i, j};
        t += 1;
      }
    }
  for (int i = 0; i < t; ++i) {
    int xx;
    cin >> xx;
    tresVal.push_back(xx);
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      for (int k = 0; k < (1 << b); ++k)
        for (int l = 0; l < (1 << t); ++l) dist[i][j][k][l] = MOD;
  queue<pair<pair<int, int>, pair<int, int> > > Q;
  dist[Start.first][Start.second][0][0] = 0;
  Q.push({Start, {0, 0}});
  while (!Q.empty()) {
    pair<pair<int, int>, pair<int, int> > v = Q.front();
    Q.pop();
    int x = v.first.first, y = v.first.second, bs = v.second.first,
        ts = v.second.second;
    for (int i = 0; i < 4; ++i) {
      int cx = x + dx[i];
      int cy = y + dy[i];
      if (cx < 0 || cx >= n) continue;
      if (cy < 0 || cy >= m) continue;
      if (inp[cx][cy] == 'B' || inp[cx][cy] == '#' ||
          (inp[cx][cy] >= 0 and inp[cx][cy] < 8))
        continue;
      int cbs = bs;
      int cts = ts;
      for (int j = 0; j < b; ++j) {
        if (Intersect(bomIndex[j], v.first, {cx, cy})) cbs ^= (1 << j);
      }
      for (int j = 0; j < t; ++j) {
        if (Intersect(trsIndex[j], v.first, {cx, cy})) cts ^= (1 << j);
      }
      if (dist[cx][cy][cbs][cts] > dist[x][y][bs][ts] + 1) {
        dist[cx][cy][cbs][cts] = dist[x][y][bs][ts] + 1;
        Q.push({{cx, cy}, {cbs, cts}});
      }
    }
  }
  int ans = -MOD;
  for (int i = 0; i < (1 << t); ++i) {
    ans = max(ans, getTresval(i, t) - dist[Start.first][Start.second][0][i]);
  }
  cout << ans << endl;
  return 0;
}
