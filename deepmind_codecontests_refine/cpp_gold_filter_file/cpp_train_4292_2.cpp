#include <bits/stdc++.h>
using namespace std;
long long t, n, z, x, c, s;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    long long f = 0;
    for (int i = 2; i * i <= n; i++) {
      for (int j = i + 1; j * j <= (n / i); j++) {
        z = i * j;
        x = n / z;
        s = i * j * x;
        if (s == n) {
          if (i != j && i != x && j != x) {
            f = 1;
            cout << "YES"
                 << "\n";
            cout << i << " " << j << " " << x << "\n";
            break;
          } else
            continue;
        }
      }
      if (f == 1) break;
    }
    if (f == 0)
      cout << "NO"
           << "\n";
  }
}
