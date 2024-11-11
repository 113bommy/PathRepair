#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int maxn = 100005;
int n, m, cl, ce, v, rocl[maxn], roce[maxn], q;
int xx, x2, yy, y2;
int main() {
  scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
  for (int i = 1; i <= cl; i++) scanf("%d", &rocl[i]);
  for (int i = 1; i <= ce; i++) scanf("%d", &roce[i]);
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d%d%d", &xx, &yy, &x2, &y2);
    int ans = mod;
    if (xx == x2) {
      printf("%d\n", abs(yy - y2));
      continue;
    }
    if (cl) {
      int poscl = lower_bound(rocl + 1, rocl + cl + 1, yy) - rocl;
      if (poscl <= cl && poscl) {
        ans = abs(rocl[poscl] - yy) + abs(rocl[poscl] - y2) + abs(xx - x2);
      }
      if (poscl > 1) {
        poscl--;
        ans = min(ans,
                  abs(rocl[poscl] - yy) + abs(rocl[poscl] - y2) + abs(xx - x2));
      }
    }
    if (ce) {
      int posce = lower_bound(roce + 1, roce + ce + 1, yy) - roce;
      if (posce <= ce && posce) {
        ans = min(ans, abs(roce[posce] - yy) + abs(roce[posce] - y2) +
                           abs(xx - x2) / v + ((abs(xx - x2) % v) ? 1 : 0));
      }
      if (posce > 1) {
        posce--;
        ans = min(ans, abs(roce[posce] - yy) + abs(roce[posce] - y2) +
                           abs(xx - x2) / v + ((abs(xx - x2) % v) ? 1 : 0));
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
