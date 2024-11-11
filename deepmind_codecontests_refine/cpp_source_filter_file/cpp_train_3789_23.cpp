#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, i, t, c = 0, x, y, z;
  cin >> n >> m;
  long long a[n + 1];
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 0; i < m; i++) {
    cin >> t >> x;
    if (t == 1) {
      cin >> y;
      a[x] = a[y];
    }
    if (t == 2) c += x;
    if (t == 3) cout << a[x] + c << endl;
  }
  return 0;
}
