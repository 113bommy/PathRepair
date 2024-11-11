#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
struct mouse {
  double sx, sy, vx, vy, st, ft;
};
mouse m[maxn];
bool compare(const mouse &a, const mouse &b) { return a.st > b.st; }
void solve() {
  int n;
  scanf("%d", &n);
  double x1, x2, y1, y2;
  scanf("%lf", &x1);
  scanf("%lf", &y1);
  scanf("%lf", &x2);
  scanf("%lf", &y2);
  if (x1 == x2 or y1 == y2) {
    puts("-1");
    return;
  }
  x1 += 1e-12;
  x2 -= 1e-12;
  y1 += 1e-12;
  y2 -= 1e-12;
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &m[i].sx);
    scanf("%lf", &m[i].sy);
    scanf("%lf", &m[i].vx);
    scanf("%lf", &m[i].vy);
    double txs, txe, tys, tye;
    txs = (x1 - m[i].sx) / m[i].vx;
    txe = (x2 - m[i].sx) / m[i].vx;
    tys = (y1 - m[i].sy) / m[i].vy;
    tye = (y2 - m[i].sy) / m[i].vy;
    if (txs <= 0 and txe <= 0) {
      puts("-1");
      return;
    }
    if (tys <= 0 and tye <= 0) {
      puts("-1");
      return;
    }
    if (txs > txe) {
      swap(txs, txe);
    }
    if (tys > tye) {
      swap(tys, tye);
    }
    m[i].st = max(txs, tys);
    m[i].ft = min(txe, tye);
    if (m[i].st <= 0) {
      m[i].st = 0;
    }
    if (m[i].st >= m[i].ft) {
      puts("-1");
      return;
    }
  }
  sort(m + 1, m + 1 + n, compare);
  double ans = m[1].st;
  for (int i = 2; i <= n; i++) {
    if (ans > m[i].ft) {
      puts("-1");
      return;
    }
  }
  printf("%.21lf\n", ans);
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
