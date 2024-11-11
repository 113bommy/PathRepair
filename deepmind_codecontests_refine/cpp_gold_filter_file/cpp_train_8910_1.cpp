#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, ans = 0, e = k, i, j;
  ;
  cin >> n >> k;
  int p = (n - k - 1);
  int q = p / k;
  int r = p % k;
  if (r == 1) ans = 1;
  if (r >= 2) ans = 2;
  ans += 1 + q;
  ans += q + 1;
  cout << ans << endl;
  int f1, f2;
  for (i = 1; i <= k; i++) {
    f1 = i;
    for (j = 0; j < q; j++) {
      f2 = n--;
      cout << f1 << " " << f2 << endl;
      f1 = f2;
    }
    if (r) {
      f2 = n--;
      r--;
      cout << f1 << " " << f2 << endl;
      f1 = f2;
    }
    cout << f1 << " " << k + 1 << endl;
  }
}
