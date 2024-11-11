#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, m, sm, t = 0;
  cin >> n >> m;
  sm = n * m;
  if (n > m) swap(n, m);
  if (n == 1) {
    t = m / 3 + (bool)(m % 3);
    cout << sm - t << endl;
    return 0;
  }
  if (n == 2) {
    cout << sm - m / 2 - 1 << endl;
    return 0;
  }
  if (n == 3) {
    t = !(m % 4);
    cout << sm - m / 4 * 3 - m % 4 - t << endl;
    return 0;
  }
  if (n == 4) {
    cout << sm - m - (m == 5 || m == 6 || m == 9) << endl;
    return 0;
  }
  if (n == 5 && m == 5) cout << 17 << endl;
  if (n == 5 && m == 6) cout << 22 << endl;
  if (n == 5 && m == 7) cout << 27 << endl;
  if (n == 5 && m == 8) cout << 29 << endl;
  if (n == 6) cout << 18 << endl;
  return 0;
}
