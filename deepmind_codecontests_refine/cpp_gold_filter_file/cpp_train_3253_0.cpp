#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, x, y, l, sum, tot, ii, a[500010], hd[1000010], nt[1000010],
    e[1000010], v[500010], ans[500010];
vector<int> zh[500010];
void build(int x, int y) {
  tot++;
  e[tot] = y;
  nt[tot] = hd[x];
  hd[x] = tot;
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    build(x, y);
    build(y, x);
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    zh[a[i]].push_back(i);
  }
  for (i = 1; i <= n; i++) {
    if (!zh[i].size()) return puts("-1"), 0;
    sum += zh[i].size();
    for (j = 0; j < zh[i].size(); j++) {
      x = zh[i][j];
      ans[++ans[0]] = x;
      for (ii = hd[x]; ii; ii = nt[ii]) {
        y = e[ii];
        if (a[y] == a[x]) return puts("-1"), 0;
        if (a[y] < a[x]) v[a[y]] = 1;
      }
      l = 1;
      while (l < a[x] && v[l]) l++;
      if (l < a[x]) return puts("-1"), 0;
      for (ii = hd[x]; ii; ii = nt[ii]) {
        y = e[ii];
        if (a[y] < a[x]) v[a[y]] = 0;
      }
    }
    if (sum == n) break;
  }
  for (i = 1; i <= n; i++) printf("%d ", ans[i]);
}
