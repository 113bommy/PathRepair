#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, v, z;
  cin >> n >> m >> v;
  if (m < n - 1 || m > (n - 1) * (n - 2) / 2 + 1) {
    cout << -1;
    return 0;
  }
  m = m - n + 1;
  v == 1 ? z = n : z = 1;
  for (int i = 1; i <= n; i++) {
    if (i == v)
      for (int j = 1; j <= n; j++) {
        if (v != j) cout << v << " " << j << endl;
      }
    else {
      if (i < v) {
        for (int j = i + 1; j <= n; j++)
          if (j != z && i != z && j != v && i != v) {
            if (m == 0) break;
            cout << i << " " << j << endl;
            m--;
          }
      } else {
        for (int j = i + 1; j <= n; j++)
          if (j != z && i != z && j != v && i != v) {
            if (m == 0) break;
            cout << i << " " << j << endl;
            m--;
          }
      }
    }
    if (m == 0 && i >= v) break;
  }
}
