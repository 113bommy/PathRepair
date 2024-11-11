#include <bits/stdc++.h>
using namespace std;
int calc(int a1, int a2, int a3, int a4, int x3, int y4) {
  if (a3 == 0) {
    if (a4 == 0) {
      if (a2 == 0) {
        return a1 - x3 - y4;
      } else {
        if (a2 < y4) {
          y4 -= a2;
          a2 = 0;
          return calc(a1, a2, a3, a4, x3, y4);
        }
        a2 -= y4;
        if (a2 > x3) {
          a2 -= x3;
          return 2 * a2 + a1;
        } else {
          a1 -= (x3 - a2);
          return a1;
        }
      }
    } else {
      if (a4 < y4) return calc(a1, a2, a3, 0, x3, y4 - a4);
      a4 -= y4;
      y4 = 0;
      if (a2 > a4) return calc(a1, a2 - a4, a3, 0, x3 - 2 * a4, y4) + a4;
      if (a2 == 0) {
        if (a4 % 2 == 0)
          return calc(a1 - a4 / 2, 0, 0, 0, x3 - (a4 + a4 / 2), 0) + a4;
        return calc(a1 - a4 / 2 - 1, 1, 0, 0, x3 - (a4 + a4 / 2), 0) + a4;
      } else
        return calc(a1, 0, a3, a4 - a2, x3 - 2 * a2, y4) + a2;
    }
  } else {
    if (a4 == 0) {
      if (x3 > a3) return calc(a1, a2, 0, a4, x3 - a3, y4);
      a3 -= x3;
      x3 = 0;
      if (a3 > y4) {
        a3 -= y4;
        return a1 + 2 * a2 + 3 * a3;
      } else if (a3 + a2 > y4) {
        a2 -= (y4 - a3);
        a3 = 0;
        return a1 + 2 * a2 + 3 * a3;
      } else {
        a1 -= (y4 - a2 - a1);
        a2 = 0;
        a3 = 0;
        return a1 + 2 * a2 + 3 * a3;
      }
    } else {
      if (a3 < x3) return calc(a1, a2, 0, a4, x3 - a3, y4);
      return calc(a1, a2, a3, 0, x3, y4 - a4);
    }
  }
  return 1000000000;
}
int main() {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  int a = 0, b = 0, c = 0, d = 0;
  int tot = 0;
  int ans = 1000000000;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    tot += x;
    if (x == 1) a++;
    if (x == 2) b++;
    if (x == 3) c++;
    if (x == 4) d++;
  }
  for (int x = 0; x <= n; ++x)
    if (tot - 3 * x >= 0 && (tot - 3 * x) % 4 == 0) {
      int a1 = a, a2 = b, a3 = c, a4 = d;
      int x3 = x;
      int y4 = (tot - 3 * x) / 4;
      int mans = calc(a1, a2, a3, a4, x3, y4);
      ans = min(ans, mans);
    }
  if (ans >= 1000000000)
    cout << "-1" << endl;
  else
    cout << ans << endl;
  return 0;
}
