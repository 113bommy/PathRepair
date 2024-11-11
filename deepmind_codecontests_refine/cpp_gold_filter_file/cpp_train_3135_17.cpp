#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  if (n > m) {
    swap(n, m);
  }
  if (n == 1) {
    cout << (((m / 6) * 3 + (max((m % 6) - 3, 0LL))) << 1LL);
    return 0;
  }
  if (n == 2) {
    cout << (m == 2 ? 0 : m == 3 ? 4 : m == 7 ? 12 : m << 1LL);
    return 0;
  }
  if (n >= 3) {
    cout << (n * m) / 2 * 2;
    return 0;
  }
}
