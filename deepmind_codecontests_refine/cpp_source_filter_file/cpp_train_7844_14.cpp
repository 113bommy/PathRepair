#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
  int n;
  int ans = 0;
  cin >> n;
  if (n < 3 || n % 2 == 0)
    cout << "-1" << endl;
  else {
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i > 0; i--) {
      ans += max(a[i], a[i - 1]);
      a[(i - 1) / 2] -= max(a[i], a[i - 1]);
      a[i] = 0;
      a[i - 1] = 0;
      if (a[(i - 1) / 2] < 0) a[(i - 1) / 2] = 0;
    }
    cout << ans << endl;
  }
  return 0;
}
