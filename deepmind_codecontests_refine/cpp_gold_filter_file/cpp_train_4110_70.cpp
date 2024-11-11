#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    int u = max(3 * a / 10, a - (a * c) / 250);
    int v = max(3 * b / 10, b - (b * d) / 250);
    if (u < v) cout << "Vasya\n";
    if (u == v) cout << "Tie\n";
    if (u > v) cout << "Misha\n";
  }
  return 0;
}
