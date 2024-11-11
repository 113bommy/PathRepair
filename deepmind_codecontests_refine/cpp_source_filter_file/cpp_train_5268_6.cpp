#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct lol {
  int l, r, ans, cnt, st[15], dr[15];
  lol() {
    l = r = ans = cnt = 0;
    memset(st, 0, sizeof(st));
    memset(dr, 0, sizeof(dr));
  }
};
int i, j, n, m, q, x, y, a[15][N], p[N];
lol arb[4 * N];
int pfind(int x) { return p[x] == x ? x : p[x] = pfind(p[x]); }
inline lol operator+(const lol &x, const lol &y) {
  lol ans;
  ans.l = x.l;
  ans.r = y.r;
  ans.cnt = x.cnt + y.cnt;
  ans.ans = x.ans + y.ans;
  for (int i = 0; i <= ans.cnt; ++i) p[i] = i;
  for (int i = 1; i <= n; ++i) {
    if (a[i][x.r] != a[i][y.l]) continue;
    if (pfind(x.dr[i]) == pfind(y.st[i] + x.cnt)) continue;
    p[pfind(x.dr[i])] = pfind(y.st[i] + x.cnt);
    --ans.ans;
  }
  ans.cnt = 0;
  int viz[100];
  memset(viz, 0, sizeof(viz));
  for (int i = 1; i <= n; ++i) {
    if (!viz[pfind(x.st[i])]) viz[pfind(x.st[i])] = ++ans.cnt;
    ans.st[i] = viz[pfind(x.st[i])];
  }
  for (int i = 1; i <= n; ++i) {
    if (!viz[pfind(y.dr[i] + x.cnt)]) viz[pfind(y.dr[i] + x.cnt)] = ++ans.cnt;
    ans.dr[i] = viz[pfind(y.dr[i] + x.cnt)];
  }
  return ans;
}
void build(int left, int right, int nod) {
  if (left == right) {
    arb[nod].l = left;
    arb[nod].r = right;
    arb[nod].st[1] = arb[nod].dr[1] = 1;
    for (int i = 2; i <= n; ++i)
      if (a[i][left] == a[i - 1][left])
        arb[nod].st[i] = arb[nod].dr[i] = arb[nod].st[i - 1];
      else
        arb[nod].st[i] = arb[nod].dr[i] = arb[nod].st[i - 1] + 1;
    arb[nod].ans = arb[nod].cnt = arb[nod].dr[n];
    return;
  }
  int pivot = (left + right) / 2;
  build(left, pivot, 2 * nod);
  build(pivot + 1, right, 2 * nod + 1);
  arb[nod] = arb[2 * nod] + arb[2 * nod + 1];
}
lol query(int left, int right, int nod) {
  if (x <= left && right <= y) return arb[nod];
  int pivot = (left + right) / 2;
  lol gmb, fnc;
  if (x <= pivot) gmb = query(left, pivot, 2 * nod);
  if (y > pivot) fnc = query(pivot + 1, right, 2 * nod + 1);
  if (!gmb.l) return fnc;
  if (!fnc.l) return gmb;
  return gmb + fnc;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> q;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) cin >> a[i][j];
  build(1, m, 1);
  while (q--) cin >> x >> y, cout << query(1, m, 1).cnt << '\n';
  return 0;
}
