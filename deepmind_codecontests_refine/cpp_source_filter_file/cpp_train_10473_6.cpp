#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, b;
  cin >> m >> b;
  long long sx = b * m, sy = b;
  long long y, my, p = -1;
  long double res = -1, mx;
  for (long long i = 0; i <= sx; i++) {
    y = (m * b - i) / m;
    mx = (y * (y + 1) * (i + 1) / 2) + (i * (i + 1) * (y + 1) / 2);
    if (mx > res) res = mx;
  }
  cout << res << endl;
}
