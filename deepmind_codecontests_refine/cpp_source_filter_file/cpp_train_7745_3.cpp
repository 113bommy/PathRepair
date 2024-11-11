#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9, PI = 2 * acos(0.0);
const int maxn = 2 * 100000 + 10, MOD = 1000 * 1000 * 1000 + 7,
          INF = 1000 * 1000 * 1000;
int x[100011], y[100011];
int main() {
  ios_base::sync_with_stdio(false);
  int te, j;
  int n;
  while (cin >> n) {
    int a, b;
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    sort(x, x + n);
    n = distance(x, unique(x, x + n));
    sort(x, x + n);
    cin >> a >> b;
    int cnt = 0;
    while (a != b) {
      int maxi = INF + 5000;
      j = 0;
      for (int i = 0; i < n; i++) {
        if (a < x[i]) {
          n = i;
          break;
        }
        if (a / x[i] == b / x[i] && b % x[i] != 0) {
          te++;
        } else {
          x[i] = x[j++];
          if (a - (a % x[i]) >= b && a - (a % x[i]) < maxi) {
            maxi = a - (a % x[i]);
          }
        }
      }
      if (a - 1 >= b && a - 1 < maxi) maxi = a - 1;
      a = maxi;
      cnt++;
      n = j;
    }
    cout << cnt << endl;
  }
  return 0;
}
