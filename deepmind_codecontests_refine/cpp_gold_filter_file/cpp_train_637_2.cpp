#include <bits/stdc++.h>
using namespace std;
int main() {
  long long s, pp = 0, qq = 0, i, n, a[100000], m, b[100000], p = 0, q = 0;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      p++;
    } else {
      q++;
    }
  }
  for (i = 0; i < m; i++) {
    if (b[i] % 2 == 0) {
      pp++;
    } else {
      qq++;
    }
  }
  s = min(p, qq) + min(q, pp);
  cout << s << endl;
}
