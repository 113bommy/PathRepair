#include <bits/stdc++.h>
using namespace std;
int n;
pair<long long, long long> pos[2010];
map<char, pair<int, int>> dir = {
    {'L', {-1, 0}}, {'R', {1, 0}}, {'U', {0, -1}}, {'D', {0, 1}}};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool blocked[2010][2010] = {0}, vis[2010][2010] = {0};
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  pos[0] = {((long long)5e9), ((long long)5e9)};
  vector<long long> xvals, yvals;
  for (int i = 0; i++ < n;) {
    char d;
    long long dis;
    cin >> d >> dis;
    pos[i].first = pos[i - 1].first + dir[d].first * dis;
    pos[i].second = pos[i - 1].second + dir[d].second * dis;
  }
  for (int i = -1; ++i < n + 1;) {
    for (int f = -1; ++f < 2;) {
      xvals.push_back(pos[i].first + f);
      yvals.push_back(pos[i].second + f);
    }
  }
  xvals.push_back(-1);
  yvals.push_back(-1);
  xvals.push_back((((long long)5e9) * 2) + 1);
  yvals.push_back((((long long)5e9) * 2) + 1);
  sort(xvals.begin(), xvals.end());
  sort(yvals.begin(), yvals.end());
  xvals.resize(unique(xvals.begin(), xvals.end()) - xvals.begin());
  yvals.resize(unique(yvals.begin(), yvals.end()) - yvals.begin());
  for (int i = -1; ++i < n + 1;) {
    pos[i].first =
        lower_bound(xvals.begin(), xvals.end(), pos[i].first) - xvals.begin();
    pos[i].second =
        lower_bound(yvals.begin(), yvals.end(), pos[i].second) - yvals.begin();
  }
  for (int i = 0; i++ < n;) {
    long long from_x = min(pos[i - 1].first, pos[i].first),
              to_x = max(pos[i - 1].first, pos[i].first);
    long long from_y = min(pos[i - 1].second, pos[i].second),
              to_y = max(pos[i - 1].second, pos[i].second);
    for (long long u = from_x; u <= to_x; ++u)
      for (long long v = from_y; v <= to_y; ++v) blocked[u][v] = 1;
  }
  queue<tuple<int, int>> qu;
  vis[0][0] = 1;
  for (qu.push({0, 0}); ((int)qu.size()); qu.pop()) {
    int x, y;
    tie(x, y) = qu.front();
    for (int i = -1; ++i < 4;) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= 2010 || ny >= 2010) continue;
      if (vis[nx][ny] || blocked[nx][ny]) continue;
      vis[nx][ny] = 1;
      qu.push({nx, ny});
    }
  }
  long long ans = 0;
  for (int i = -1; ++i < 2010;)
    for (int f = -1; ++f < 2010;) {
      if (vis[i][f]) continue;
      ans += 1ll * (xvals[i + 1] - xvals[i]) * (yvals[f + 1] - yvals[f]);
    }
  cout << ans;
  return 0;
}
