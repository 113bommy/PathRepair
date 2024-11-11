#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i = 0, j, x, a[100], b[100], p = 0, q = 0, s = -100, m;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> x;
    a[i] = x;
  }
  for (i = 0; i <= k; i++) {
    for (j = 0; j < n; j++) {
      if ((j + 2) % (k) == 0) continue;
      if (a[j] == 1)
        p++;
      else
        q++;
    }
    m = abs(p - q);
    p = 0;
    q = 0;
    if (m >= s) s = m;
  }
  cout << s << endl;
}
