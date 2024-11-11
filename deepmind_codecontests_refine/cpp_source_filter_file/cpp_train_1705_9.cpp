#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n < m) {
    cout << n + 1 << endl;
    for (int i = 0; i <= n; i++) {
      cout << i << " " << i + 1 << endl;
    }
  } else if (m < n) {
    cout << m + 1 << endl;
    for (int i = 0; i <= m; i++) {
      cout << i + 1 << " " << i << endl;
    }
  } else {
    cout << n + 1 << endl;
    for (int i = 0; i < n; i++) {
      cout << i << " " << i + 1 << endl;
    }
    cout << n << " " << 0 << endl;
  }
  return 0;
}
