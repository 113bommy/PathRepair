#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int n, m, k, l;
  cin >> n >> m >> k >> l;
  long long int x = (l + k) % m == 0 ? (l + k) / m : ((l + k) / m) + 1;
  if (x * m > n)
    cout << "-1" << '\n';
  else
    cout << x << '\n';
}
