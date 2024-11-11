#include <bits/stdc++.h>
int abs(int x) { return (x < 0) ? -x : x; }
int main(void) {
  int n, k;
  int a[5000 + 1];
  int diff[1000000 + 1];
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    for (int j = 0; j < i; j++) diff[abs(a[i] - a[j])]++;
  }
  int mark[5000] = {};
  for (int i = std::max(n - k, 1); i <= 1000000 + 1; i++) {
    int excess = 0;
    for (int j = i; j <= 1000000; j += i) {
      excess += diff[j];
      if (excess > k * (k + 1) / 2) break;
    }
    if (excess > k * (k + 1) / 2) continue;
    excess = 0;
    for (int j = 0; j < n; j++) {
      if (mark[a[j] % i] == i)
        excess++;
      else
        mark[a[j] % i] = i;
    }
    if (excess <= k) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
