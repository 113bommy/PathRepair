#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, q, c = 0, x, y, i;
  cin >> n >> q;
  long long a[2][2 + n];
  for (i = 0; i <= n + 1; i++) a[0][i] = a[1][i] = 0;
  while (q--) {
    cin >> x >> y;
    x--;
    if (a[x][y]) {
      c -= a[1 - x][y - 1] + a[1 - x][y] + a[1 - x][y + 1];
      a[x][y] = 0;
    } else {
      c += a[1 - x][y - 1] + a[1 - x][y] + a[1 - x][y + 1];
      a[x][y] = 1;
    }
    if (c)
      cout << "No\n";
    else
      cout << "Yes\n";
  }
  return 0;
}
