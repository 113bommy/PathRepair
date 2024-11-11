#include <bits/stdc++.h>
int wei(int x) {
  int w = 1;
  while (x / 10 != 0) {
    x = x / 10;
    w++;
  }
  return w;
}
int max = 1, m1;
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int m, m1 = 0;
    int qian = 0;
    int w1;
    int sum = 0;
    scanf("%d", &m);
    for (int i = 1; i <= 9; i++) {
      m1 = m;
      int y = m1;
      while (m1 / 10 != 0) {
        m1 = m1 / 10, y = m1;
      }
      if (y == i) {
        max = i;
        break;
      }
    }
    qian = (max - 1) * 10;
    w1 = wei(m);
    for (int k = 1; k <= w1; k++) {
      sum += k;
    }
    sum += qian;
    printf("%d", sum);
    max = 1;
    if (n >= 1) printf("\n");
  }
  return 0;
}
