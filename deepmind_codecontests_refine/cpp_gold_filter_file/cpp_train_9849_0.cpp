#include <bits/stdc++.h>
int n, k, ans, p = 0;
int a[200010];
int main() {
  scanf("%d%d", &n, &k);
  n--;
  ans = 2 * (n / k);
  if ((n % k) >= 2)
    ans += 2;
  else if ((n % k) == 1)
    ans++;
  printf("%d\n", ans);
  int br = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= (n / k); j++) {
      br++;
      if (j == 1)
        printf("1 %d\n", br);
      else
        printf("%d %d\n", br - 1, br);
      if (j == (n / k)) a[++p] = br;
    }
  }
  for (int i = 1; i <= (n % k); i++) {
    br++;
    printf("%d %d\n", a[i], br);
  }
  return 0;
}
