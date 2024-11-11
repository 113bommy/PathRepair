#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> n >> m;
  if (m == 3 && (n == 5 || n == 6))
    cout << -1 << endl;
  else {
    for (int i = 0; i < m; i++) {
      cout << i << " " << i * i << endl;
    }
    for (int i = m; i < n; i++) {
      cout << m - i + 3 << " " << -(m - i + 3) * (m - i + 3) - 100000 << endl;
    }
  }
  return 0;
}
