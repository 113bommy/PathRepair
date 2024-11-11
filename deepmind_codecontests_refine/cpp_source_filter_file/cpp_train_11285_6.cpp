#include <bits/stdc++.h>
using namespace std;
int n, i, a[100666], j;
int main() {
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> a[i];
  for (i = 6; i >= 0; --i) {
    int value = (1 << 30) - 1;
    int nr = 0;
    for (j = 1; j <= n; ++j) {
      if (a[j] & (1 << i)) {
        value &= a[j];
        ++nr;
      }
    }
    if (nr > 0)
      if ((!(value & ((1 << i) - 1))) && value > 0) {
        cout << nr << '\n';
        for (j = 1; j <= n; ++j)
          if (a[j] & (1 << i)) cout << a[j] << " ";
        return 0;
      }
  }
  cout << -1;
  return 0;
}
