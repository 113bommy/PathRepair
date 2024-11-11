#include <bits/stdc++.h>
int main() {
  int n, x[105];
  int i;
  scanf("%d", &n);
  float sum = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  for (i = 0; i < n; i++) {
    sum += x[i];
  }
  printf("%.12f\n", sum / n);
}
