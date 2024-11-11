#include <bits/stdc++.h>
using namespace std;
struct node {
  double p;
  int s, n, t;
  bool operator<(const node &t) const {
    if (s != t.s) return s < t.s;
    return p > t.p;
  }
} f[1100];
int main() {
  int n, k;
  while (~scanf("%d%d", &n, &k)) {
    int cc = 0;
    double ans = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lf%d", &f[i].p, &f[i].s);
      f[i].n = i + 1;
      f[i].t = 0;
      if (f[i].s == 1) cc++;
      ans += f[i].p;
    }
    sort(f, f + n);
    k--;
    if (cc <= k) {
      for (int i = 0; i < cc; i++) {
        ans -= f[i].p * .5;
      }
      printf("%.1f\n", ans);
      for (int i = 0; i < cc; i++) {
        printf("%d %d\n", 1, f[i].n);
      }
      k -= cc;
      while (k--) {
        printf("1 %d\n", f[cc].n);
        cc++;
      }
      printf("%d", n - cc);
      for (int i = cc; i < n; i++) {
        printf(" %d", f[i].n);
      }
      puts("");
    } else {
      for (int i = 0; i < k; i++) {
        ans -= f[i].p * .5;
      }
      double mi = 23452352345.0;
      for (int i = k; i < n; i++) {
        mi = min(f[i].p, mi);
      }
      ans -= mi * .5;
      printf("%.1f\n", ans);
      for (int i = 0; i < k; i++) {
        printf("%d %d\n", 1, f[i].n);
      }
      int p = n - k;
      printf("%d", p);
      for (int i = k; i < n; i++) {
        printf(" %d", f[i].n);
      }
      puts("");
    }
  }
  return 0;
}
