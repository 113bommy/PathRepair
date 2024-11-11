#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
const long long mod = 1e9 + 7;
int mk[N];
vector<int> g[N];
map<int, int> xx, yy;
bool iscir;
long long res, ans;
int cnt, n;
void dfs(int x, int f, int tmp) {
  mk[x] = tmp;
  res = (res * 2) % mod;
  for (int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if (y == f) continue;
    if (!mk[y])
      dfs(y, x, tmp);
    else if (mk[y] == tmp)
      iscir = 1;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x1, y1; i <= n; ++i) {
    scanf("%d%d", &x1, &y1);
    int &x = xx[x1], &y = yy[y1];
    if (!x) x = ++cnt;
    if (!y) y = ++cnt;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  long long ans = 1;
  for (int i = 1; i <= cnt; ++i) {
    if (!mk[i]) {
      res = 1;
      iscir = 0;
      dfs(i, -1, i);
      if (!iscir) res = (res - 1 + mod) % mod;
      ans = ans * res % mod;
    }
  }
  cout << ans;
}
