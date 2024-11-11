#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  int tmp = a;
  while (b) {
    tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}
int main() {
  int a, b;
  int y1[2005], x2[2005];
  int i, j, t, c1, c2;
  while (scanf("%d%d", &a, &b) != EOF) {
    c1 = c2 = 0;
    for (i = -a + 1; i < 0; i++) {
      t = a * a - i * i;
      int ty = sqrt(t);
      if (ty * ty == t) {
        y1[c1++] = ty;
      }
    }
    for (i = 1; i <= b - 1; i++) {
      t = b * b - i * i;
      if ((int)sqrt(t) * sqrt(t) == t) {
        x2[c2++] = i;
      }
    }
    int flag = 1;
    for (i = 0; i < c1 && flag; i++)
      for (j = 0; j < c2 && flag; j++) {
        int x1 = (int)sqrt(a * a - y1[i] * y1[i]);
        int y2 = (int)sqrt(b * b - x2[j] * x2[j]);
        if (x1 * x2[i] == y1[j] * y2)
          if (!(y1[i] == y2)) {
            printf("YES\n");
            printf("0 0\n");
            printf("%d %d\n", -x1, y1[i]);
            printf("%d %d\n", x2[j], y2);
            flag = 0;
          }
      }
    if (flag) printf("NO\n");
  }
  return 0;
}
