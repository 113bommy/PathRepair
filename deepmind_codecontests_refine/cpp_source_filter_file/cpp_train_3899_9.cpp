#include <bits/stdc++.h>
int main() {
  int n, v, i, a, b;
  int f[4000], prev, res;
  scanf("%d%d", &n, &v);
  for (i = 0; i <= 3000; i++) {
    f[i] = 0;
  }
  for (i = 0; i < n; i++) {
    scanf("%d%d", &a, &b);
    f[a] += b;
  }
  prev = res = 0;
  for (i = 0; i <= 3000; i++) {
    if (prev + f[i] <= v) {
      res += (prev + f[i]);
      prev = 0;
    } else {
      res += v;
      if (prev >= v)
        prev = f[i];
      else {
        prev = prev + f[i] - v;
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
