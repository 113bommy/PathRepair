#include <bits/stdc++.h>
int main() {
  int n, i, p;
  float s = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &p);
    s = s + p;
  }
  s = s / n;
  printf("%f", s);
}
