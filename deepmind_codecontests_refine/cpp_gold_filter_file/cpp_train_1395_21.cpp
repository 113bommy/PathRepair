#include <bits/stdc++.h>
using namespace std;
int n;
string xx;
const int mod = (int)1.e9 + 7;
inline long long powpow(int x) {
  long long res = 1;
  for (int i = (int)(0); i < (int)(x); ++i) res = (res << 1) % mod;
  return res;
}
int main() {
  getline(cin, xx);
  n = xx.size();
  long long res = 0;
  for (int i = (int)(0); i < (int)(n); ++i) {
    if (xx[i] == '1') {
      int l = i, r = n - i - 1;
      res += (powpow(l) * (powpow(r) * powpow(r) % mod)) % mod;
      res %= mod;
    }
  }
  cout << res << endl;
  return 0;
}
