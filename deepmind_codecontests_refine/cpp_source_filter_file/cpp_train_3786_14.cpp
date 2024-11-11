#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
int n, hl, hr, cnt1, cnt2;
double ta[5551000];
struct Node {
  int l, r, score;
} c[110], f[110];
bool vis1[110], vis2[110];
int cmp(Node a, Node b) { return a.l < b.l; }
int main() {
  int cnt = 0;
  for (double i = -pi / 2; i < pi / 2; i += 0.00001) ta[cnt++] = tan(i);
  int a, b, c1;
  char ss[20];
  while (scanf("%d%d%d", &hl, &hr, &n) == 3) {
    cnt1 = cnt2 = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d %s %d %d", &a, ss, &b, &c1);
      if (ss[0] == 'F')
        f[cnt1].score = a, f[cnt1].l = b, f[cnt1++].r = c1;
      else
        c[cnt2].score = a, c[cnt2].l = b, c[cnt2++].r = c1;
    }
    sort(f, f + cnt1, cmp);
    sort(c, c + cnt2, cmp);
    int ans = 0;
    for (int i = 0, j; i < cnt; i++) {
      double x = 0, y = hl, k = ta[i], h = -1;
      int tmp = 0;
      if (k > -eps && k < eps) continue;
      memset(vis1, 0, sizeof(vis1));
      memset(vis2, 0, sizeof(vis2));
      while (x < 100000) {
        if (k <= 0)
          x = (k * x - y) / k, y = 0;
        else
          x = (100 - y) / k + x, y = 100;
        if (x >= 100000) {
          h = k * (100000 - x) + y;
          break;
        }
        if (k <= 0) {
          for (j = 0; j < cnt1; j++)
            if (x >= f[j].l && x <= f[j].r) break;
          if (j >= cnt1) break;
          if (vis1[j]) break;
          vis1[j] = 1;
          tmp += f[j].score;
        } else {
          for (j = 0; j < cnt2; j++)
            if (x >= c[j].l && x <= c[j].r) break;
          if (j >= cnt2 || vis2[j]) break;
          vis2[j] = 1;
          tmp += c[j].score;
        }
        k *= -1;
      }
      if (h >= hr - 0.5 && h <= hr + 0.5) ans = max(ans, tmp);
    }
    printf("%d\n", ans);
  }
  return 0;
}
