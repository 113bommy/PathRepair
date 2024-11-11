#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, x, y;
  long long n, s, m;
  cin >> n >> m >> s;
  if (s >= max(n, m))
    cout << n * m << endl;
  else {
    a = 1 + (n - 1) / s;
    x = n - (a - 1) * s;
    b = 1 + (m - 1) / s;
    y = m - (b - 1) * s;
    if (s >= n)
      cout << n * b * 2 << endl;
    else if (s >= m)
      cout << m * a * 2 << endl;
    else
      cout << x * y * a * b << endl;
  }
  return 0;
}
