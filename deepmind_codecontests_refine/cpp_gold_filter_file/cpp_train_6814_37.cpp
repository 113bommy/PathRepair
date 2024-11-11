#include <bits/stdc++.h>
int main() {
  long long P, L, R;
  scanf("%lld", &P);
  L = P - (long long)1e18 % P * 9 % P * 9 % P;
  R = (long long)1e18 + L - 1;
  printf("%lld %lld\n", L, R);
  return 0;
}
