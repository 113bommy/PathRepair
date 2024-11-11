#include <bits/stdc++.h>
using namespace std;
int main() {
  long int t;
  cin >> t;
  while (t--) {
    long long int n, m, x, a, b, i, m1, m2, s, e;
    cin >> n >> x >> m;
    m1 = x;
    m2 = x;
    s = x;
    e = x;
    while (m--) {
      cin >> a >> b;
      a = min(a, b);
      b = max(a, b);
      if ((a <= e && a >= s) || (b >= s && b <= e) || (a <= s && b >= e)) {
        m1 = min(m1, a);
        m2 = max(m2, b);
        s = m1;
        e = m2;
      }
    }
    cout << m2 - m1 + 1 << "\n";
  }
  return 0;
}
