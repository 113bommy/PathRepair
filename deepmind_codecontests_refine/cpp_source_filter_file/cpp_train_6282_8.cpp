#include <bits/stdc++.h>
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int a[100], b[100];
  for (int i = 0; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int j = 0; j <= m; j++) {
    scanf("%d", b + j);
  }
  if (n > m) {
    if (a[0] * b[0] > 0) {
      printf("Infinity\n");
    } else {
      printf("-Infinity\n");
    }
  } else if (n < m) {
    printf("0/1\n");
  } else {
    int g = gcd(abs(a[0]), abs(b[0]));
    if (a[0] * b[0] < 0) {
      printf("-");
    }
    printf("%d/%d\n", abs(a[0]) / g, abs(b[0]) / g);
  }
  return 0;
}
