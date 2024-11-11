#include <bits/stdc++.h>
int main() {
  int n, a, d;
  scanf("%d", &n);
  scanf("%d", &a);
  scanf("%d", &d);
  int atv[n][3];
  for (int i = 0; i < n; i++) {
    scanf("%d", &atv[i][0]);
    scanf("%d", &atv[i][1]);
    atv[i][2] = i;
  }
  long double ts[n][3];
  long double delta = 0;
  for (int i = 0; i < n; i++) {
    ts[i][0] = (long double)atv[i][1] / a;
    if (((a * ts[i][0] * ts[i][0]) / 2) < (long double)d)
      ts[i][1] = ts[i][0] +
                 (d - (long double)(a * ts[i][0] * ts[i][0]) / 2) / atv[i][1] +
                 atv[i][0];
    else
      ts[i][1] = sqrt((long double)2 * d / a) + atv[i][0];
    if (ts[i][1] < ts[i - 1][1] && i > 0) ts[i][1] = ts[i - 1][1];
  }
  for (int i = 0; i < n; i++) {
    printf("%Lf ", ts[i][1]);
  }
  return 0;
}
