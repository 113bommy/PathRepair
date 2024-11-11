#include <bits/stdc++.h>
int main() {
  int mino, maxo, mine, maxe;
  int n, d, l;
  int a[105];
  scanf("%d%d%d", &n, &d, &l);
  if (n % 2 == 0) {
    mino = mine = n / 2;
    maxo = maxe = (n / 2) * l;
  } else {
    mino = n / 2 + 1;
    mine = n / 2;
    maxo = mino * l;
    maxe = mine * l;
  }
  if (!(mino - maxe <= d && d <= maxo - mine)) {
    printf("-1\n");
  } else {
    for (int i = 0; i < n; i++) {
      a[i] = 1;
    }
    if (d > 0) {
      int i = 0;
      if (n % 2) d -= 1;
      while (d) {
        if (d >= l - 1) {
          a[i] += l - 1;
          d -= l - 1;
        } else {
          a[i] += d;
          d = 0;
        }
        i += 2;
      }
    } else {
      int i = 1;
      d = -d;
      if (n % 2) d += 1;
      while (d) {
        if (d >= l - 1) {
          a[i] += l - 1;
          d -= l - 1;
        } else {
          a[i] += d;
          d = 0;
        }
        i += 2;
      }
    }
    for (int i = 0; i < n; i++) {
      (i == 0) ? printf("%d", a[i]) : printf(" %d", a[i]);
    }
    printf("\n");
  }
  return 0;
}
