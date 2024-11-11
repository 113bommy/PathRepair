#include <bits/stdc++.h>
using namespace std;
int a[2 * 1005], b[2 * 1005], v, c, d, sum[2 * 1005];
bool tag;
int main() {
  int k, j, e, f, t, i, sumds;
  for (scanf("%d", &v); v--;) {
    k = 250;
    tag = 0;
    d = 0;
    memset(a, 0, sizeof a);
    while (k--) {
      scanf("%d", &c);
      if (c <= 2000) {
        a[c]++;
        d = max(c, d);
      } else
        tag = 1;
    }
    if (tag)
      puts("poisson");
    else {
      for (j = d / 2; j <= 1000; j++) {
        memset(sum, 0, sizeof sum);
        sumds = 0;
        for (k = 0; k <= 2 * j; k++) {
          sum[k] = sumds = sumds + a[k];
        }
        for (i = 0; i <= j; i++) {
          if (85 < sum[i + j] - sum[i] && 160 > sum[i + j] - sum[i])
            continue;
          else
            break;
        }
        if (i > j) {
          puts("uniform");
          break;
        }
      }
      if (j > 1000) puts("poisson");
    }
  }
}
