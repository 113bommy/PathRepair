#include <bits/stdc++.h>
using namespace std;
char a[3333][3333];
char used[3333];
int min_e[3333];
int sel_e[3333];
int n, m;
int prima(void) {
  const int INF = 1000000000;
  memset(used, 0, sizeof(used));
  for (int i = 0; i < n; i++) {
    min_e[i] = INF;
    sel_e[i] = -1;
  }
  min_e[0] = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int v = -1;
    for (int j = 0; j < n; ++j)
      if (!used[j] && (v == -1 || min_e[j] < min_e[v])) v = j;
    used[v] = true;
    ans += a[v][sel_e[v]];
    for (int to = 0; to < n; ++to)
      if (a[v][to] < min_e[to]) {
        min_e[to] = a[v][to];
        sel_e[to] = v;
      }
  }
  return ans;
}
vector<int> vv[1111111];
vector<int> vv2[1111111];
vector<int> pv;
char pvv[1111111];
char used2[1111111];
int cnt = 0;
void dfs(int v) {
  used2[v] = 1;
  if (!pvv[v]) return;
  for (auto t : vv2[v])
    if (pvv[t] && !used2[t]) {
      dfs(t);
    }
}
int main() {
  scanf("%i%i", &n, &m);
  if (n > 3000) {
    for (int i = 0; i < m; i++) {
      int x, y;
      scanf("%i%i", &x, &y);
      x--;
      y--;
      vv[x].push_back(y);
      vv[y].push_back(x);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (vv[i].size() >= n / 2) {
        pv.push_back(i);
        sort(vv[i].begin(), vv[i].end());
        int x = 0;
        for (int j = 0; j < n; j++) {
          while (x < vv[i].size() - 1 && vv[i][x] < j) x++;
          if (vv[i][x] != j) vv2[i].push_back(j);
        }
        pvv[i] = 1;
      }
    }
    for (int kk = 0; kk < 200; kk++) {
      for (int i = 0; i < pv.size(); i++) {
        int v = pv[i];
        if (!pvv[v]) continue;
        for (auto t : vv2[v])
          if (!pvv[t]) {
            pvv[v] = 0;
            break;
          }
      }
    }
    for (int i = 0; i < pv.size(); i++) {
      int v = pv[i];
      if (!pvv[v]) continue;
      if (!used2[v]) {
        ans++;
        dfs(v);
      }
    }
    printf("%i\n", ans);
  } else {
    for (int i = 0; i < m; i++) {
      int x, y;
      scanf("%i%i", &x, &y);
      x--;
      y--;
      a[x][y] = 1;
      a[y][x] = 1;
    }
    printf("%i\n", prima());
  }
}
