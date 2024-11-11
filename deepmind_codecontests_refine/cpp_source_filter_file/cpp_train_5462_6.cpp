#include <bits/stdc++.h>
using namespace std;
int ex(int x, int b) {
  int ret = 0;
  while (x % b == 0) {
    x /= b;
    ret++;
  }
  return ret;
}
int main() {
  int a1, b1, a2, b2;
  cin >> a1 >> b1 >> a2 >> b2;
  int e31 = ex(a1, 3) + ex(b1, 3);
  int e32 = ex(a2, 3) + ex(b2, 3);
  int e3 = min(e31, e32);
  int ans = 0;
  while (e31 > e3) {
    ans++;
    if (a1 % 3 == 0) {
      a1 /= 3;
      a1 *= 2;
    } else {
      b1 /= 3;
      b1 *= 2;
    }
    e31--;
  }
  while (e32 > e3) {
    ans++;
    if (a2 % 2 == 0) {
      a2 /= 3;
      a2 *= 2;
    } else {
      b2 /= 3;
      b2 *= 2;
    }
    e32--;
  }
  int e21 = ex(a1, 2) + ex(b1, 2);
  int e22 = ex(a2, 2) + ex(b2, 2);
  int e2 = min(e21, e22);
  while (e21 > e2) {
    ans++;
    if (a1 % 2 == 0)
      a1 /= 2;
    else
      b1 /= 2;
    e21--;
  }
  while (e22 > e2) {
    ans++;
    if (a2 % 2 == 0)
      a2 /= 2;
    else
      b2 /= 2;
    e22--;
  }
  long long t1, t2;
  t1 = (long long)a1 * (long long)b1;
  t2 = (long long)a2 * (long long)b2;
  if (t1 != t2) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", ans);
  printf("%d %d\n%d %d\n", a1, b1, a2, b2);
  return 0;
}
