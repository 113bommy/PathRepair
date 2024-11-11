#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, a, j, b, m, s = 0, t = 0;
  int x[100] = {0};
  cin >> n >> m;
  for (i = 1; i <= m; ++i) {
    cin >> a;
    for (j = a; j <= n; ++j) {
      if (x[j] != 0) break;
      x[j] = a;
    }
  }
  for (i = 1; i <= n; ++i) cout << x[i] << " ";
  return 0;
}
