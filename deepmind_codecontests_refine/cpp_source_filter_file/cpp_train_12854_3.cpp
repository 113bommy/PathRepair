#include <bits/stdc++.h>
using namespace std;
int a, s, d[2002], f[2002], g[2002], h, j, k, l, i, n, m, r;
vector<pair<int, int> > v[2002];
vector<int> v1[2002];
int dfs(int idx, int par, int pre) {
  if (d[idx]) return d[idx];
  d[idx] = ++k;
  int ret = k;
  for (int i = 0; i < v[idx].size(); i++) {
    if (v[idx][i].second == par) continue;
    int l = dfs(v[idx][i].first, v[idx][i].second, idx);
    if (l > d[idx]) {
      v[idx][i].first *= -1;
    }
    ret = min(ret, l);
  }
  d[idx] = ret;
  if (ret > d[pre]) {
    for (int i = 0; i < v[idx].size(); i++)
      if (v[idx][i].first == pre) {
        v[idx][i].first *= -1;
        break;
      }
  }
  return ret;
}
void df1(int idx, int zn, int par) {
  if (f[idx]) {
    if (f[idx] != zn) v1[zn].push_back(f[idx]);
    return;
  }
  f[idx] = zn;
  int ret = k;
  for (int i = 0; i < v[idx].size(); i++) {
    if (abs(v[idx][i].first) == par) continue;
    if (v[idx][i].first < 0) {
      j++;
      int y = j;
      df1(-v[idx][i].first, j, idx);
      v1[zn].push_back(y);
      v1[y].push_back(zn);
    } else
      df1(v[idx][i].first, zn, idx);
  }
  return;
}
int df2(int idx, int par) {
  if (v1[idx].size() == 1) return 0;
  int ret = 0, r1 = 0;
  for (auto it : v1[idx]) {
    if (it == par) continue;
    int y = df2(it, idx);
    ret = max(ret, y);
  }
  return ret + 1;
}
int main() {
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> a >> s;
    v[a].push_back({s, i});
    v[s].push_back({a, i});
  }
  for (i = 1; i <= n; i++) {
    if (!d[i]) {
      l++;
      dfs(i, -1, -1);
      h = j + 1;
      df1(i, ++j, 0);
      k = 0;
      int k1 = 0;
      for (; h <= j; h++) {
        if (v[h].size() == 1) k++;
        int y = df2(h, 0);
        k1 = max(k1, y);
      }
      r += k + k1;
    }
  }
  cout << n - r + l - 1;
}
