#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    if (d <= n) {
      cout << "YES" << endl;
    } else {
      int x = sqrt(d);
      int x2 = x - 1;
      int x1, x3;
      if (d % (x + 1) != 0) {
        x1 = (d / (x + 1)) + 1;
      } else {
        x1 = d / (x + 1);
      }
      if (d % (x2 + 1) != 0) {
        x3 = (d / (x2 + 1)) + 1;
      } else {
        x3 = d / (x2 + 1);
      }
      if (x + x1 <= n || x2 + x3 <= n) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}
