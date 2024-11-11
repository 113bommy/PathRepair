#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long pw(long long a, long long k) {
  if (k == 0) {
    return 1;
  }
  if (k == 1) {
    return a;
  }
  long long res = pw(a, k / 2);
  res = res * res % mod;
  if (k % 2 == 1) {
    res *= a;
  }
  return res % mod;
}
int main(int argc, char **argv) {
  string s;
  cin >> s;
  long long ans = 0, n = (int)s.size(), l = (int)s.size();
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == '1') {
      ans += pw(2, n - l) * pw(2, l * 2 - 2) % mod;
    }
    l--;
  }
  cout << ans;
  return 0;
}
