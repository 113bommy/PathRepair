#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    int max_number = (max(a, b) - min(a, b) + abs(a - b));
    if (c > max_number || a > max_number || b > max_number) {
      cout << -1 << endl;
      continue;
    }
    if (c == a) {
      cout << b << endl;
      continue;
    }
    if (c == b) {
      cout << a << endl;
      continue;
    }
    if (c <= max_number / 2) {
      c += max_number / 2;
      if (c <= max_number)
        cout << c << endl;
      else
        cout << -1 << endl;
    } else {
      c -= max_number / 2;
      if (c >= 1)
        cout << c << endl;
      else
        cout << -1 << endl;
    }
  }
}
