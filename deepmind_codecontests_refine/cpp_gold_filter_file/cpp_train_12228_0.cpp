#include <bits/stdc++.h>
using namespace std;
long long s, a, b, flag;
long long ans, ansx, ansy, atx, aty;
int main() {
  scanf("%I64d%I64d%I64d", &s, &a, &b);
  ans = 100000000000000ll;
  s *= 6;
  if (a * b >= s) {
    printf("%I64d\n%I64d %I64d\n", a * b, a, b);
    return 0;
  }
  if (a > b) {
    swap(a, b);
    flag = 1;
  }
  for (ansx = a; ansx * ansx <= s; ansx++) {
    ansy = s / ansx;
    if (ansx * ansy < s) ansy++;
    if (ansy > b)
      if (ansx * ansy < ans) {
        ans = ansx * ansy;
        atx = ansx;
        aty = ansy;
      }
  }
  printf("%I64d\n", ans);
  if (flag)
    printf("%I64d %I64d\n", aty, atx);
  else
    printf("%I64d %I64d\n", atx, aty);
}
