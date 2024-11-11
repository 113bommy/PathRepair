#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, sum = 0;
  cin >> n >> m;
  int i, a[n + 1];
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (m--) {
    int t, x, y;
    cin >> t;
    if (t == 1) {
      cin >> x >> y;
      a[x] = (y - sum);
    } else if (t == 2) {
      cin >> x;
      sum += x;
    } else if (t == 3) {
      cin >> x;
      cout << a[x] + sum << "\n";
    }
  }
  return 0;
}
