#include <bits/stdc++.h>
using namespace std;
int resr[111], resc[111], a[111][111], sumr[111], sumc[111];
queue<int> c, r;
int main(void) {
  int n, m;
  while (scanf("%d %d", &n, &m) != EOF) {
    int i, j;
    memset(resr, 0, sizeof(resr));
    memset(resc, 0, sizeof(resc));
    memset(sumr, 0, sizeof(sumr));
    memset(sumc, 0, sizeof(sumc));
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
        sumr[i] += a[i][j];
        sumc[j] += a[i][j];
      }
    for (i = 0; i < n; i++)
      if (sumr[i] < 0) r.push(i);
    for (j = 0; j < m; j++)
      if (sumc[j] < 0) c.push(j);
    while (!(c.empty() && r.empty())) {
      while (!r.empty()) {
        i = r.front();
        if (sumr[i] >= 0) {
          r.pop();
          continue;
        }
        sumr[i] = -sumr[i];
        resc[i] ^= 1;
        for (j = 0; j < m; j++) {
          sumc[j] -= 2 * a[i][j];
          a[i][j] = -a[i][j];
          if (sumc[j] < 0) c.push(j);
        }
        r.pop();
      }
      while (!c.empty()) {
        j = c.front();
        if (sumc[j] >= 0) {
          c.pop();
          continue;
        }
        sumc[j] = -sumc[j];
        resc[j] ^= 1;
        for (i = 0; i < n; i++) {
          sumr[i] -= 2 * a[i][j];
          a[i][j] = -a[i][j];
          if (sumr[i] < 0) r.push(i);
        }
        c.pop();
      }
    }
    int rc = 0, rr = 0;
    for (i = 0; i < n; i++)
      if (resr[i] == 1) rr++;
    printf("%d ", rr);
    for (i = 0; i < n; i++)
      if (resr[i] == 1) printf("%d ", i + 1);
    printf("\n");
    for (j = 0; j < m; j++)
      if (resc[j] == 1) rc++;
    printf("%d ", rc);
    for (j = 0; j < m; j++)
      if (resc[j] == 1) printf("%d ", j + 1);
    printf("\n");
  }
  return 0;
}
