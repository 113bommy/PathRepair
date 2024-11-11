#include <bits/stdc++.h>
int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; i++) {
    long long x;
    scanf("%I64d", &x);
    x = (x * a) % b;
    printf("%I64d ", x);
  }
}
