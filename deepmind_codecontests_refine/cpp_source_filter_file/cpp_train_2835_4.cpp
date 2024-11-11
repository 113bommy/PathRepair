#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long p, q;
  cin >> t;
  int i, n;
  while (t--) {
    t = 0;
    p = 0;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (i = 0; i < n; i++) {
      if (a[i] % 2 == 0) {
        q++;
      } else
        p++;
    }
    if (q == n || p == n) {
      cout << "YES"
           << "\n";
    } else
      cout << "NO"
           << "\n";
  }
}
