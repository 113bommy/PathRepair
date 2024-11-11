#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
string s, r;
int x;
long long len = 0;
long long res = 0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    res = 0;
    long double resd = 0;
    cin >> x;
    cin >> r;
    len = r.length();
    res = len;
    for (int i = 0; i < x; i++) {
      int cnt = r[i] - '0';
      if (resd < x - 0.5) {
        long long oldlen = len;
        for (int j = 0; j < (cnt - 1) * (oldlen - (i + 1)) && len < x + 1;
             j++) {
          r.push_back(r[j % (oldlen - (i + 1)) + (i + 1)]);
          len++;
        }
      }
      res += 1LL * (cnt - 1) * (res - (i + 1)) % mod;
      res %= mod;
      resd += 1LL * (cnt - 1) * (resd - (i + 1));
      len = res;
    }
    cout << (res % mod + mod) % mod << endl;
  }
}
