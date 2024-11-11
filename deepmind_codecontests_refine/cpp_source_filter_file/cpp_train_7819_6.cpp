#include <bits/stdc++.h>
int m(int n) {
  int max = 0, k;
  for (int i = 0; i < n; i++) {
    scanf("%d", &k);
    if (k > max) max = k;
  }
  return max;
}
int c[200005], ce[200005];
int main() {
  int n, max = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ce[i]);
    c[i] = m(ce[i]);
    if (c[i] > max) max = c[i];
  }
  long long sum = 0;
  for (int i = 0; i < n; i++)
    if (c[i] < max) sum += ce[i] * (max - c[i]);
  printf("%lld", sum);
  return 0;
}
