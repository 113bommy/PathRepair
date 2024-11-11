#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, v;
  cin >> n >> m >> v;
  if (m < n - 1) {
    cout << -1;
    return 0;
  }
  if (m > ((n - 1) * (n - 2)) / 2) {
    cout << -1;
    return 0;
  }
  if (v != n) {
    for (int i = 1; i < n - 1; i++) cout << i << " " << i + 1 << endl;
    m -= n - 2;
    cout << v << " " << n << endl;
    m--;
    for (int i = 1; i < n - 1 && m; i++) {
      for (int j = i + 2; j < n && m; j++) {
        cout << i << " " << j << endl;
        m--;
      }
    }
  } else if (v == n) {
    for (int i = 2; i < n; i++) cout << i << " " << i + 1 << endl;
    m -= n - 2;
    cout << 1 << " " << v << endl;
    m--;
    for (int i = n; i > 1 && m; i--) {
      for (int j = i - 2; j > 2 && m; j--) {
        cout << i << " " << j << endl;
        m--;
      }
    }
  }
}
