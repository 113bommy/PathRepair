#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (n == 1)
    cout << m / 6 * 6 + max(0ll, m % 6 - 3) << '\n';
  else {
    if (n % 2 == 0 && m % 2 == 0) {
      if (n == 2 && m == 2)
        cout << 0 << '\n';
      else
        cout << n * m << '\n';
    } else if (n % 2 && m % 2)
      cout << n * m - 1 << '\n';
    else {
      if (n == 2 && m == 3)
        cout << 4 << '\n';
      else if (n == 2 && m == 7)
        cout << 12 << '\n';
      else
        cout << n * m << '\n';
    }
  }
  return 0;
}
