#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == d && b == c) {
      cout << a + b;
    } else if (a > d && c > b) {
      cout << max(a + b, c + d);
    } else if (a == d && c > b) {
      cout << c + d;
    } else if (a > d && c == b) {
      cout << a + b;
    }
    cout << "\n";
  }
}
