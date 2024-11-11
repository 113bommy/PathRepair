#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ans = 0, x, y, m, a[10000];
  cin >> x >> y >> m;
  if (x > y) swap(x, y);
  if (x >= m || y >= m) {
    cout << 0 << endl;
    return 0;
  }
  if (x <= 0 && y <= 0 && m < 0) {
    if (x > m || y > m) {
      cout << 0 << endl;
      return 0;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  if (x >= 0 && y >= 0 && m < 0) {
    cout << -1 << endl;
    return 0;
  }
  if (x <= 0 && y <= 0 && m > 0) {
    cout << -1 << endl;
    return 0;
  }
  if (x < 0) {
    long long diff = 0 - x;
    long long diff1 = m - x;
    if (diff1 <= diff) {
      long long t1 = diff1 / y;
      ans += t1;
      x += (t1 * y);
      if (x < m) {
        cout << ++ans << endl;
        return 0;
      } else {
        cout << ans << endl;
        return 0;
      }
    }
    long long t = diff / y;
    ans += t;
    x += (t * y);
    if (x < 0) {
      x += y;
      ans++;
    }
  }
  if (x >= m) {
    cout << ans << endl;
    return 0;
  }
  a[1] = x;
  a[2] = y;
  for (int i = 3;; i++) {
    a[i] = a[i - 1] + a[i - 2];
    if (a[i] >= m) {
      ans += (i - 2);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
