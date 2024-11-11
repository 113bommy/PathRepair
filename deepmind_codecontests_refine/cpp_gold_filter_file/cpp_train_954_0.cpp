#include <bits/stdc++.h>
using namespace std;
const int N = 2000000;
int n, k, w;
vector<int> g[N];
int c[N], h[N], p[N];
vector<int> v, nv;
set<int> s;
bool ok;
void dfs_for_2(int v, int p) {
  for (auto to : g[v]) {
    if (to == p) continue;
    c[to] = !c[v];
    dfs_for_2(to, v);
  }
}
pair<int, int> dfs1(int v = 0, int p = -1, int h = 0) {
  pair<int, int> tmp = {h, v};
  for (auto to : g[v]) {
    if (to == p) continue;
    tmp = max(tmp, dfs1(to, v, h + 1));
  }
  return tmp;
}
void dfs2(int v, int pr = -1) {
  p[v] = pr;
  for (auto to : g[v]) {
    if (to == pr) continue;
    h[to] = h[v] + 1;
    dfs2(to, v);
  }
}
pair<int, int> d1(int v, int col, int p = -1, int h = 0) {
  c[v] = col;
  int mx1 = 0, mx2 = 0;
  for (auto to : g[v]) {
    if (to == p || s.count(to) == 1) continue;
    pair<int, int> q = d1(to, col - 1, v, h + 1);
    q.first++;
    q.second++;
    if (q.first > mx1) {
      mx2 = mx1;
      mx1 = q.first;
    }
    if (q.second > mx2) {
      mx2 = q.second;
    }
  }
  return {mx1, mx2};
}
pair<int, int> d2(int v, int col, int p = -1, int h = 0) {
  c[v] = col;
  int mx1 = 0, mx2 = 0;
  for (auto to : g[v]) {
    if (to == p || s.count(to) == 1) continue;
    pair<int, int> q = d2(to, col + 1, v, h + 1);
    q.first++;
    q.second++;
    if (q.first > mx1) {
      mx2 = mx1;
      mx1 = q.first;
    }
    if (q.second > mx2) {
      mx2 = q.second;
    }
  }
  return {mx1, mx2};
}
int main() {
  cin >> n >> k;
  w = 1;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  if (k == 2) {
    cout << "Yes\n";
    if (w) {
      dfs_for_2(0, -1);
      for (int i = 0; i < n; i++) {
        cout << c[i] + 1 << ' ';
      }
    }
    return 0;
  }
  dfs2(dfs1().second);
  int mxn = 0;
  for (int i = 0; i < n; i++) {
    if (h[i] > h[mxn]) mxn = i;
  }
  while (mxn != -1) {
    v.push_back(mxn);
    s.insert(mxn);
    mxn = p[mxn];
  }
  if (v.size() < k) {
    cout << "Yes\n";
    if (w) {
      for (int i = 0; i < n; i++) {
        cout << 1 << ' ';
      }
    }
    return 0;
  }
  nv.resize((int)v.size());
  for (int i = 0; i < v.size(); i++) {
    c[v[i]] = i;
  }
  int tmp = k - 2;
  for (int i = 0; i < (int)v.size() / 2; i++) {
    nv[i] = min(tmp, i);
    if (tmp > 0) tmp--;
    ok = 1;
    pair<int, int> w = d1(v[i], c[v[i]]);
    if (!ok || w.first > nv[i]) {
      cout << "No";
      return 0;
    }
  }
  tmp = k - 2;
  for (int i = (int)v.size() - 1; i >= (int)v.size() / 2; i--) {
    nv[i] = min(tmp, (int)v.size() - i - 1);
    if (tmp > 0) tmp--;
    ok = 1;
    pair<int, int> w = d2(v[i], c[v[i]]);
    if (!ok || w.first > nv[i]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes\n";
  if (w) {
    for (int i = 0; i < n; i++) {
      if (c[i] < 0) return 228;
      cout << c[i] % k + 1 << ' ';
    }
  }
  return 0;
}
