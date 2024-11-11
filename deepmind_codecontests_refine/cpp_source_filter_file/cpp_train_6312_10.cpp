#include <bits/stdc++.h>
using namespace std;
long long int maxx = 1e9 + 7;
long long int powr(long long int x, long long int a, long long int mod) {
  if (a == 0) return 1;
  long long int val;
  val = x * x;
  val = val % mod;
  if (a % 2 == 0)
    return powr(val, a / 2, mod) % mod;
  else
    return (powr(val, a / 2, mod) * x) % mod;
}
int main() {
  long long int x, y;
  cin >> x >> y;
  if (y % x != 0)
    cout << 0 << endl;
  else {
    long long int n = y / x;
    vector<long long int> fac;
    long long int ii;
    for (ii = 1; ii * ii < n; ii++) {
      if (n % ii == 0) {
        fac.push_back(ii);
        fac.push_back(n / ii);
      }
    }
    if (ii * ii == n) fac.push_back(ii);
    sort(fac.begin(), fac.end());
    long long int l = fac.size();
    unordered_map<long long int, long long int> g;
    g[1] = 1;
    for (long long int i = 1; i < l; i++) {
      long long int num = fac[i];
      long long int val = powr(2, num - 1, maxx);
      long long int j;
      for (j = 1; j * j < n; j++) {
        if (num % j == 0) {
          val -= g[j];
          val = (val + maxx) % maxx;
          val -= g[num / j];
          val = (val + maxx) % maxx;
        }
      }
      if (j * j == n) {
        val -= g[j];
        val = (val + maxx) % maxx;
      }
      g[num] = val;
    }
    cout << g[n] << endl;
  }
  return 0;
}
