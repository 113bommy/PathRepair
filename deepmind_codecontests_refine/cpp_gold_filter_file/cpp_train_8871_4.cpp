#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> > g;
vector<int> used;
vector<int> wss;
int cst = 0;
bool fff = 0;
bool dfs1(int sp, int prev = -1) {
  used[sp] = 1;
  bool rv = 0;
  for (int i = 0; i < int(g[sp].size()); ++i) {
    int cur = g[sp][i];
    if (cur == prev || wss[cur] == 0) {
      continue;
    }
    if (used[cur]) {
      wss[sp] = 0;
      wss[cur] = 0;
      fff = true;
      return true;
    } else if (!used[cur]) {
      int rvv = dfs1(cur, sp);
      rv |= rvv;
    }
  }
  if (rv) {
    if (wss[sp] == 0) {
      return false;
    }
    wss[sp] = 0;
    return true;
  }
  return false;
}
int dfs3(int sp, int pr) {
  if (wss[sp] != -1) {
    return wss[sp];
  }
  for (int i = 0; i < int(g[sp].size()); ++i) {
    int cur = g[sp][i];
    if (cur == pr) {
      continue;
    }
    int prev = dfs3(cur, sp);
    if (prev == -1) {
      continue;
    }
    wss[sp] = prev + 1;
    return wss[sp];
  }
  return -1;
}
int main() {
  cin >> n;
  g = vector<vector<int> >(n);
  for (int i = 0; i < int(n); ++i) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  used = vector<int>(n);
  wss = vector<int>(n, -1);
  dfs1(0);
  for (int i = 0; i < int(n); ++i) {
    dfs3(i, -1);
  }
  for (int i = 0; i < int(n); ++i) cout << wss[i] << " ";
  cout << endl;
}
