#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct ett {
  int x, y;
};
ett e[N];
bool cmp1(ett a, ett b) { return a.x < b.x || a.x == b.x && a.y < b.y; }
bool cmp2(ett a, ett b) { return a.y < b.y || a.y == b.y && a.x < b.x; }
int fa[N], b[N];
bool findfa(int x) {
  if (fa[x] == x) return x;
  fa[x] = findfa(fa[x]);
  return fa[x];
}
pair<int, int> cal1(int q, int m) {
  int i, j, k;
  sort(e + 1, e + q + 1, cmp1);
  e[0].x = e[1].x - 1;
  for (i = 1; i <= m; i++) fa[i] = i, b[i] = 0;
  for (i = 1; i <= q; i++) {
    if (e[i].x == e[i - 1].x) continue;
    int tt = e[i].y, ft = findfa(tt);
    b[tt] = 1;
    for (j = i; j <= q; j++)
      if (e[j].x > e[i].x) break;
    for (k = i + 1; k < j; k++) {
      int t = e[k].y;
      b[t] = 1;
      fa[findfa(t)] = ft;
    }
  }
  int tot1 = 0, tot2 = 0;
  for (i = 1; i <= m; i++) {
    if (!b[i]) {
      tot2++;
      continue;
    }
    if (findfa(i) == i) tot1++;
  }
  return make_pair(tot1, tot2);
}
pair<int, int> cal2(int q, int m) {
  int i, j, k;
  sort(e + 1, e + q + 1, cmp2);
  e[0].y = e[1].y - 1;
  for (i = 1; i <= m; i++) fa[i] = i, b[i] = 0;
  for (i = 1; i <= q; i++) {
    if (e[i].y == e[i - 1].y) continue;
    int tt = e[i].x, ft = findfa(tt);
    b[tt] = 1;
    for (j = i; j <= q; j++)
      if (e[j].y > e[i].y) break;
    for (k = i + 1; k < j; k++) {
      int t = e[k].x;
      b[t] = 1;
      fa[findfa(t)] = ft;
    }
  }
  int tot1 = 0, tot2 = 0;
  for (i = 1; i <= m; i++) {
    if (!b[i]) {
      tot2++;
      continue;
    }
    if (findfa(i) == i) tot1++;
  }
  return make_pair(tot1, tot2);
}
int main() {
  int i, n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (i = 1; i <= q; i++) scanf("%d%d", &e[i].x, &e[i].y);
  pair<int, int> p1 = cal1(q, m), p2 = cal2(q, n);
  int ans1 = p1.first - 1;
  int ans2 = p1.second + p2.second;
  cout << ans1 + ans2 << endl;
  return 0;
}
