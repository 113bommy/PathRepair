#include <bits/stdc++.h>
int main() {
  int n, k;
  int a[1005];
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  std::sort(a, a + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    while (k * 2 < a[i]) {
      k *= 2;
      ans++;
    }
    k = std::max(k, a[i]);
  }
  printf("%d\n", ans);
  return 0;
}
