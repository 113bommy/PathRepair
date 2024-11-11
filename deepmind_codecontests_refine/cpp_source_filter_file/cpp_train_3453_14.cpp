#include <bits/stdc++.h>
using namespace std;
long long n, a[100002], s[4];
int main() {
  cin >> n;
  int m = 0, ps = 100001;
  long long d;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  if (a[1] == 0 && a[2] == 0) {
    cout << "cslnb";
    return 0;
  }
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i + 1]) {
      ++i;
      ++s[2];
      ps = i - 1;
    }
    if (a[i] == a[i + 1]) {
      cout << "cslnb";
      return 0;
    }
  }
  if (s[2] > 1) {
    cout << "cslnb";
    return 0;
  }
  if (a[ps] == ps - 1 && ps != 100002) {
    cout << "cslnb";
    return 0;
  }
  if (ps != 100002)
    for (int i = 1; i <= n; ++i)
      if (a[ps] == a[i] + 1) {
        cout << "cslnb";
        return 0;
      }
  for (int i = 1; i <= n; ++i) {
    d += a[i] - i + 1;
  }
  if (d % 2 == 1) {
    cout << "cslnb";
    return 0;
  } else {
    cout << "sjfnb";
    return 0;
  }
  return 0;
}
