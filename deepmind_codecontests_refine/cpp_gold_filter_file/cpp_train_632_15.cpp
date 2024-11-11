#include <bits/stdc++.h>
using namespace std;
long long n, k, a[1111];
int p;
int main() {
  if (0) {
    freopen("aaa.inp", "r", stdin);
    freopen("aaa.out", "w", stdout);
  };
  scanf("%I64d%I64d%d", &n, &k, &p);
  for (int i = 0; i < p; i++) scanf("%I64d", &a[i]);
  long long dt = k - n + k;
  if (dt < 0) dt = 0;
  n -= dt;
  k -= dt;
  if (n % 2 == 1 && k >= 1) n--, k--;
  for (int i = 0; i < p; i++) {
    long long c = a[i];
    if (c > n)
      printf("X");
    else if (c > n - k - k)
      if (c % 2 == 0)
        printf("X");
      else
        printf(".");
    else
      printf(".");
  }
  return 0;
};
