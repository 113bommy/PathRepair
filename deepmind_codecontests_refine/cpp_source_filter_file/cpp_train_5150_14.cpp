#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 123;
double lclose, ropen;
int n;
bool stat[N];
int last;
int i;
int main() {
  while (scanf("%d", &n) != EOF) {
    memset(stat, 0, sizeof(stat));
    while (n--) {
      int a;
      scanf("%d", &a);
      stat[a] = true;
      last = a;
    }
    lclose = 1;
    ropen = 1e100;
    double coe = 1;
    double l, r;
    for (i = 1; i <= last; ++i) {
      double te = (i + 1.0) / coe;
      if (stat[i]) {
        if (te < ropen) ropen = te;
        coe += 1;
      } else {
        if (te > lclose) lclose = te;
      }
    }
    bool unique = true;
    int ans;
    for (i = last + 1;; ++i) {
      l = lclose * coe - i;
      r = ropen * coe - i;
      if (((fabs(1 - l) < 1e-8) ? 0 : ((1 - l < 0) ? -1 : 1)) > 0 &&
          ((fabs(1 - r) < 1e-8) ? 0 : ((1 - r < 0) ? -1 : 1)) <= 0) {
        unique = false;
        break;
      }
      if (((fabs(1 - r) < 1e-8) ? 0 : ((1 - r < 0) ? -1 : 1)) > 0) {
        ans = i;
        break;
      }
    }
    if (unique) {
      puts("unique");
      printf("%d\n", ans);
    } else
      puts("not unique");
  }
  return 0;
}
