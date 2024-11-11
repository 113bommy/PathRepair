#include <bits/stdc++.h>
int n, x[1010], y[1010], p[1010], pos, q;
char a[1010];
int ccw(int i, int j, int k) {
  long long x1 = x[i];
  long long y1 = y[i];
  long long x2 = x[j];
  long long y2 = y[j];
  long long x3 = x[k];
  long long y3 = y[k];
  long long c = x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2;
  if (c > 0)
    return 1;
  else
    return -1;
}
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d", x + i, y + i);
  scanf("%s", a);
  for (int i = 1; i < n; i++) {
    if (x[i] < x[pos])
      pos = i;
    else if (x[i] == x[pos] && y[i] < y[pos])
      pos = i;
  }
  printf("%d ", pos + 1);
  p[pos] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!p[j]) {
        q = j;
        break;
      }
    }
    for (int j = q + 1; j < n; j++) {
      if (p[j]) continue;
      if (a[i - 1] == 'L' && ccw(j, pos, q) < 0) q = j;
      if (a[i - 1] == 'R' && ccw(j, pos, q) > 0) q = j;
    }
    pos = q;
    printf("%d ", pos + 1);
    p[pos] = 1;
  }
  printf("\n");
}
