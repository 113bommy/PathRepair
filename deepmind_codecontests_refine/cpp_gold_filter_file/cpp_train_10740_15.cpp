#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long q;
  cin >> q;
  while (q--) {
    long long i, j, b, w;
    cin >> b >> w;
    if (w > b) {
      if (w > 3 * b + 1) {
        cout << "NO\n";
        continue;
      }
      cout << "YES\n";
      i = 1;
      while (b) {
        cout << i << " 3\n";
        if (i & 1)
          w--;
        else
          b--;
        i++;
      }
      if (w) {
        cout << i << " 3\n";
        w--;
        i++;
      }
      j = i - 1;
      i = 2;
      while (w && i <= j) {
        cout << i << " 2\n";
        i += 2;
        w--;
      }
      i = 2;
      while (w && i <= j) {
        cout << i << " 4\n";
        i += 2;
        w--;
      }
    } else {
      if (b > 3 * w + 1) {
        cout << "NO\n";
        continue;
      }
      cout << "YES\n";
      i = 1;
      while (w) {
        cout << i << " 2\n";
        if (i & 1)
          b--;
        else
          w--;
        i++;
      }
      if (b) {
        cout << i << " 2\n";
        b--;
        i++;
      }
      j = i - 1;
      i = 2;
      while (b && i <= j) {
        cout << i << " 1\n";
        i += 2;
        b--;
      }
      i = 2;
      while (b && i <= j) {
        cout << i << " 3\n";
        i += 2;
        b--;
      }
    }
  }
}
