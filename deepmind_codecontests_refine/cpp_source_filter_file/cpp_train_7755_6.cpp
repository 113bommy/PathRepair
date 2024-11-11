#include <bits/stdc++.h>
using namespace std;
namespace Acc {
const int N = 30;
int v[N][3], r = -1, p1, p2, st[N], tp, n, m;
char ch[3] = {'L', 'M', 'W'};
map<pair<int, int>, pair<int, int>> mp;
void dfs1(int d, int a, int b, int c, int path) {
  if (d == m + 1) {
    pair<int, int> x = {a - b, a - c}, y = {a, path};
    if (!mp.count(x))
      mp[x] = y;
    else if (mp[x].first < a)
      mp[x] = y;
    return;
  }
  dfs1(d + 1, a, b + v[d][1], c + v[d][2], path * 3);
  dfs1(d + 1, a + v[d][0], b, c + v[d][2], path * 3 + 1);
  dfs1(d + 1, a + v[d][0], b + v[d][1], c, path * 3 + 2);
}
void dfs2(int d, int x, int y, int z, int path) {
  if (d == n + 1) {
    pair<int, int> a = {y - x, z - x};
    int b;
    if (mp.count(a) && r < (b = mp[a].first + x))
      r = b, p1 = mp[a].second, p2 = path;
    return;
  }
  dfs2(d + 1, x, y + v[d][1], z + v[d][2], path * 3);
  dfs2(d + 1, x + v[d][0], y, z + v[d][2], path * 3 + 1);
  dfs2(d + 1, x + v[d][0], y + v[d][1], z, path * 3 + 2);
}
void work() {
  cin >> n, m = n >> 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 3; j++) cin >> v[i][j];
  dfs1(1, 0, 0, 0, 0), dfs2(m + 1, 0, 0, 0, 0);
  if (r == -1) puts("Impossible"), exit(0);
  for (int i = m + 1; i <= n; i++, p2 /= 3) st[++tp] = p2 % 3;
  for (int i = 1; i <= m; i++, p1 /= 3) st[++tp] = p1 % 3;
  for (; tp; puts(""), tp--)
    for (int j = 0; j < 3; j++)
      if (j != st[tp]) putchar(ch[j]);
}
}  // namespace Acc
int main() { return Acc::work(), 0; }
