#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, i, s, n, p, j, x, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    map<long long, long long> a;
    for (i = 1; i <= n; i++) {
      cin >> x;
      a[x]++;
    }
    p = 0;
    for (j = 1; j <= m; j++) {
      cin >> x;
      if (a[x] > 0) p = x;
    }
    if (p == 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl << 0 << " " << p << endl;
  }
}
