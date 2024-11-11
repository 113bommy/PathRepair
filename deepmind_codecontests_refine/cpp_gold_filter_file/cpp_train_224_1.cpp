#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535897932238460;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    long long c = 0, d = 1000000001;
    int n;
    cin >> n;
    if (n == 1) {
      cin >> a >> b;
      cout << 0 << "\n";
    } else {
      while (n--) {
        cin >> a >> b;
        if (a > c) c = a;
        if (b < d) d = b;
      }
      if (c - d < 0)
        cout << 0 << "\n";
      else
        cout << c - d << "\n";
    }
  }
  return 0;
}
