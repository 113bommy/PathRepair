#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
int n;
vector<vector<pair<int, int> > > g;
int f[1 << 17];
int f2[1 << 17];
unsigned long long ans[1 << 17];
inline int lucky(int x) {
  if (!x) return 0;
  while (x) {
    int y = x % 10;
    if (y != 4 && y != 7) return 0;
    x /= 10;
  }
  return 1;
}
inline void init() {
  memset(ans, 0, sizeof ans);
  memset(f, -1, sizeof f);
  memset(f2, -1, sizeof f2);
  scanf("%d", &n);
  g.resize(n);
  int x, y, z;
  for (int i = 1; i < n; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    --x, --y;
    z = lucky(z);
    g[x].push_back(pair<int, int>(y, z));
    g[y].push_back(pair<int, int>(x, z));
  }
}
int rec(int x, int p) {
  if (f[x] != -1) return f[x];
  int res = 1;
  int k = (int)g[x].size();
  for (int i = 0; i < k; ++i) {
    int y = g[x][i].first;
    if (y == p) continue;
    res += rec(y, x);
  }
  return f[x] = res;
}
int rec2(int x, int p) {
  if (f2[x] != -1) return f2[x];
  int res = 0;
  int k = (int)g[x].size();
  for (int i = 0; i < k; ++i) {
    int y = g[x][i].first;
    if (y == p) continue;
    if (g[x][i].second)
      res += rec(y, x);
    else
      res += rec2(y, x);
  }
  return f2[x] = res;
}
void dfs(int x, int p, int res, int use) {
  int k = (int)g[x].size();
  int reserv = 1 + res;
  int useful = use;
  for (int i = 0; i < k; ++i) {
    int y = g[x][i].first;
    if (y == p) continue;
    if (g[x][i].second) {
      useful += rec(y, x);
    } else {
      reserv += rec(y, x) - rec2(y, x);
      useful += rec2(y, x);
    }
  }
  for (int i = 0; i < k; ++i) {
    int y = g[x][i].first;
    if (y == p) continue;
    if (g[x][i].second)
      dfs(y, x, 0, reserv + useful - rec(y, x));
    else
      dfs(y, x, reserv - (rec(y, x) - rec2(y, x)), useful - rec2(y, x));
  }
  ans[x] = (unsigned long long)useful;
}
int main() {
  init();
  dfs(0, -1, 0, 0);
  unsigned long long res = 0;
  for (int i = 0; i < n; ++i) {
    res += ans[i] * (ans[i] - 1);
  }
  cout << res << endl;
  return 0;
}
