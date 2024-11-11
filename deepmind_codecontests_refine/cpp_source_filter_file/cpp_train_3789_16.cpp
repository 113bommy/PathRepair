#include <bits/stdc++.h>
using namespace std;
int a[100000], i, n, m;
long long x, y, s, v, vv;
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; ++i) cin >> a[i];
  for (i = 0; i < m; i++) {
    cin >> x;
    if (x == 1) {
      cin >> v >> vv;
      a[v] = vv;
    } else if (x == 2) {
      cin >> y;
      s += y;
    } else {
      cin >> y;
      cout << a[y] + s << "\n";
    }
  }
}
