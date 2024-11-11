#include <bits/stdc++.h>
int f[400005];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int now = 0, deg = 1;
  for (int i = 1, tmp; i <= n; i++) {
    scanf("%d", &tmp);
    f[tmp % k]++;
    while (f[now % k] >= deg) {
      now++;
      if (now >= deg * k) deg++;
    }
    printf("%d\n", now);
  }
  return 0;
}
