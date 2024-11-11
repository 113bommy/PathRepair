#include <bits/stdc++.h>
using namespace std;
long long n, i, s, z, z1, x, res, a[200007];
int main() {
  cin >> n >> s;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  if (a[n / 2 + 1] == s) {
    cout << 0 << endl;
    return 0;
  } else if (a[n / 2 + 1] < s) {
    for (i = n / 2 + 1; i <= n; i++) {
      if (a[i] < s) {
        res += s - a[i];
        a[i] = s;
      }
      if (a[i] >= s) {
        s = a[i];
      }
    }
  } else {
    for (i = n / 2 + 1; i >= 1; i--) {
      if (a[i] > s) {
        res += a[i] - s;
        a[i] = s;
      }
      if (a[i] <= s) {
        s = a[i];
      }
    }
  }
  cout << res << endl;
  return 0;
}
