#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int x, y, z, d, e, f;
  while (cin >> x >> y >> z >> d >> e >> f) {
    int ff = (abs(z - x) + abs(x - y)) * e + f * 3;
    int ss = (abs(x - y) * d);
    if (ff <= ss) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}
