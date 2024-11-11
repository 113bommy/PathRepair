#include <bits/stdc++.h>
long long int k, l, r, p;
long long int quickpow(long long int a, long long int b, long long int q) {
  long long int ans = 1;
  while (b != 0) {
    if (b % 2 == 1) {
      ans = (ans % q * a % q) % q;
    }
    a = (a % q * a % q) % q;
    b = b / 2;
  }
  return ans;
}
long long int sum() {
  if (k % p == 0) return 1;
  long long int x = quickpow(k, quickpow(2, l, p), p) - 1;
  x = (x + p) % p;
  if (x == 0) {
    return quickpow(2, r - l + 1, p);
  }
  long long int y = quickpow(k, quickpow(2, r + 1, p - 1), p) - 1;
  y = (y + p) % p;
  y = y * quickpow(x, p - 2, p) % p;
  return y;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%I64d %I64d %I64d %I64d", &k, &l, &r, &p);
    long long int ans;
    if (p == 2) {
      if (k % 2 == 1) {
        printf("0\n");
      } else {
        printf("1\n");
      }
    } else {
      ans = sum();
      if (k % 2) {
        ans = ans * quickpow(quickpow(2, r - l, p), p - 2, p) % p;
      }
      printf("%I64d\n", ans);
    }
  }
}
