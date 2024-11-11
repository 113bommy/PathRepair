#include <bits/stdc++.h>
const int inf = (int)1e9;
const int mod = 1e9 + 7;
using namespace std;
int n, a[5], b[5], c[5], d[5];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= 4; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  for (int i = 1; i <= n; i++) {
    if (min(a[i], b[i]) + min(c[i], d[i]) <= n) {
      cout << i << " " << min(a[i], b[i]) << " "
           << min(c[i], d[i]) + n - (min(a[i], b[i]) + min(c[i], d[i]));
      return 0;
    }
  }
  cout << -1;
  return 0;
}
