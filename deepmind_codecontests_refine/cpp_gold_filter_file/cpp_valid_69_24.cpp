#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 998244353;
long long n, m;
long long ans, cnt;
long long aa[N];
long long kpow(long long a, long long b) {
  long long temp = 1;
  while (b) {
    if (b & 1) temp = temp * a % M;
    a = a * a % M;
    b >>= 1;
  }
  return temp;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    ans = to_string(n).length() + 1;
    string s, ss;
    s = to_string(n);
    for (long long k = 1; k < (1ll << 60); k <<= 1) {
      cnt = 0;
      int i = 0, j = 0;
      ss = to_string(k);
      while (i < s.length() && j < ss.length()) {
        if (s[i] == ss[j])
          i++, j++;
        else {
          i++;
          cnt++;
        }
      }
      if (i < s.length()) cnt += s.length() - i;
      if (j < ss.length()) cnt += ss.length() - j;
      ans = min(ans, cnt);
    }
    cout << ans << endl;
  }
  return 0;
}
