#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b, c, d;
int main() {
  long long n, m;
  while (cin >> n >> m) {
    if (m == 0) {
      cout << n << " " << n << endl;
      return 0;
    }
    int flag = 0;
    int i;
    for (i = 1; i <= n; i++) {
      if (i * (i - 1) / 2 >= m) {
        if (n > 2 * m) {
          cout << n - m * 2 << " " << n - i << endl;
          return 0;
        } else {
          cout << 0 << " " << n - i << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}
