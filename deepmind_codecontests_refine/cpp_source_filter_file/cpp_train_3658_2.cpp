#include <bits/stdc++.h>
using namespace std;
long long int p[40];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int q, ans, y, sum, x, k;
  p[0] = 1;
  for (long long int i = 1; i < 40; i++) p[i] = p[i - 1] + p[i - 1];
  cin >> q;
  while (q--) {
    cin >> x;
    y = 0;
    sum = 0;
    ans = 0;
    k = 0;
    for (long long int i = x; i > 0; i /= 2) y++, sum += (i % 2 == 1);
    if (y == sum) {
      for (long long int i = 2; i * i <= y; i++) {
        if (y % i == 0) {
          cout << (y / i) << endl;
          k = 1;
          break;
        }
      }
      if (!k) {
        cout << 1 << endl;
      }
    } else {
      ans = p[y] - 1;
      cout << ans << endl;
    }
  }
}
