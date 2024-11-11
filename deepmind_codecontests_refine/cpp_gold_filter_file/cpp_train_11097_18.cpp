#include <bits/stdc++.h>
using namespace std;
long long int fun(long long int x, long long int y, long long int a,
                  long long int k, long long int l) {
  long long int c[2][2], d[2][2], val, i, j, flag = 0, val1 = k, ans = 0, b = 0;
  if (x == 0 || y == 0) return 0;
  val = (x - 1) / a;
  if (val == 0) {
    c[1][0] = -1;
    c[0][0] = ((x - 1) % a == a - 1) ? 1 : 0;
    c[0][1] = (x - 1) % a + 1;
  } else {
    c[0][0] = 1;
    c[0][1] = a;
    c[1][0] = ((x - 1) % a == a - 1) ? 1 : 0;
    c[1][1] = (x - 1) % a + 1;
  }
  val = (y - 1) / a;
  if (val == 0) {
    d[1][0] = -1;
    d[0][0] = ((y - 1) % a == a - 1) ? 1 : 0;
    d[0][1] = (y - 1) % a + 1;
  } else {
    d[0][0] = 1;
    d[0][1] = a;
    d[1][0] = ((y - 1) % a == a - 1) ? 1 : 0;
    d[1][1] = (y - 1) % a + 1;
  }
  for (i = 0; i < 2; i++) {
    if (c[i][0] == -1) continue;
    for (j = 0; j < 2; j++) {
      if (d[j][0] == -1) continue;
      if (c[i][0] == 0 && d[j][0] == 0) {
        flag = 1;
        break;
      }
      val = min(c[i][1], d[j][1]);
      b = 0;
      if ((i ^ j) == 1) {
        if (a > k - 1)
          val1 = 0;
        else
          val1 = min(k - a, a);
        b = (a + l) % 1000000007;
      } else {
        val1 = min(a, k);
        b = l;
      }
      if ((val1 % 2) == 0)
        ans = (ans +
               (((val * (val1 + 1)) % 1000000007 * (val1 / 2)) % 1000000007 +
                ((val * b) % 1000000007 * val1) % 1000000007) %
                   1000000007) %
              1000000007;
      else
        ans = (ans +
               (((val * (val1)) % 1000000007 * ((val1 + 1) / 2)) % 1000000007 +
                ((val * b) % 1000000007 * val1) % 1000000007) %
                   1000000007) %
              1000000007;
    }
    if (flag == 1) break;
  }
  val = 0;
  if (flag == 1) {
    if ((i ^ j) == 1) {
      if (a <= k - 1) {
        val1 = k - 1 - a;
        val = fun((x - 1) % a + 1, (y - 1) % a + 1, a / 2, val1 + 1,
                  (l + a) % 1000000007);
      }
    } else {
      val1 = k - 1;
      val = fun((x - 1) % a + 1, (y - 1) % a + 1, a / 2, val1 + 1, l);
    }
  }
  return (ans + val) % 1000000007;
}
int main() {
  long long int q, x1, x2, y1, y2, k, ans, xmin, xmax, ymin, ymax, x;
  scanf("%lld", &q);
  while (q--) {
    scanf("%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &k);
    xmin = min(x1, x2);
    xmax = max(x1, x2);
    ymin = min(y1, y2);
    ymax = max(y1, y2);
    x = pow(2ll, 30ll);
    ans = (fun(xmax, ymax, x, k, 0) - fun(xmin - 1, ymax, x, k, 0) -
           fun(xmax, ymin - 1, x, k, 0) + fun(xmin - 1, ymin - 1, x, k, 0) +
           2 * 1000000007) %
          1000000007;
    printf("%lld\n", ans);
  }
  return 0;
}
