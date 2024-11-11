#include <bits/stdc++.h>
using namespace std;
const long long P = 1e9 + 7;
const int N = 1005;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(time(0));
long long n, x[N], y[N];
vector<int> g[N];
int group[N];
unordered_map<int, vector<int>> hlines, vlines;
unordered_map<int, unordered_map<int, int>> ids;
void dfs(int x, int cnt) {
  group[x] = cnt;
  for (auto u : g[x])
    if (!group[u]) dfs(u, cnt);
}
bool ok(int dist, int d1, int d2, int d3, int g1, int g2, int g3) {
  if (g1 == g2 || g1 == g3 || g2 == g3) return false;
  if (abs(d1) > dist || abs(d2) > dist || abs(d3) > dist) return false;
  return true;
}
bool check(long long dist) {
  for (int i = (1); i <= (n); ++i) g[i].clear();
  for (int i = (1); i <= (n); ++i)
    for (int j = (i + 1); j <= (n); ++j) {
      if (x[i] == x[j] && abs(y[i] - y[j]) <= dist ||
          y[i] == y[j] && abs(x[i] - x[j]) <= dist) {
        g[i].push_back(j), g[j].push_back(i);
      }
    }
  memset(group, 0, sizeof group);
  int cnt = 0;
  for (int i = (1); i <= (n); ++i)
    if (!group[i]) {
      cnt++;
      dfs(i, cnt);
    }
  if (cnt == 1) return true;
  if (cnt == 2) {
    for (int i = (1); i <= (n); ++i) {
      for (int j = (i + 1); j <= (n); ++j)
        if (group[i] != group[j]) {
          if (x[i] == x[j] && abs(y[i] - y[j]) <= dist * 2ll)
            return true;
          else if (y[i] == y[j] && abs(x[i] - x[j]) <= dist * 2ll)
            return true;
          else if (abs(x[i] - x[j]) <= dist && abs(y[i] - y[j]) <= dist)
            return true;
        }
    }
  }
  if (cnt == 3 || cnt == 4) {
    int x0, y1, sz1, sz2;
    for (auto ele1 : vlines) {
      vector<int> ptv = ele1.second;
      for (auto ele2 : hlines) {
        vector<int> pth = ele2.second;
        x0 = ele1.first, y1 = ele2.first;
        sz1 = ptv.size(), sz2 = pth.size();
        int i = lower_bound(ptv.begin(), ptv.end(), y1) - ptv.begin(),
            j = lower_bound(pth.begin(), pth.end(), x0) - pth.begin();
        int gp1, gp2, gp3, gp4, y00, y01, x10, x11;
        if (cnt == 4) {
          if (i == 0 || i == sz1 || j == 0 || j == sz2) continue;
          y00 = ptv[i - 1], y01 = ptv[i], x10 = pth[j - 1], x11 = pth[j];
          gp1 = group[ids[x0][y00]], gp2 = group[ids[x0][y01]],
          gp3 = group[ids[x10][y1]], gp4 = group[ids[x11][y1]];
          if (gp1 != gp2 && gp1 != gp3 && gp1 != gp4 && gp2 != gp3 &&
              gp2 != gp4 && gp3 != gp4) {
            if (abs(y00 - y1) <= dist && abs(y01 - y1) <= dist &&
                abs(x10 - x0) <= dist && abs(x11 - x0) <= dist)
              return true;
          }
        } else {
          bool f1, f2, f3, f4;
          f1 = i > 0 && i < sz1 && j > 0;
          f2 = i > 0 && i < sz1 && j < sz2;
          f3 = i > 0 && j > 0 && j < sz2;
          f4 = i < sz1 && j > 0 && j < sz2;
          y00 = i > 0 ? ptv[i - 1] : 0, y01 = i < sz1 ? ptv[i] : 0,
          x10 = j > 0 ? pth[j - 1] : 0, x11 = j < sz2 ? pth[j] : 0;
          gp1 = group[ids[x0][y00]], gp2 = group[ids[x0][y01]],
          gp3 = group[ids[x10][y1]], gp4 = group[ids[x11][y1]];
          if (f1 && ok(dist, y00 - y1, y01 - y1, x10 - x0, gp1, gp2, gp3) ||
              f2 && ok(dist, y00 - y1, y01 - y1, x11 - x0, gp1, gp2, gp4) ||
              f3 && ok(dist, y00 - y1, x10 - x0, x11 - x0, gp1, gp3, gp4) ||
              f4 && ok(dist, y01 - y1, x10 - x0, x11 - x0, gp2, gp3, gp4))
            return true;
        }
      }
    }
  }
  return false;
}
int main() {
  cin >> n;
  for (int i = (1); i <= (n); ++i) {
    cin >> x[i] >> y[i];
    vlines[x[i]].push_back(y[i]);
    hlines[y[i]].push_back(x[i]);
    ids[x[i]][y[i]] = i;
  }
  for (auto &ele : hlines) {
    vector<int> &tmp = ele.second;
    sort(tmp.begin(), tmp.end());
  }
  for (auto &ele : vlines) {
    vector<int> &tmp = ele.second;
    sort(tmp.begin(), tmp.end());
  }
  long long l = 1, r = 2e9 + 7, t = r;
  while (l <= r) {
    long long mid = l + r >> 1;
    if (check(mid))
      t = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  if (t == 2e9 + 7)
    cout << -1;
  else
    cout << t;
  return 0;
}
