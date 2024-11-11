#include <bits/stdc++.h>
using namespace std;
const int nmax = 300;
const long long mod = 998244353;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k, m, t;
  cin >> n >> k >> m >> t;
  for (long long i = 0; i < t; i++) {
    long long q, z;
    cin >> q >> z;
    if (q == 0) {
      if (z <= k) {
        k = (k == z ? 1 : k - z);
        n -= z;
      } else {
        n = z;
      }
    } else {
      if (z <= k) k++;
      n++;
    }
    cout << n << " " << k << endl;
  }
  return 0;
}
