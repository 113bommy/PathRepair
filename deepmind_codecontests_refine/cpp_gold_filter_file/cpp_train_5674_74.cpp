#include <bits/stdc++.h>
using namespace std;
int i, j, a[101], n, m, b, t, val;
int main() {
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    b = 0, val = 0;
    for (j = 1; j <= n; j++) {
      cin >> t;
      if (t > b) {
        b = t;
        val = j;
      }
    }
    a[val]++;
  }
  b = 0;
  for (i = 0; i < n; i++) {
    t = a[i];
    if (t > b) {
      b = t;
      val = i;
    }
  }
  if (val == 0) val = 1;
  cout << val << endl;
}
