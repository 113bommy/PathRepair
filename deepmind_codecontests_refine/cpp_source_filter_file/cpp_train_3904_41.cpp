#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    if ((1 <= x && x <= 4) || (n - 3 <= x && x <= n) || (1 <= y && y <= 4) ||
        (m - 3 <= y && y <= m)) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
