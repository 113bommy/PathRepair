#include <bits/stdc++.h>
using namespace std;
long long a[1000000], b[1000000], i, j, k, m, n, p, t;
int main() {
  cin >> n >> t >> j;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  for (i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      p++;
      k = i;
      if (p == 1) m = i;
    }
  }
  m++;
  k++;
  if (m == t && k == j)
    cout << "TRUTH" << endl;
  else if (m == 1 && k == 1)
    cout << "TRUTH" << endl;
  else
    cout << "LIE" << endl;
  return 0;
}
