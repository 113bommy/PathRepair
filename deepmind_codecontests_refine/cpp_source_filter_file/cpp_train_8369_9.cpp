#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
long long modPow(long long b, long long p) {
  if (p == 0)
    return 1;
  else if (p == 1)
    return b;
  else {
    long long res = modPow(b, p / 2);
    res = (res * res) % 1000000007;
    if (p & 1) res = (res * res) % 1000000007;
    return res;
  }
}
int main() {
  string s;
  while (cin >> s) {
    long long ans = 0, n = s.length();
    for (int i = 0; i < (int)n; ++i) {
      if (s[i] == '1') ans = (ans + modPow(2, (n << 1) - i - 2)) % 1000000007;
    }
    cout << ans << endl;
  }
  return 0;
}
