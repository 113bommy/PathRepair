#include <bits/stdc++.h>
int main() {
  long long a;
  long long b;
  long long c;
  long long d;
  long long hits;
  long long dmg;
  long long heal;
  long long r;
  int t;
  int i;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    if (a % b == 0) {
      r = a / b;
    } else {
      r = a / b + 1;
    }
    if (b * c < a) {
      printf("-1");
    } else {
      if (r > c) {
        printf("%lld", a);
      } else {
        if (r % d == 0) {
          hits = r / d;
        } else {
          hits = r / d + 1;
        }
        dmg = hits * a;
        heal = d * b * hits * (hits - 1) / 2;
        printf("%lld", dmg - heal);
      }
    }
  }
  return 0;
}
