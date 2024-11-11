#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  float sum = 0;
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    sum = sum + k;
  }
  sum = sum / n;
  printf("%f", sum);
}
