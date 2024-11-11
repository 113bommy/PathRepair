#include <bits/stdc++.h>
using namespace std;
int n, ans, a[5], x, s;
int main() {
  cin >> n;
  while (n--) {
    cin >> x;
    a[x]++, s += x;
  }
  if (s < 3 || s == 5) {
    cout << "-1";
    return 0;
  }
  ans += x = a[1] < a[2] ? a[1] : a[2];
  a[1] -= x, a[2] -= x, a[3] += x;
  if (a[1]) {
    ans += 2 * (x = a[1] / 3);
    a[2] -= x * 3;
    a[3] += x;
    if (a[1]) {
      if (a[1] == 1 && a[3])
        ans++;
      else
        ans += 2;
    }
  } else {
    ans += 2 * (x = a[2] / 3);
    a[2] -= x * 3;
    a[3] += x * 2;
    if (a[2]) {
      if (a[2] == 1 && a[4])
        ans++;
      else
        ans += 2;
    }
  }
  cout << ans;
}
