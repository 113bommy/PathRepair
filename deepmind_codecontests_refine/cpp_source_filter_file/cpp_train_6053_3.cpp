#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i, j, k, m, n, x, y;
  t = 1;
  while (t--) {
    long long int flag = 0;
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == d) {
      if (c > 0 && (a > 0 || b > 0)) {
        cout << "1";
        return 0;
      }
      if (c == 0) {
        cout << "1";
        return 0;
      }
    }
    cout << "0";
  }
  return 0;
}
