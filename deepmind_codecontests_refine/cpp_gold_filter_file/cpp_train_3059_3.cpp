#include <bits/stdc++.h>
int ans, p, i;
bool f(int x) {
  int t, y, i;
  t = 1;
  for (i = 1; i < p - 1; i++) {
    t = t * x % p;
    if (t - 1 == 0) {
      return 0;
    }
  }
  t = t * x % p;
  return (t - 1 == 0);
}
int main() {
  scanf("%d\n", &p);
  ans = 0;
  for (i = 1; i < p; i++) {
    if (f(i)) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
