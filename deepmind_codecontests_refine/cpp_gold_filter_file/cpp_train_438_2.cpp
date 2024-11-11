#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, k, t, b, c, g, n, m, flag, p, q, r, l, x, y, z;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int a[n];
    unordered_set<long long int> s;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) {
      r = ((a[i]) % n + n) % n;
      k = (i + r) % n;
      s.insert(k);
    }
    if (s.size() == n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
