#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long n;
string st;
long long pow(long long a, long long b) {
  long long ret = 1;
  while (b > 0) {
    if (b & 1) ret *= a;
    b /= 2;
    a *= a;
  }
  return ret;
}
long long aton(char c) {
  if (c == '-') return 62;
  if (c == '_') return 63;
  if (c <= '9' && c >= '0') return c - '0';
  if (c <= 'Z' && c >= 'A') return (c - 'A') + 10;
  if (c <= 'z' && c >= 'a') return (c - 'a') + 36;
}
long long pos(long long xx) {
  long long cnt = 0;
  for (long long i = 0; i < 6; i++) {
    if (!((1 << i) & (xx))) cnt++;
  }
  return pow(3, cnt);
}
int main() {
  long long cval, ans = 1;
  cin >> st;
  n = st.length();
  for (long long i = 0; i < n; i++) {
    cval = aton(st[i]);
    ans *= pos(cval);
    if (ans >= mod) ans %= mod;
  }
  cout << ans << endl;
}
