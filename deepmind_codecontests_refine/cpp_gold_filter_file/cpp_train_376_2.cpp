#include <bits/stdc++.h>
int mod(int);
int main() {
  int x, y, n, ans1, ans2, ans;
  scanf("%d%d", &x, &y);
  if (mod(x - y) == 1) {
    printf("%d", 1);
  } else if ((x - y) % 2 == 0) {
    n = mod(x - y);
    n = n / 2;
    n = n * (n + 1) / 2;
    n = 2 * n;
    printf("%d", n);
  } else {
    n = mod(x - y);
    n = n / 2;
    n = n * (n + 1) / 2;
    n = 2 * n;
    ans = mod(x - y);
    ans = (ans + 1) / 2;
    n = n + ans;
    printf("%d", n);
  }
  return 0;
}
int mod(int n) {
  if (n > 0) {
    return n;
  } else {
    n = 0 - n;
    return n;
  }
}
