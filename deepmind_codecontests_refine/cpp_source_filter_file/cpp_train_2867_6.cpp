#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a, b, c, d;
  cin >> n >> k >> a >> b >> c >> d;
  if (n == 4 or k < n * 2 - 4) {
    cout << -1 << endl;
    return 0;
  }
  cout << a << " " << c;
  for (int i = 1; i < (int)n + 1; ++i)
    if (i != a and i != b and i != c and i != d) cout << " " << i;
  cout << " " << d << " " << b << endl;
  cout << c << " " << a;
  for (int i = 1; i < (int)n + 1; ++i)
    if (i != a and i != b and i != c and i != d) cout << " " << i;
  cout << " " << b << " " << d << endl;
  return 0;
}
