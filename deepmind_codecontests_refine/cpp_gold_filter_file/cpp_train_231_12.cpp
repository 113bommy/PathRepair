#include <bits/stdc++.h>
using namespace std;
int n, t;
int main() {
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cin >> n;
    int d2 = 0, d3 = 0;
    while (n % 2 == 0) {
      n /= 2;
      d2++;
    }
    while (n % 3 == 0) {
      n /= 3;
      d3++;
    }
    if (n != 1 || d3 < d2) {
      cout << -1 << '\n';
      continue;
    }
    cout << d3 + d3 - d2 << '\n';
  }
  return 0;
}
