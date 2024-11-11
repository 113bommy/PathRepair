#include <bits/stdc++.h>
int a[1000000];
int count(int x) {
  int s = 1;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) {
      int a = 0;
      while (x % i == 0) {
        x /= i;
        a++;
      }
      s *= (a + 1);
    }
  if (x > 1) s = s * 2;
  return s;
}
void init() {
  for (int i = 1; i < 1000000; i++) a[i] = count(i);
}
int main() {
  init();
  int m, n, p;
  while (scanf("%d%d%d", &m, &n, &p) != EOF) {
    int s = 0;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        for (int k = 1; k <= p; k++) {
          s += a[i * j * k];
        }
    printf("%d\n", s % 1073741824);
  }
  return 0;
}
