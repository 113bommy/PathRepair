#include <bits/stdc++.h>
using namespace std;
int f(int n) {
  int r = 0;
  while (n) {
    r++;
    n /= 10;
  }
  return r;
}
int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  if (n == 1000000000) {
    n--;
    ans += 10;
  }
  int dig = f(n);
  long long mul = 9;
  for (int i = 1; i < dig; i++) {
    ans += i * mul;
    mul *= 10;
  }
  n -= (mul / 9);
  ans += dig * 1LL * (n + 1);
  printf("%lld\n", ans);
  return 0;
}
