#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, x, y, p = 0, z = 5;
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    cin >> x >> y;
    if (x < 1 + z || x > n - z || y < 1 + z || y > m - z) {
      p = 1;
    }
  }
  if (p)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
