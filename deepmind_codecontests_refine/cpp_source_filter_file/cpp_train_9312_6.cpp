#include <bits/stdc++.h>
using namespace std;
int const mlen = 100100;
bool u[mlen], u1[mlen];
vector<int> g[mlen], zn[mlen];
int ans[mlen];
bool fl = 0;
void DFS1(int v, int color) {
  u1[v] = 1;
  ans[v] = color;
  for (int i = 0; i < g[v].size(); ++i)
    if (u1[g[v][i]] == 0) DFS1(g[v][i], color);
}
int t, color;
int vfl;
void DFS(int v, int cl) {
  u[v] = 1;
  ++t;
  bool wer = 1;
  for (int i = 0; i < g[v].size(); ++i) {
    if (g[v][i] == v) fl = 1, vfl = v;
    if (u[g[v][i]] == 0) wer = 0, DFS(g[v][i], zn[v][i]);
  }
  if (wer) color = cl;
}
int main() {
  int a, b, n;
  cin >> n >> a >> b;
  map<int, int> mp;
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    mp[x] = i;
    if (a - x == x) v.push_back(i);
    if (b - x == x) v.push_back(i);
  }
  for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
    pair<int, int> x = *it;
    bool fl = 1;
    if (mp.count(a - x.first))
      fl = 0, g[x.second].push_back(mp[a - x.first]), zn[x.second].push_back(0);
    if (mp.count(b - x.first))
      fl = 0, g[x.second].push_back(mp[b - x.first]), zn[x.second].push_back(1);
    if (fl) {
      cout << "NO\n";
      return 0;
    }
  }
  for (int j = 0; j < v.size(); ++j) {
    int i = v[j];
    if (u[i] == 0) {
      fl = -1;
      t = 0;
      DFS(i, zn[i][0]);
      if (t % 2 == 0) {
        DFS1(i, color);
      } else {
        if (fl) {
          for (int j = 0; j < g[vfl].size(); ++j)
            if (g[vfl][j] == vfl) color = zn[vfl][j];
          DFS1(i, color);
        } else {
          cout << "NO\n";
          return 0;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i)
    if (u[i] == 0) {
      fl = -1;
      t = 0;
      DFS(i, zn[i][0]);
      if (t % 2 == 0) {
        DFS1(i, color);
      } else {
        if (fl) {
          for (int j = 0; j < g[vfl].size(); ++j)
            if (g[vfl][j] == vfl) color = zn[vfl][j];
          DFS1(i, color);
        } else {
          cout << "NO\n";
          return 0;
        }
      }
    }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
}
