#include <bits/stdc++.h>
using namespace std;
long long S, X, ans, sum;
void rip() {
  puts("0");
  exit(0);
}
int main() {
  scanf("%lld %lld", &S, &X);
  sum = X;
  for (long long i = 60; i--;)
    if (((1LL << i) & X) == 0) {
      if (sum + (1LL << (i + 1)) <= S) sum += (1LL << (i + 1));
    }
  if (sum != S) rip();
  long long n = (long long)__builtin_popcountll(X);
  ans = (1LL << n);
  if (sum == X) ans -= 2;
  printf("%lld\n", ans);
  return 0;
}
