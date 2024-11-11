#include <bits/stdc++.h>
const long long mod = (long long)1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long e, f, g, h, i, j;
  cin >> e >> f >> g >> h >> i >> j;
  bool valid = false;
  for (long long a = 0; a <= 9; a++) {
    for (long long b = 0; b <= 9; b++) {
      for (long long c = 0; c <= 9; c++) {
        for (long long d = 0; d <= 9; d++) {
          if (a != b and a != c and a != d and b != c and b != d and c != d and
              a + d == i and b + c == j and a + b == e and c + d == f and
              a + c == g and b + d == h) {
            cout << a << " " << b << "\n" << c << " " << d << "\n";
            valid = true;
            break;
          }
        }
      }
    }
  }
  if (valid == false) {
    cout << -1 << "\n";
  }
  return 0;
}
