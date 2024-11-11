#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5, oo = 0x3f3f3f3f, mod = 1e9 + 7;
int t;
string l, r;
long long mem[19][5][2];
long long dp(int i, int n, int pre, string s, int sz) {
  if (i == sz) {
    if (n <= 3) return 1;
    return 0;
  }
  if (n > 3) return 0;
  if (mem[i][n][pre] != -1) return mem[i][n][pre];
  int lim = 9;
  if (!pre) lim = s[i] - '0';
  long long ans = 0;
  for (int d = 0; d <= lim; d++) {
    int nd = n;
    if (d != 0) nd++;
    int pred = pre;
    if (pre == 0 && d < lim) pre = 1;
    if (nd <= 3) ans += dp(i + 1, nd, pred, s, sz);
  }
  return mem[i][n][pre] = ans;
}
void dec() {
  int i = l.size() - 1;
  while (i >= 0) {
    if (l[i] != '0') {
      l[i]--;
      break;
    } else
      l[i] = '9';
    i--;
  }
}
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    memset(mem, -1, sizeof mem);
    cin >> l >> r;
    dec();
    long long ansR = dp(0, 0, 0, r, r.size());
    memset(mem, -1, sizeof mem);
    cout << ansR - dp(0, 0, 0, l, l.size()) << endl;
  }
  return 0;
}
