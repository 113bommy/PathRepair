#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, i, j, a, b, c, k, A, B, C;
  long long int mn = 100000000000, tmp;
  cin >> a >> b >> c;
  for (i = 1; i <= 20000; i++) {
    for (j = i; j <= 20000; j += i) {
      for (k = j; k <= 20000; k += j) {
        tmp = abs(a - i) + abs(b - j) + abs(c - k);
        if (tmp < mn) {
          mn = tmp;
          A = i, B = j, C = k;
        }
      }
    }
  }
  cout << mn << endl;
  cout << A << " " << B << " " << C << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
