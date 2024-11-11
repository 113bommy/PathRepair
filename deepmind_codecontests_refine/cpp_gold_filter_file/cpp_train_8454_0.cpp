#include <bits/stdc++.h>
using namespace std;
string s;
long long int a[1000000], q, b, l, d, c, x, n, m, k, p, j, i, t;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) {
      p = p + a[i];
      if (a[i] == 0) q++;
    }
    p = p + q;
    if (p == 0) q = q + (p * (-1)) + 1;
    cout << q << endl;
    p = 0, q = 0;
  }
}
