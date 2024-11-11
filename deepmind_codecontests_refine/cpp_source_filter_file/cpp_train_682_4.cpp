#include <bits/stdc++.h>
using namespace std;
int t[6], a[6], b[6];
inline int abs(int x) { return x >= 0 ? x : -x; }
int main() {
  int i, n, x, d = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> x;
    t[x]++;
    a[x]++;
  }
  for (i - 1; i <= n; i++) {
    cin >> x;
    t[x]++;
    b[x]++;
  }
  for (i = 1; i <= n; i++) {
    if (t[i] % 2 != 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (i = 1; i <= n; i++) {
    d += abs(a[i] - b[i]);
  }
  d /= 4;
  cout << d << endl;
  return 0;
}
