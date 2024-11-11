#include <bits/stdc++.h>
using namespace std;
const int u = 1111;
long long n, m, k = u, l = u, r, a[u], b[u];
string s, t;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (i % 2 != 0) {
        cout << '#';
      } else {
        if ((i / 2) % 2 != 0) {
          if (j < m)
            cout << '.';
          else
            cout << '#';
        } else {
          if (j == 1)
            cout << '#';
          else
            cout << '.';
        }
      }
    }
    cout << "\n";
  }
  return 0;
}
