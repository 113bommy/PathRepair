#include <bits/stdc++.h>
int main() {
  int p, k;
  int n = 1e9 + 7;
  scanf("%d%d", &p, &k);
  if (k == 0) {
    long long tmp = p, r = 1;
    p--;
    while (p) {
      if (p & 1) {
        r = r * tmp % n;
      }
      tmp = tmp * tmp % n;
      p >>= 1;
    }
    printf("%I64d\n", r);
  } else if (k == 1) {
    long long tmp = p, r = 1;
    while (p) {
      if (p & 1) {
        r = r * tmp % n;
      }
      tmp = tmp * tmp % n;
      p >>= 1;
    }
    printf("%I64d\n", r);
  } else {
    long long tmp = 1;
    long long ans;
    for (int i = 1;; i++) {
      tmp = (tmp * k) % p;
      if (tmp == 1) {
        ans = i;
        break;
      }
    }
    long long r = 1;
    tmp = p;
    p = (p - 1) / ans;
    while (p) {
      if (p & 1) {
        r = r * tmp % n;
      }
      tmp = tmp * tmp % n;
      p >>= 1;
    }
    printf("%I64d\n", r);
  }
}
