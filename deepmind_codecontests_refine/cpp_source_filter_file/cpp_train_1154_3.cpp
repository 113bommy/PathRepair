#include <bits/stdc++.h>
int main() {
  long long n, m;
  scanf("%I64d%I64d", &n, &m);
  long long bf = 0, s = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%I64", &x);
    s += x;
    printf("%d ", s / m - bf);
    bf = s / m;
  }
  return 0;
}
