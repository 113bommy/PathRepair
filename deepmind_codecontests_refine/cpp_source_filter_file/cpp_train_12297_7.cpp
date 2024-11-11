#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
  long long i, j, k, l, r, co = 0;
  long long n, m, t, s, p;
  cin >> n;
  while (n--) {
    cin >> l >> r;
    m = r - l + 1;
    if (m % 2) {
      if (l % 2 == 0) {
        cout << m / 2 * (-1) - r << endl;
      } else {
        cout << m / 2 + r << endl;
      }
    } else {
      if (l % 2 == 0)
        cout << m / 2 << endl;
      else
        cout << m / 2 * (-1) << endl;
    }
  }
  return 0;
}
