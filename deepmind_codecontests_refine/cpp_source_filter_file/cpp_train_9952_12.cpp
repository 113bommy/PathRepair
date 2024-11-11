#include <bits/stdc++.h>
using namespace std;
int solved[10], v[10], p[10];
int give(int acc, int tot) {
  if (2 * acc > tot)
    return 500;
  else if (4 * acc > tot)
    return 1000;
  else if (8 * acc > tot)
    return 1500;
  else if (16 * acc > tot)
    return 2000;
  else if (32 * acc > tot)
    return 2500;
  else
    return 3000;
}
int main() {
  int n, i, j, a, x;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= 5; j++) {
      scanf("%d", &a);
      if (i == 1)
        v[j] = a;
      else if (i == 2)
        p[j] = a;
      if (a != -1) solved[j]++;
    }
  }
  for (x = 0; x <= 720; x++) {
    int tot1 = 0, tot2 = 0, m;
    for (i = 1; i <= 5; i++) {
      if (v[i] == p[i]) continue;
      if (v[i] == -1) {
        m = give(solved[i], n + x);
        tot2 += (m - (m * p[i]) / 250);
      } else if (p[i] == -1) {
        m = give(solved[i], n + x);
        tot1 += (m - (m * v[i]) / 250);
      } else if (v[i] < p[i]) {
        m = give(solved[i], n + x);
        tot1 += (m - (m * v[i]) / 250);
        tot2 += (m - (m * p[i]) / 250);
      } else {
        m = give(solved[i] + x, n + x);
        tot1 += (m - (m * v[i]) / 250);
        tot2 += (m - (m * p[i]) / 250);
      }
    }
    if (tot1 > tot2) break;
  }
  if (x > 720)
    printf("-1\n");
  else
    printf("%d\n", x);
  return 0;
}
