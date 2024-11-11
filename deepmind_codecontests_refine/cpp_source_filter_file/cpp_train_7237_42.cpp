#include <bits/stdc++.h>
using namespace std;
long long int modularPower(long long int x, unsigned long long int y,
                           long long int mod) {
  long long int res = 1;
  x %= mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y >>= 1;
    x = (x * x) % mod;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cerr.tie(NULL);
  cout.tie(NULL);
  ;
  int tests = 1;
  while (tests--) {
    int n, a;
    cin >> n >> a;
    if (a & 1)
      cout << (a + 1) / 2;
    else
      cout << (n - a) / 2;
  }
  return 0;
}
