#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m = 1, k = 1, ans;
  cin >> n;
  int i = n - 1;
  while (i--) {
    ans = m + k;
    if (ans > n && ans > 10) {
      cout << ans - n << " ";
      ans = ans - m;
    } else if (ans > n && ans < 10) {
      cout << ans % n << " ";
      ans = ans % n;
    } else
      cout << ans << " ";
    m = ans;
    k++;
  }
  return 0;
}
