#include <bits/stdc++.h>
using namespace std;
long long ts, h, w, s, l, maxsquare, maxh, maxw;
int main() {
  scanf("%I64d%I64d", &h, &w);
  maxsquare = 0;
  maxh = 0;
  maxw = 0;
  for (ts = 0; ts < 31; ts++) {
    s = (long long)1 << ts;
    if (s > h) break;
    if (0.8 * s > w) continue;
    if (1.25 * s < w) l = floor(1.25 * s);
    if ((0.8 * s <= w) && (w <= 1.25 * s)) l = w;
    if ((s * l > maxsquare) || ((s * l == maxsquare) && (s > maxh))) {
      maxsquare = s * l;
      maxh = s;
      maxw = l;
    }
  }
  for (ts = 0; ts < 31; ts++) {
    l = (long long)1 << ts;
    if (l > w) break;
    if (0.8 * l > h) continue;
    if (1.25 * l < h) s = floor(1.25 * l);
    if ((0.8 * l <= h) && (h <= 1.25 * l)) s = h;
    if ((s * l > maxsquare) || ((s * l == maxsquare) && (s > maxh))) {
      maxsquare = s * l;
      maxh = s;
      maxw = l;
    }
  }
  printf("%I64d %I64d\n", maxh, maxw);
  return 0;
}
