#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int n = max(a - b, b - a);
    n += n;
    if (a > n || b > n || c > n)
      cout << -1 << endl;
    else {
      c -= n / 2;
      if (c <= 0) c += n;
      cout << c << endl;
    }
  }
  return 0;
}
