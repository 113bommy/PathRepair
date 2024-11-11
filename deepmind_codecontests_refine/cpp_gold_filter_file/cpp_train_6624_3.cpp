#include <bits/stdc++.h>
using namespace std;
const long long mod = 100000009;
long long t[1000010];
long long h[1000010];
string s;
bool check(int la, int lb, int lc) {
  if (la < 1 || lb < 1 || lc < 1 || la > lc || lb > lc) return false;
  if (la > 1 && s[0] == '0' || lb > 1 && s[la] == '0' ||
      lc > 1 && s[la + lb] == '0')
    return false;
  long long ha, hb, hc;
  ha = h[la - 1];
  hb = ((h[la + lb - 1] - t[lb] * h[la - 1]) % mod + mod) % mod;
  hc = ((h[la + lb + lc - 1] - t[lc] * h[la + lb - 1]) % mod + mod) % mod;
  return (ha + hb) % mod == hc;
}
int main() {
  cin >> s;
  int n = s.length();
  t[0] = 1;
  h[0] = s[0] - '0';
  for (int i = 1; i < n; ++i) {
    t[i] = (t[i - 1] * 10) % mod;
    h[i] = (h[i - 1] * 10 + s[i] - '0') % mod;
  }
  int lc, lb, la;
  for (lc = 1; lc < n - 1; ++lc) {
    la = lc;
    lb = n - la - lc;
    if (check(la, lb, lc)) {
      break;
    }
    la = lc - 1;
    lb = n - la - lc;
    if (check(la, lb, lc)) {
      break;
    }
    lb = lc;
    la = n - lb - lc;
    if (check(la, lb, lc)) {
      break;
    }
    lb = lc - 1;
    la = n - lb - lc;
    if (check(la, lb, lc)) {
      break;
    }
  }
  cout << s.substr(0, la) << "+" << s.substr(la, lb) << "=" << s.substr(la + lb)
       << endl;
  return 0;
}
