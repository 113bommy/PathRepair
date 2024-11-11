#include <bits/stdc++.h>
using namespace std;
int n, t;
int m[2];
int p[2][1000010];
int d[2][6500000];
pair<int, int> par[2][6500000];
vector<int> ord;
set<int> q;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m[0] >> m[1] >> t;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < m[i]; j++) {
      cin >> p[i][j];
      ord.push_back(p[i][j] - 1);
      ord.push_back(p[i][j]);
      ord.push_back(p[i][j] + 1);
    }
  }
  ord.push_back(0);
  ord.push_back(n + 1);
  sort(ord.begin(), ord.end());
  vector<int> tmp(1, 0);
  for (int i = 1; i < (int)ord.size(); i++) {
    if (ord[i] != ord[i - 1]) tmp.push_back(ord[i]);
  }
  ord = tmp;
  int pointer[2] = {};
  memset(d, -1, sizeof(d));
  d[0][0] = 0;
  par[0][0] = {-1, -1};
  d[1][0] = 0;
  par[1][0] = {0, 0};
  for (int i = 1; i < (int)ord.size(); i++) {
    int pos = ord[i];
    bool wall[2] = {};
    for (int j = 0; j < 2; j++) {
      while (pointer[j] < m[j] && p[j][pointer[j]] < pos) pointer[j]++;
      if (pointer[j] < m[j] && p[j][pointer[j]] == pos) wall[j] = true;
    }
    int prev = ord[i - 1];
    for (int j = 0; j < 2; j++) {
      if (d[j][i - 1] == -1) continue;
      int val = d[j][i - 1] + pos - prev;
      if (!wall[j]) {
        d[j][i] = val;
        par[j][i] = {j, i - 1};
      } else if (val - t >= 1) {
        d[j][i] = val - t;
        par[j][i] = {j, i - 1};
      }
    }
    int v[2] = {d[0][i], d[1][i]};
    for (int j = 0; j < 2; j++) {
      if (v[1 - j] == -1 || wall[j]) continue;
      if (d[j][i] < min(t, v[1 - j])) {
        d[j][i] = min(t, v[1 - j]);
        par[j][i] = {1 - j, i};
      }
    }
  }
  vector<int> path;
  pair<int, int> v;
  int r = ord.size();
  if (d[0][r - 1] == -1 && d[1][r - 1] == -1)
    cout << "No" << endl;
  else {
    if (d[0][r - 1] != -1)
      v = {0, r - 1};
    else
      v = {1, r - 1};
    vector<pair<int, int>> fullpath;
    for (;;) {
      fullpath.push_back(v);
      if (par[v.first][v.second] == make_pair(-1, -1)) break;
      auto pr = par[v.first][v.second];
      if (v.first != pr.first) path.push_back(v.second);
      v = pr;
    }
    reverse(path.begin(), path.end());
    reverse(fullpath.begin(), fullpath.end());
    int k = fullpath.size();
    vector<pair<int, int>> sh;
    for (int i = 0; i < k; i++) {
      int j = i;
      while (j < k && fullpath[i].first == fullpath[j].first) j++;
      j--;
      int y = fullpath[i].first;
      int left = ord[fullpath[i].second], right = ord[fullpath[j].second];
      int lo = 0, hi = m[y];
      while (lo != hi) {
        int mi = (lo + hi) >> 1;
        if (p[y][mi] < left)
          lo = mi + 1;
        else
          hi = mi;
      }
      if (lo < m[y]) {
        int have = d[y][fullpath[i].second];
        int start = left + t - have;
        int need = 0;
        for (int j = lo; j < m[y]; j++) {
          if (left <= p[y][j] && p[y][j] <= right) need++;
          if (p[y][j] > right) break;
        }
        for (int j = 0; j < need; j++) {
          sh.push_back({start, y});
          start += t;
        }
      }
      i = j;
    }
    cout << "Yes" << endl;
    cout << path.size() << endl;
    for (auto u : path) cout << ord[u] << ' ';
    cout << endl;
    cout << sh.size() << endl;
    for (auto u : sh) cout << u.first << ' ' << u.second + 1 << '\n';
  }
}
