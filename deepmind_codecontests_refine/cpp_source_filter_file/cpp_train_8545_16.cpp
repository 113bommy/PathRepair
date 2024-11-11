#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
int n, q;
long long lft[222222], rgt[222222];
long long pref[222222];
int main() {
  long long sy, a, b;
  scanf("%lld%lld%lld", &sy, &a, &b);
  scanf("%d", &n);
  for (int(i) = 0; (i) < (n); (i)++) scanf("%lld%lld", lft + i, rgt + i);
  for (int(i) = 0; (i) < (n); (i)++) pref[i + 1] = pref[i] + rgt[i] - lft[i];
  scanf("%d", &q);
  for (int(i) = 0; (i) < (q); (i)++) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    long double L = x == a ? x : (x - y * (x - a) / (long double)(y - sy));
    long double R = x == b ? x : (x - y * (x - b) / (long double)(y - sy));
    int lbin = 0, rbin = n;
    while (lbin + 1 < rbin) {
      int mid = (lbin + rbin) / 2;
      if (L > rgt[mid] - 0.0000000001) {
        lbin = mid;
      } else {
        rbin = mid;
      }
    }
    int anshf = lbin;
    if (anshf == n) {
      printf("%.10lf\n", 0);
      continue;
    }
    lbin = 0, rbin = n;
    while (lbin + 1 < rbin) {
      int mid = (lbin + rbin) / 2;
      if (R < lft[mid] + 0.0000000001) {
        rbin = mid;
      } else {
        lbin = mid;
      }
    }
    long double ratio = 0.0;
    if (anshf == lbin) {
      ratio = max(0.0L, min(R, (long double)rgt[anshf]) -
                            max(L, (long double)lft[anshf]));
      ratio /= R - L;
    } else {
      ratio = pref[lbin] - pref[anshf + 1];
      ratio += max(0.0L, min((long double)rgt[anshf], R) -
                             max(L, (long double)lft[anshf]));
      ratio += max(0.0L, min((long double)rgt[lbin], R) -
                             max(L, (long double)lft[lbin]));
      ratio /= R - L;
    }
    ratio = max(0.0L, ratio);
    printf("%.10lf\n", (double)(ratio * (b - a)));
  }
  return 0;
}
