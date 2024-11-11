#include <bits/stdc++.h>
int main() {
  int i, n, k, ans = 0;
  int num[51];
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d ", &num[i]);
  }
  for (i = 0; i < n; i++) {
    if (num[i] != 0 && num[i] > num[k - 1]) {
      ans += 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
