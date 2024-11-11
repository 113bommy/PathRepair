#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
  cin.sync_with_stdio(false), cin.tie(0);
  cin >> a >> b >> c >> d;
  for (long long i = 1; i <= 200; ++i) {
    for (long long j = 1; j <= 200; ++j) {
      for (long long k = 1; k <= 200; ++k) {
        if (i <= j || j <= k) continue;
        if (i >= a && i <= 2 * a && j >= b && j <= 2 * b && k >= c &&
            k <= 2 * c) {
          if (k >= d && 2 * d >= k && 2 * d < i && 2 * d < j) {
            cout << i << endl;
            cout << j << endl;
            cout << k << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << -1 << endl;
}
