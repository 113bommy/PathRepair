#include <bits/stdc++.h>
using namespace std;
const long long mxn = 1e5 + 7;
int main() {
  int n, a[mxn], q, l[mxn], r[mxn], x;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      l[i] = 1;
      r[i] = a[i];
    } else {
      l[i] = r[i - 1] + 1;
      r[i] = a[i] + r[i - 1];
    }
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int l1 = 0, r1 = n, x;
    cin >> x;
    while (r1 - l1 > 1) {
      int m = (l1 + r1) >> 1;
      if (r[m] > x)
        r1 = m;
      else
        l1 = m;
    }
    cout << r1 << endl;
  }
}
