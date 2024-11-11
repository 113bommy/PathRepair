#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long md = 1e9 + 7;
signed main() {
  int n, k;
  cin >> n >> k;
  if (n % (2 * k) >= k)
    cout << "YES";
  else
    cout << "NO";
}
