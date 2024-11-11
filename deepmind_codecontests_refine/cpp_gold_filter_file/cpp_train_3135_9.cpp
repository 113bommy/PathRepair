#include <bits/stdc++.h>
using namespace std;
long long n, m;
int main() {
  cin >> n >> m;
  if (n + m <= 4) {
    cout << 0 << '\n';
    return 0;
  }
  if (n > m) swap(n, m);
  if (n == 2 && m == 3) {
    cout << 4 << '\n';
    return 0;
  }
  if (n == 1 && m == 4) {
    cout << 2 << '\n';
    return 0;
  }
  if (n == 1 && m == 9) {
    cout << 6 << '\n';
    return 0;
  }
  if (n == 2 && m == 7) {
    cout << 12 << '\n';
    return 0;
  }
  if (n == 1) {
    long long ans;
    ans = n * m;
    m = m % 6;
    ans -= min(m, 6 - m);
    cout << ans << '\n';
    return 0;
  }
  n = n * m;
  n -= n % 2;
  cout << n << '\n';
  return 0;
}
