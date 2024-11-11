#include <bits/stdc++.h>
long long expxs(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
long long inv(long long a, long long b) {
  return expxs(expxs(a, 1000000007 - 2), b);
}
int k;
long long ar[100005];
int main() {
  int even, i, j, all1 = 1;
  scanf("%d", &k);
  even = 0;
  long long x = 2;
  for (i = 0; i < k; i++) {
    scanf("%lld", ar + i);
    if (ar[i] & 1 == 0) {
      even = 1;
    }
    if (ar[i] != 1) all1 = 0;
    x = expxs(x, ar[i]);
  }
  if (all1) {
    printf("0/1\n");
    return 0;
  }
  x = (x * inv(2, 1)) % 1000000007;
  long long y;
  if (!even) {
    y = (x + 1) % 1000000007;
  } else {
    y = (x - 1 + 1000000007) % 1000000007;
  }
  y = (y * inv(3, 1)) % 1000000007;
  printf("%lld/%lld\n", y, x);
  return 0;
}
