#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (long long o = 0; o < t; o++) {
    long long a, b, c;
    cin >> a >> b >> c;
    if (b == 1 && c == a) {
      cout << -1 << " " << -1 << '\n';
    } else if (c <= a) {
      cout << -1 << " " << b << '\n';
    } else if (b == 1) {
      cout << 1 << " " << -1 << '\n';
    } else if (a * b <= c) {
      cout << 1 << " " << -1 << '\n';
    } else {
      cout << 1 << " " << b << '\n';
    }
  }
  return 0;
}
