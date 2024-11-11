#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, t, i, res;
  bool s;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a == b + 1) {
      s = 0;
      res = a + b;
      for (i = 2; i * i < res; i++) {
        if (res % i == 0) {
          s = 1;
          break;
        }
      }
      if (s)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
