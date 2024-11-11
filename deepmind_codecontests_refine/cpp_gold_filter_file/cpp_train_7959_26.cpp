#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  long long int c, h;
  long long int a00, a01, a10, a11;
  long long int x, y;
  scanf("%lld%lld%lld", &n, &m, &c);
  int flag = 1;
  while (c--) {
    scanf("%lld%lld", &x, &y);
    if (flag) {
      flag = 0;
      a00 = x + y;
      a10 = -x + y;
      a01 = x - y;
      a11 = -x - y;
    } else {
      a00 = max(a00, x + y);
      a10 = max(a10, -x + y);
      a01 = max(a01, x - y);
      a11 = max(a11, -x - y);
    }
  }
  scanf("%lld", &h);
  long long int d = 1e16, cnt = 0, pos, mx;
  while (h--) {
    scanf("%lld%lld", &x, &y);
    cnt++;
    mx = max(max(x + y + a11, -x - y + a00), max(-x + y + a01, x - y + a10));
    if (mx < d) {
      d = mx;
      pos = cnt;
    }
  }
  printf("%lld\n%lld", d, pos);
  return 0;
}
