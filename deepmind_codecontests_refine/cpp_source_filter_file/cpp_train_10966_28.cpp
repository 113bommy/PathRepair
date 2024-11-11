#include <bits/stdc++.h>
int main() {
  int n, k, ans;
  scanf("%d%d", &n, &k);
  if (n * 3 >= k)
    printf("0\n");
  else {
    if (n >= k) {
      ans = n - (k / 3);
      printf("%d\n", ans);
    }
    if (n * 2 == k)
      printf("%d\n", n);
    else {
      ans = abs(n - (abs(k - (n * 2))));
      printf("%d\n", ans);
    }
  }
  return 0;
}
