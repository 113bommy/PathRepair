#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int m, n;
  cin >> n >> m;
  if (n >= m + 2) {
    cout << "-1" << endl;
    return 0;
  }
  if (2 * n + 2 < m) {
    cout << "-1" << endl;
    return 0;
  }
  int a = m - (n - 1);
  for (int i = 0; i < n + 1; i++) {
    if (a >= 2 && (i == 0 || i == n)) {
      cout << "11";
      a -= 2;
    } else if (a >= 1) {
      cout << "1";
      a -= 1;
    }
    if (i > 0 && i < n) cout << "1";
    if (i < n) cout << "0";
  }
  return 0;
}
