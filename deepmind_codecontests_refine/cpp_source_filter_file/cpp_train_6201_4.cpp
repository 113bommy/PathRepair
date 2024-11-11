#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const long long int inf = 1e18;
const long long int N = 1e5 + 5;
void HyperBeast() {
  long long int n, m, k;
  cin >> n >> m >> k;
  vector<pair<long long int, long long int> > v(k);
  for (auto &i : v) {
    cin >> i.first >> i.second;
  }
  vector<pair<long long int, long long int> > path;
  path.push_back({0, 0});
  bool up = 1;
  long long int dx = 1, dy = 1;
  while (true) {
    if (dx == 1 and dy == 1) {
      long long int x = path.back().first;
      long long int y = path.back().second;
      long long int nx1, ny1, nx2, ny2;
      nx1 = n;
      ny2 = m;
      ny1 = y + dy * ((nx1 - x) / dx);
      nx2 = x + dx * ((ny2 - y) / dy);
      if (nx2 < nx1) {
        dx = 1, dy = -1;
        path.push_back({nx2, ny2});
      } else {
        dx = -1, dy = 1;
        path.push_back({nx1, ny1});
      }
      if (ny1 == m or nx2 == n) break;
    }
    if (dx == -1 and dy == 1) {
      long long int x = path.back().first;
      long long int y = path.back().second;
      long long int nx1, ny1, nx2, ny2;
      nx1 = 0;
      ny2 = m;
      ny1 = y + dy * ((nx1 - x) / dx);
      nx2 = x + dx * ((ny2 - y) / dy);
      if (nx2 > nx1) {
        dx = -1, dy = -1;
        path.push_back({nx2, ny2});
      } else {
        dx = 1, dy = 1;
        path.push_back({nx1, ny1});
      }
      if (ny1 == m or nx2 == 0) break;
    }
    if (dx == -1 and dy == -1) {
      long long int x = path.back().first;
      long long int y = path.back().second;
      long long int nx1, ny1, nx2, ny2;
      nx1 = 0;
      ny2 = 0;
      ny1 = y + dy * ((nx1 - x) / dx);
      nx2 = x + dx * ((ny2 - y) / dy);
      if (nx2 > nx1) {
        dx = -1, dy = 1;
        path.push_back({nx2, ny2});
      } else {
        dx = 1, dy = -1;
        path.push_back({nx1, ny1});
      }
      if (ny1 == 0 or nx2 == 0) break;
    }
    if (dx == 1 and dy == -1) {
      long long int x = path.back().first;
      long long int y = path.back().second;
      long long int nx1, ny1, nx2, ny2;
      nx1 = n;
      ny2 = 0;
      ny1 = y + dy * ((nx1 - x) / dx);
      nx2 = x + dx * ((ny2 - y) / dy);
      if (nx2 < nx1) {
        dx = 1, dy = 1;
        path.push_back({nx2, ny2});
      } else {
        dx = -1, dy = -1;
        path.push_back({nx1, ny1});
      }
      if (ny1 == 0) break;
    }
  }
  vector<long long int> pref((long long int)((path).size()), 0);
  map<pair<pair<long long int, long long int>,
           pair<long long int, long long int> >,
      long long int>
      mp;
  for (long long int i = 1; i < (long long int)((path).size()); i++) {
    mp[{{path[i - 1].first, path[i - 1].second},
        {path[i].first, path[i].second}}] = i;
    pref[i] = abs(path[i].first - path[i - 1].first) + pref[i - 1];
  }
  for (long long int i = 0; i < k; i++) {
    long long int x = v[i].first;
    long long int y = v[i].second;
    long long int x1, y1, x2, y2;
    x1 = 0, y2 = 0;
    long long int tx = -1, ty = -1;
    y1 = y + ty * ((x1 - x) / tx);
    x2 = x + tx * ((y1 - y) / ty);
    long long int fx = x1, fy = y1;
    if (x2 > x1) {
      fx = x2;
      fy = y2;
    }
    x1 = n, y2 = m;
    tx = 1, ty = 1;
    y1 = y + ty * ((x1 - x) / tx);
    x2 = x + tx * ((y2 - y) / ty);
    long long int gx = x1, gy = y1;
    if (x2 < x1) {
      gx = x2;
      gy = y2;
    }
    long long int ans = inf;
    if (mp.count({{fx, fy}, {gx, gy}})) {
      long long int tmp = mp[{{fx, fy}, {gx, gy}}];
      ans = min(ans, pref[tmp - 1] + (x - fx));
    }
    if (mp.count({{gx, gy}, {fx, fy}})) {
      long long int tmp = mp[{{gx, gy}, {fx, fy}}];
      ans = min(ans, pref[tmp - 1] + (gx - x));
    }
    x1 = 0, y2 = m;
    tx = -1, ty = 1;
    y1 = y + ty * ((x1 - x) / tx);
    x2 = x + tx * ((y2 - y) / ty);
    fx = x1, fy = y1;
    if (x2 > x1) {
      fx = x2, fy = y2;
    }
    x1 = n, y2 = 0;
    tx = 1, ty = -1;
    y1 = y + ty * ((x1 - x) / tx);
    x2 = x + tx * ((y2 - y) / ty);
    gx = x1, gy = y1;
    if (x2 < x1) {
      gx = x2, gy = y2;
    }
    if (mp.count({{fx, fy}, {gx, gy}})) {
      long long int tmp = mp[{{fx, fy}, {gx, gy}}];
      ans = min(ans, pref[tmp - 1] + (x - fx));
    }
    if (mp.count({{gx, gy}, {fx, fy}})) {
      long long int tmp = mp[{{gx, gy}, {fx, fy}}];
      ans = min(ans, pref[tmp - 1] + (gx - x));
    }
    if (ans == inf) ans = -1;
    cout << ans << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T = 1;
  while (T--) {
    HyperBeast();
    cout << '\n';
  }
}
