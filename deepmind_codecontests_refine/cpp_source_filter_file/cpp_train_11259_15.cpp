#include <bits/stdc++.h>
using namespace std;
struct bus {
  int s, d;
} a[100001];
int main() {
  int n, t;
  while (~scanf("%d%d", &n, &t)) {
    int i, minn = 100001, xx;
    for (i = 0; i < n; i++) {
      scanf("%d%d", &a[i].s, &a[i].d);
    }
    for (i = 0; i < n; i++) {
      while (a[i].s < t) a[i].s += a[i].d;
      if (minn > a[i].s) {
        minn = a[i].s;
        xx = i + 1;
      }
    }
    printf("%d\n", xx);
  }
  return 0;
}
