#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int cs = 1; cs <= t; cs++) {
    int a, b, c, A, B, C;
    cin >> a >> b >> c;
    int res = INT_MAX;
    for (int i = 1; i <= 10000; i++) {
      for (int j = i; j <= 10000; j += i) {
        for (int k = j; k <= 10000; k += j) {
          if (res > abs(a - i) + abs(b - j) + abs(c - k)) {
            res = abs(a - i) + abs(b - j) + abs(c - k);
            A = i;
            B = j;
            C = k;
          }
        }
      }
    }
    cout << res << endl;
    cout << A << " " << B << " " << C << endl;
  }
}
