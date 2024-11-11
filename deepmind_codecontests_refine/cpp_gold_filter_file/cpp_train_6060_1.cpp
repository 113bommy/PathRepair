#include <bits/stdc++.h>
using namespace std;
double PI = 3.141592653589793238462643383279;
const double EPS = 1e-9;
const long long MOD = 1000000007;
const int inf = 1 << 30;
const long long linf = 1LL << 60;
int a[2], b[2], c[2];
int d[7];
void solve() {
  scanf("%d%d%d", a, b, c);
  scanf("%d%d%d", a + 1, b + 1, c + 1);
  for (int i = 0; i < (int)7; i++) scanf("%d", d + i);
  int x0, x1, x2 = -1, x4 = -1;
  bool ok = false;
  for (x0 = 0; x0 <= d[0]; x0++) {
    for (x1 = 0; x1 <= d[1]; x1++) {
      int p1 = max(0, d[0] + d[1] + d[2] - a[1] - x0 - x1);
      int p2 = min(d[2], a[0] - x0 - x1);
      int q1 = max(0, d[0] + d[1] + d[4] - b[1] - x0 - x1);
      int q2 = min(d[4], b[0] - x0 - x1);
      if (p1 > p2 || q1 > q2) continue;
      int r1 = d[0] + d[2] + d[4] - c[1] - x0;
      int r2 = c[0] - x0;
      x2 = p1;
      x4 = q1;
      if (x2 + x4 > r2) {
        continue;
      }
      if (r1 <= x2 + x4) {
        ok = true;
        break;
      }
      int d = r1 - x2 - x4;
      if (d <= p2 - p1) {
        x2 += d;
        ok = true;
        break;
      } else {
        x2 += (p2 - p1);
        d -= (p2 - p1);
      }
      if (d <= q2 - q1) {
        x4 += d;
        ok = true;
        break;
      } else {
        continue;
      }
    }
    if (ok) break;
  }
  if (!ok) {
    puts("-1");
    return;
  }
  int l3 = d[0] + d[1] + d[2] + d[3] - a[1] - x0 - x1 - x2,
      r3 = a[0] - x0 - x1 - x2;
  int l5 = d[0] + d[1] + d[4] + d[5] - b[1] - x0 - x1 - x4,
      r5 = b[0] - x0 - x1 - x4;
  int l6 = d[0] + d[2] + d[4] + d[6] - c[1] - x0 - x2 - x4,
      r6 = c[0] - x0 - x2 - x4;
  int x3 = min(d[3], max(0, l3));
  int x5 = min(d[5], max(0, l5));
  int x6 = min(d[6], max(0, l6));
  if (x3 > r3 || x5 > r5 || x6 > r6) {
    puts("-1");
    return;
  }
  printf("%d %d %d %d %d %d %d\n", x0, x1, x2, x3, x4, x5, x6);
}
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < (int)t; i++) solve();
}
