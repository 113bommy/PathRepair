#include <bits/stdc++.h>
using namespace std;
long long int binpow(long long int a, long long int b, long long int mod) {
  long long int res = 1;
  while (b != 0) {
    if (b % 2) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    b = b / 2;
  }
  return res % mod;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    if (n % 2 == 0)
      cout << "YES" << endl;
    else {
      int fl = 1;
      for (int i = 0; i < n - 1; i++) {
        if (v[i] >= v[i + 1]) {
          fl = 0;
          break;
        }
      }
      if (!fl)
        cout << "YES" << endl;
      else {
        cout << "NO" << endl;
      }
    }
  }
}
