#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n < m) {
    cout << n + 1 << endl;
    for (int i = 0; i <= n; i++) {
      cout << i << " " << n - i << endl;
    }
  } else if (m < n) {
    cout << m + 1 << endl;
    for (int i = 0; i <= m; i++) {
      cout << m - i << " " << i << endl;
    }
  } else {
    cout << n + 1 << endl;
    for (int i = 0; i < n; i++) {
      cout << i << " " << n - i << endl;
    }
    cout << n << " " << 0 << endl;
  }
  return 0;
}
