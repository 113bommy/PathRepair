#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e, st, en;
  scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &e);
  if (a <= c && c <= b) {
    st = c;
    en = min(b, d);
  } else if (c <= a && a <= d) {
    st = a;
    en = min(b, d);
  } else if (a < c && d < b) {
    st = c;
    en = d;
  } else if (c <= a && b <= d) {
    st = a;
    en = b;
  } else {
    printf("0");
    return 0;
  }
  if (st <= e && e <= en) en--;
  printf("%d", en - st + 1);
  return 0;
}
