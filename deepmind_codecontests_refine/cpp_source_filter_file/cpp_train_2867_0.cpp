#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-9;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int main(int argc, char const *argv[]) {
  int n, m, a, b, c, d;
  cin >> n >> m >> a >> b >> c >> d;
  if (m < n + 1) {
    cout << -1 << endl;
    return 0;
  } else {
    if (n = 4) {
      cout << -1 << endl;
      return 0;
    }
    cout << a << " " << c << " ";
    for (int i = 1; i <= n; ++i) {
      if (i != a && i != b && i != c && i != d) {
        cout << i << " ";
      }
    }
    cout << d << " " << b << endl;
    cout << c << " " << a << " ";
    for (int i = 1; i <= n; ++i) {
      if (i != a && i != b && i != c && i != d) {
        cout << i << " ";
      }
    }
    cout << b << " " << d << endl;
  }
  return 0;
}
