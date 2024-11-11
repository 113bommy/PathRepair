#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
long s, d[200001], minus1[200001];
void deriv(int x, int y) {
  d[y] += y - 1;
  minus1[y + 1] -= 1;
  minus1[x] += 1;
  d[x] += 2 * y - x;
}
int main() {
  cin >> n >> m;
  cin >> x;
  for (size_t i = 1; i < m; i++) {
    cin >> y;
    if (x == y) continue;
    if (x > y) {
      deriv(x, y);
      s += x - y;
    } else {
      deriv(y, x);
      s += y - x;
    }
    x = y;
  }
  for (size_t i = 1; i <= n; i++) {
    s += minus1[i];
    cout << s + d[i] << ' ';
  }
}
