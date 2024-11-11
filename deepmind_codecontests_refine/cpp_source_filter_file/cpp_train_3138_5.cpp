#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum, ans, p;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) sum += a[i];
  ans = sum;
  for (int i = 2; i <= 100; i++) {
    int f1 = 0;
    p = sum;
    for (int j = n - 1; j; j--) {
      if (!f1 && !(a[j] % i)) {
        p -= a[j];
        p += a[j] / i;
        f1 = 1;
        p -= a[0];
        p += a[0] * i;
        break;
      }
    }
    if (f1) {
      ans = min(ans, p);
    }
  }
  cout << ans;
}
