#include <bits/stdc++.h>
char issq[1000000];
int a, b, xa[123456], ya[123456], uta, xb[123456], yb[123456], utb;
int dotp(int x1, int y1, int x2, int y2, int x3, int y3) {
  return (x1 - x2) * (x2 - x3) + (y1 - y2) * (y2 - y3);
}
int main() {
  scanf("%d %d", &a, &b);
  for (int i = 1; i < 1000; i++)
    for (int j = 1; j < 1000; j++) {
      if (i * i + j * j == a * a) {
        xa[uta] = i;
        ya[uta++] = j;
      }
      if (i * i + j * j == b * b) {
        xb[utb] = i;
        yb[utb++] = j;
      }
    }
  for (int i = 0; i < uta; i++)
    for (int j = 0; j < utb; j++)
      if (ya[i] != yb[j] && !dotp(xa[i], ya[i], 0, 0, -xb[j], yb[j])) {
        printf("YES\n%d %d\n0 0\n%d %d\n", xa[i], ya[i], -xb[j], yb[j]);
        return 0;
      }
  puts("NO");
  return 0;
}
