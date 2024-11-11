#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int o = 0; o < t; o++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a >= 1 && b == 0 && c == 0 && d >= 0)) {
      if (a % 2 == 1)
        cout << "Ya Tidak Tidak Tidak\n";
      else
        cout << "Tidak Tidak Tidak Ya\n";
      continue;
    }
    if ((a == 0 && b >= 1 && c == 0 && d == 0)) {
      if (b % 2 == 1)
        cout << "Tidak Ya Tidak Tidak\n";
      else
        cout << "Tidak Tidak Ya Tidak\n";
      continue;
    }
    if ((a == 0 && b == 0 && c >= 1 && d == 0) ||
        (a == 0 && b >= 1 && c >= 1 && d == 0 && b % 2 == 0)) {
      cout << "Tidak Tidak Ya Tidak\n";
      continue;
    }
    if ((a == 0 && b == 0 && c == 0 && d >= 1) ||
        (a >= 1 && b == 0 && c == 0 && d >= 1 && a % 2 == 0)) {
      cout << "Tidak Tidak Tidak Ya\n";
      continue;
    }
    if ((a + b) % 2 == 1) {
      cout << "Ya Ya Tidak Tidak\n";
      continue;
    } else {
      cout << "Tidak Tidak Ya Ya\n";
      continue;
    }
  }
  return 0;
}
