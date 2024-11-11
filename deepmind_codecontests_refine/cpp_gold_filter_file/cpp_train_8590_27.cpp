#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, d, k, i;
  cin >> n >> d >> k;
  if (2 * k < d || (d == 1 && n != 2)) {
    cout << -1;
    return 0;
  }
  for (i = 1; i <= k; i++) {
    cout << i << " " << i + 1 << endl;
  }
  long long x = 1, y;
  for (i = 1; i <= d - k; i++) {
    y = i + k + 1;
    cout << x << " " << y << endl;
    x = y;
  }
  for (i = d + 2; i <= n; i++) {
    if (d == k)
      cout << 2 << " " << i << endl;
    else
      cout << 1 << " " << i << endl;
  }
}
