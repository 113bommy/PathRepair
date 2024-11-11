#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  if (n == m + 1) {
    cout << 0;
    for (int i = 0; i < m; ++i) cout << 1 << 0;
  } else if ((n + 1) * 2 == m) {
    cout << 11;
    for (int i = 0; i < n; ++i) cout << 0 << 11;
  } else if ((n + 1) * 2 - 1 == m) {
    cout << 1;
    for (int i = 0; i < n; ++i) cout << 0 << 11;
  } else if ((n + 1) * 2 > m && n < m + 1) {
    for (int i = 0; i < n; ++i) {
      if (m-- > n)
        cout << 11 << 0;
      else
        cout << 1 << 0;
    }
  } else
    cout << -1;
}
