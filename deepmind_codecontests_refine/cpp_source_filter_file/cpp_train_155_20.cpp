#include <bits/stdc++.h>
const int mmax = 1e6 + 10;
using namespace std;
int main() {
  long long n, s, a, b, c, d;
  while (cin >> n >> s) {
    cin >> a >> b >> c >> d;
    if (n > s - 1 || n == 4)
      cout << "-1" << endl;
    else {
      cout << a << " " << c << " ";
      for (int i = 1; i <= n; i++) {
        if (i != a && i != b && i != c && i != d) cout << i << " ";
      }
      cout << d << " " << b << endl;
      cout << c << " " << a << " ";
      for (int i = 1; i <= n; i++) {
        if (i != a && i != b && i != c && i != d) cout << i << " ";
      }
      cout << n << " " << d << endl;
    }
  }
  return 0;
}
