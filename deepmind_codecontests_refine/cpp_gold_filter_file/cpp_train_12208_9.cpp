#include <bits/stdc++.h>
int n;
long long h[1000003], s;
int main() {
  scanf(" %d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" %I64d", &h[i]);
    h[i] -= i;
    s += h[i];
  }
  for (int i = 0; i < n; ++i) {
    h[i] = s / n + (i < s % n) + i;
    printf("%I64d ", h[i]);
  }
  return 0;
}
