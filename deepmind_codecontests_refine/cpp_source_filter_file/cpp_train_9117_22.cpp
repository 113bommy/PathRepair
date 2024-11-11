#include <bits/stdc++.h>
using namespace std;
int c[3000];
double sc, d[3000], dis, dmx;
int main() {
  int cnt, a, sum, dsum, j, mx, p, i;
  for (scanf("%d", &cnt); cnt--;) {
    sum = dsum = mx = 0;
    dmx = 10000;
    memset(c, 0, sizeof c);
    for (i = 0; i < 250; i++) {
      scanf("%d", &a);
      if (a <= 2000) c[a]++;
      if (mx < a) mx = a;
      sum += a;
      dsum += a * a;
    }
    sc = 250.0 * dsum / sum / sum;
    if (sc < 1.15)
      printf("%d\n", (int)(0.5 + 0.004 * sum));
    else {
      for (i = 0; i <= 2000; i++) d[i] = 1.0 * c[i] / 250;
      for (j = (mx + 1) / 2; j <= 1000; j++) {
        dis = 0;
        for (i = 0; i <= mx; i++) dis += fabs(d[i] - 1.0 / (2 * j + 1));
        if (dmx > dis) {
          dmx = dis;
          p = j;
        }
      }
      printf("%d\n", p);
    }
  }
}
