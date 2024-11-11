#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimizer("O3")
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    int del = (y - x) / (a + b);
    if (del * (a + b) == x - y) {
      cout << del << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}
