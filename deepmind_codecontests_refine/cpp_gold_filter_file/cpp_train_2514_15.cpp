#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
inline int mod(int n) { return (n % 1000000007); }
int gcd(int a, int b) {
  if (a == 0 || b == 0) return 0;
  if (b == 1)
    return b;
  else
    return gcd(b, a % b);
}
int fpow(int x, unsigned int y, int p) {
  int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, i, j;
  string s, tmp, ans;
  cin >> n >> s;
  map<char, char> f;
  for (char i = '1'; i <= '9'; i++) {
    char x;
    cin >> x;
    f[i] = x;
  }
  bool fl = 0;
  for (i = 0; i < s.size(); i++) {
    if (f[s[i]] == s[i]) continue;
    if (f[s[i]] > s[i]) {
      s[i] = f[s[i]];
      fl = 1;
    } else if (fl)
      break;
  }
  cout << s << '\n';
}
