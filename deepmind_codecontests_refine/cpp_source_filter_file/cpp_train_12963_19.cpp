#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long p, q, i, t, i1 = 0, i2 = 0, mx;
  char c;
  cin >> t;
  long long a[358], b[358];
  for (i = 0; i < 358; i++) {
    a[i] = 0;
    b[i] = 0;
  }
  for (i = 0; i < t; i++) {
    cin >> c >> p >> q;
    if (c == 'F') {
      b[p]++;
      b[q + 1]--;
    } else {
      a[p]++;
      a[q + 1]--;
    }
  }
  mx = 0;
  for (i = 0; i < 358; i++) {
    a[i] += a[i - 1];
    b[i] += b[i - 1];
    mx = max(mx, min(a[i], b[i]) * 2);
  }
  cout << mx << endl;
  return 0;
}
