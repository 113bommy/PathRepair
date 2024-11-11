#include <bits/stdc++.h>
using namespace std;
long long a, b, x, y, t;
int main() {
  cin >> t;
  while (t) {
    t--;
    cin >> a >> b >> x >> y;
    cout << max(max(b * x, b * (a - x - 1)), max(a * y, a * (b - y - 1)))
         << '\n';
  }
  return 0;
}
