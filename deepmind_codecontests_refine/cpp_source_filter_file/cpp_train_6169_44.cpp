#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 1e6 + 14;
const int inf = (int)1e18 + 10;
const int mod = 998244353;
const double eps = 1e-6;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
using namespace std;
int q;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    if (n % 2)
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
}
