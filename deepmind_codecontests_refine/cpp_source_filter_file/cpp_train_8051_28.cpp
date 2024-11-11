#include <bits/stdc++.h>
int main() {
  int n, p, i;
  float sum = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &p);
    sum = sum + p;
  }
  printf("%lf", sum / n);
}
