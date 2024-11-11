#include <bits/stdc++.h>
using namespace std;
long long h[100500], p[100500];
int main() {
  int n, np;
  scanf("%d %d", &n, &np);
  for (int i = (0); i < (n); ++i) scanf("%I64d", h + i);
  for (int i = (0); i < (np); ++i) scanf("%I64d", p + i);
  long long tleft = 0, tright = 20000000100LL;
  while (tleft < tright) {
    long long mid = (tleft + tright) / 2;
    long long* e = p + np;
    long long* b = p;
    for (int i = 0; i < n && b != e; ++i) {
      long long y = h[i];
      long long t = mid;
      if (*b < y) {
        long long d = y - *b;
        if (d > mid) break;
        t = max(mid - 2 * d, (mid - d) / 2);
        if (t < 0) t = 0;
      }
      b = upper_bound(b, e, y + t);
    }
    if (b == e)
      tright = mid;
    else
      tleft = mid + 1;
  }
  cout << tleft << endl;
}
