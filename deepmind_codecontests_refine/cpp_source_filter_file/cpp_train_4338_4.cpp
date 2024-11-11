#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int maxn = 100005;
int n, m, cl, ce, v, rocl[maxn], roce[maxn], q;
int xx, x2, yy, y2;
int zheng(int x) { return x > 0 ? x : -x; }
double dzheng(double x) { return x > 0 ? x : -x; }
int deal(int pos, int flag, int now) {
  int ans = mod;
  if (pos == 0) return ans;
  if (flag) {
    if (pos - 1 != 0) {
      ans = zheng(yy - rocl[pos - 1]) + zheng(xx - x2) +
            zheng(rocl[pos - 1] - y2);
    }
    if (now) {
      ans = min(ans,
                zheng(yy - rocl[pos]) + zheng(xx - x2) + zheng(rocl[pos] - y2));
    }
    return ans;
  } else {
    if (pos - 1 != 0) {
      ans = zheng(yy - roce[pos - 1]) + (int)ceil((dzheng(xx - x2) * 1.0 / v)) +
            zheng(roce[pos - 1] - y2);
    }
    if (now) {
      double z = dzheng((xx - x2) * 1.0 / v);
      int x = (int)ceil(dzheng((xx - x2) * 1.0 / v));
      ans = min(ans, zheng(yy - roce[pos]) +
                         (int)ceil(dzheng((xx - x2) * 1.0 / v)) +
                         zheng(roce[pos] - y2));
    }
    return ans;
  }
}
int main() {
  scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
  for (int i = 1; i <= cl; i++) scanf("%d", &rocl[i]);
  for (int i = 1; i <= ce; i++) scanf("%d", &roce[i]);
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d%d%d", &xx, &yy, &x2, &y2);
    if (xx == x2) {
      printf("%d\n", abs(xx - x2));
      continue;
    }
    int ans = mod;
    int poscl = upper_bound(rocl + 1, rocl + 1 + cl, yy) - rocl,
        posce = upper_bound(roce + 1, roce + 1 + ce, yy) - roce;
    if (poscl == cl + 1) {
      ans = deal(poscl, 1, 0);
    } else
      ans = deal(poscl, 1, 1);
    if (posce == ce + 1) {
      ans = min(ans, deal(posce, 0, 0));
    } else
      ans = min(ans, deal(posce, 0, 1));
    printf("%d\n", ans);
  }
  return 0;
}
