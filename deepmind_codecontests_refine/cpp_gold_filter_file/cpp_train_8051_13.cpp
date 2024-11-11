#include <bits/stdc++.h>
int main() {
  int i, n, v[100];
  float p, s;
  char c;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%c", &v[i], &c);
  }
  s = 0;
  for (i = 0; i < n; i++) {
    s = s + v[i];
  }
  printf("%f", s / n);
  return 0;
}
