#include <bits/stdc++.h>
using namespace std;
signed main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  cout << fixed;
  long long int n, m;
  cin >> n >> m;
  if (max(m, n) > 2 * min(m, n))
    cout << min(m, n) << endl;
  else {
    if (n % 3 + m % 3 >= 3)
      cout << m / 3 + n / 3 + 1 << endl;
    else
      cout << m / 3 + n / 3 << endl;
  }
}
