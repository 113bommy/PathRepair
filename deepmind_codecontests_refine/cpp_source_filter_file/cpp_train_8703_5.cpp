#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, n, m, t, a, b, c, d, shajib;
  cin >> a >> b >> c >> d >> t;
  c = c * t;
  d = d * t;
  shajib = a / t;
  if (b < c || d < a)
    cout << "NO" << endl;
  else if (shajib != a && shajib > b)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
