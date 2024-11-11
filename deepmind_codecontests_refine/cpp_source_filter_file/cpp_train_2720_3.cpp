#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e10;
const long long mod = 1e9 + 7;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long n;
  cin >> n;
  if ((n % 2 + n / 2) == 0) {
    cout << 0;
    cout << '\n';
  } else {
    cout << 1;
    cout << '\n';
  }
  return 0;
}
