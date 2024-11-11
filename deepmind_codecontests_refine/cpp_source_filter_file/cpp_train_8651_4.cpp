#include <bits/stdc++.h>
int gcd(int a, int b) { return b ? a : gcd(b, a % b); }
int main() {
  int la, ra, ta, lb, rb, tb;
  scanf("%d%d%d", &la, &ra, &ta), ++ra;
  scanf("%d%d%d", &lb, &rb, &tb), ++rb;
  int g = gcd(ta, tb);
  ra -= la / g * g, la %= g;
  rb -= lb / g * g, lb %= g;
  if (lb > la) lb -= g, rb -= g;
  int ans = 0;
  ans = std::max(ans, std::min(ra, rb) - std::max(la, lb));
  lb += g, rb += g;
  ans = std::max(ans, std::min(ra, rb) - std::max(la, lb));
  printf("%d\n", ans);
  return 0;
}
