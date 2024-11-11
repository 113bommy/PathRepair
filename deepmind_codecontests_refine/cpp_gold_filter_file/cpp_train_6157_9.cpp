#include <bits/stdc++.h>
using namespace std;
char s[100010];
long long changex[100010];
long long changey[100010];
int main() {
  long long x, y;
  long long dx, dy;
  long long n, ans = 0x3f3f3f3f3f3f3f3f;
  scanf("%lld%lld", &x, &y);
  scanf("%lld%lld", &dx, &dy);
  scanf("%lld", &n);
  scanf("%s", s);
  long long distancex = dx - x;
  long long distancey = dy - y;
  if (s[0] == 'U') {
    changex[0] = 0;
    changey[0] = 1;
  }
  if (s[0] == 'D') {
    changex[0] = 0;
    changey[0] = -1;
  }
  if (s[0] == 'L') {
    changex[0] = -1;
    changey[0] = 0;
  }
  if (s[0] == 'R') {
    changex[0] = 1;
    changey[0] = 0;
  }
  for (long long i = 1; i < n; i++) {
    if (s[i] == 'U') {
      changex[i] = changex[i - 1];
      changey[i] = changey[i - 1] + 1;
    }
    if (s[i] == 'D') {
      changex[i] = changex[i - 1];
      changey[i] = changey[i - 1] - 1;
    }
    if (s[i] == 'L') {
      changex[i] = changex[i - 1] - 1;
      changey[i] = changey[i - 1];
    }
    if (s[i] == 'R') {
      changex[i] = changex[i - 1] + 1;
      changey[i] = changey[i - 1];
    }
  }
  long long k;
  long long l = 0;
  long long r = 1e10;
  while (l < r - 1) {
    k = (l + r) / 2;
    long long tmpp = abs(distancex - changex[n - 1] * k) +
                     abs(distancey - changey[n - 1] * k);
    long long remain = max(tmpp - n * k, 0ll);
    if (remain == 0) {
      r = k;
    } else {
      l = k;
    }
  }
  k = l;
  for (long long i = 0; i < n; i++) {
    long long tmp = abs(distancex - changex[i] - changex[n - 1] * k) +
                    abs(distancey - changey[i] - changey[n - 1] * k);
    if (tmp <= i + 1 + n * k) {
      ans = i + 1 + n * k;
      break;
    }
  }
  if (ans == 0x3f3f3f3f3f3f3f3f) ans = -1;
  printf("%lld", ans);
}
