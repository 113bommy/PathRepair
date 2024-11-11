#include <bits/stdc++.h>
using namespace std;
bool b[10000], vec = true;
int main() {
  int n, sum = 0, ans = 0, k = 0, l = 0;
  cin >> n;
  int a[n + 1];
  for (int i(1); i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (n == 1) {
    cout << 0;
    return 0;
  }
  while (sum > 0) {
    if (vec) {
      for (int i(1); i <= n; i++) {
        if (k >= a[i] && !b[i]) {
          k++;
          b[i] = true;
          sum -= a[i];
          a[i] = 0;
        }
        l++;
      }
    } else {
      for (int i(n); i >= 1; i--) {
        if (k >= a[i] && !b[i]) {
          k++;
          b[i] = true;
          sum -= a[i];
          a[i] = 0;
        }
        l--;
      }
    }
    if (l == n && sum != 0) vec = false;
    if (l == 0 && sum != 0) vec = true;
    ans++;
  }
  cout << ans - 1 << endl;
  return 0;
}
