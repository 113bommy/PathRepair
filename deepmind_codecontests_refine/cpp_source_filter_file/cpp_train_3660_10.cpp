#include <bits/stdc++.h>
long long xp[2200];
long long yp[2200];
int used[2200];
char str[2200];
long long cross(long long x1, long long y1, long long x2, long long y2) {
  return (x1 * y2) - (x2 * y1);
};
int main(void) {
  int start = -1;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &xp[i], &yp[i]);
    if (start == -1 || xp[i] < xp[start] ||
        (xp[i] == xp[start] && yp[i] < yp[start])) {
      start = i;
    };
  };
  used[start] = 1;
  scanf("%s", str);
  printf("%d ", start + 1);
  int best = -1;
  int last = start;
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < n; j++) {
      if (!used[j]) {
        if (best == -1) {
          best = j;
        } else {
          long long erg = cross(xp[best] - xp[last], yp[best] - yp[last],
                                xp[j] - xp[last], yp[j] - yp[last]);
          if (str[i] == 'L' && erg > 0) {
            best = j;
          } else if (str[i] == 'R' && erg < 0) {
            best = j;
          };
        };
      };
    };
    printf("%d ", best + 1);
    used[best] = 1;
    last = best;
    best = -1;
  };
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      printf("%d\n", i + 1);
    };
  };
  return 0;
};
