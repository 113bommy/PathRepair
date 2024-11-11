#include <bits/stdc++.h>
using namespace std;
int a, b, n, m, l, t;
bool check(int r) {
  if (a + 1ll * b * (r - 1) <= t &&
      (1ll * a * (r - l + 1) +
       1ll * b * (1ll * r * (r - 1) / 2 - 1ll * (l - 1) * (l - 2) / 2)) <=
          1ll * m * t)
    return 1;
  else
    return 0;
}
int main() {
  scanf("%d %d %d", &a, &b, &n);
  int res;
  while (n--) {
    scanf("%d %d %d", &l, &t, &m);
    res = l;
    if (check(res) == 0)
      cout << "-1" << endl;
    else {
      int low = l;
      int mid;
      int up = 1000100;
      while (low <= up) {
        mid = (low + up) / 2;
        if (check(mid) == 1) {
          res = mid;
          low = mid + 1;
        } else {
          up = mid - 1;
        }
      }
      printf("%d", res);
    }
  }
  return 0;
}
