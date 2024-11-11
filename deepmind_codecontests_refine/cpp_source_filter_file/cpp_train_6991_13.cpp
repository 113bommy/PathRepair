#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
const long long N = 100005;
void solve() {
  long long x, y, z;
  cin >> x >> y >> z;
  if (x == y and z == 0)
    cout << "0";
  else if (abs(x - y) < z)
    cout << "?";
  else if (x + z < y)
    cout << "-";
  else
    cout << "+";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
