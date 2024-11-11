#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, d, a, b, r, l;
  cin >> t;
  while (t--) {
    d = 1;
    cin >> n >> a >> b;
    if (a == b && a + b <= n - 2 && d == 1) {
      d = 0;
      l = 1;
      r = n - 1;
      cout << n << " ";
      while (r >= n - a) {
        cout << l << " " << r << " ";
        l++;
        r--;
      }
      while (r >= l) {
        cout << r << " ";
        r--;
      }
      cout << endl;
    }
    if (a - 1 == b && a + b <= n - 2 && d == 1) {
      d = 0;
      l = 1;
      r = n;
      while (r >= n - a) {
        cout << l << " " << r << " ";
        l++;
        r--;
      }
      while (l <= r) {
        cout << l << " ";
        l++;
      }
      cout << endl;
    }
    if (a == b - 1 && a + b <= n - 2 && d == 1) {
      d = 0;
      l = 1;
      r = n;
      while (r >= n - a) {
        cout << r << " " << l << " ";
        l++;
        r--;
      }
      while (r >= l) {
        cout << l << " ";
        l++;
      }
      cout << endl;
    }
    if (d == 1) {
      cout << -1 << endl;
    }
  }
}
