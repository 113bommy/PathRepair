#include <bits/stdc++.h>
int SRD[709][709];
int a[500001];
int main() {
  int q, i, j, k;
  scanf("%d", &q);
  for (k = 0; k < q; k++) {
    int t, x, y;
    scanf("%d", &t);
    scanf("%d", &x);
    scanf("%d", &y);
    if (t == 1) {
      a[x] += y;
      for (i = 1; i < 709; i++) {
        SRD[i][x % i] += y;
      }
    } else {
      if (x >= 709) {
        long long answer = 0;
        for (i = y; i < 500001; i += x) answer += a[i];
        printf("%I64d", answer);
        printf("\n");
      } else {
        printf("%d", SRD[x][y]);
        printf("\n");
      }
    }
  }
  return 0;
}
