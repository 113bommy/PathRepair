#include <bits/stdc++.h>
using namespace std;
long long fh(string s) {
  long long x = 0;
  for (char c : s) {
    if (isdigit(c)) {
      x = 16 * x + c - 48;
    } else {
      x = 16 * x + c - 'a' + 10;
    }
  }
  return x;
}
bool jeste(long long x) {
  long long dm = 0;
  for (int i = 0; i < 15; i++) {
    long long d = (x >> (4 * i)) & 15;
    dm = max(dm, d);
  }
  return x & (1ll << dm);
}
long long resi_brut(long long x) {
  long long z = 0;
  for (long long i = 1; i < x; i++) {
    if (jeste(i)) {
      z++;
    }
  }
  return z;
}
int nl;
int a[16];
long long dp[17][2][2];
void xtr(long long x) {
  nl = 0;
  while (x) {
    a[nl++] = x & 15;
    x >>= 4;
  }
  reverse(a, a + nl);
}
long long resi(long long x) {
  xtr(x);
  long long z = 0;
  for (int m = 1; m <= 15; m++) {
    memset(dp, 0, sizeof dp);
    dp[0][1][0] = 1;
    int cri = nl - 1 - m / 4;
    int crj = m % 4;
    for (int i = 0; i < nl; i++) {
      for (int p : {0, 1}) {
        for (int h : {0, 1}) {
          for (int y = 0; y <= m; y++) {
            if (p && y > a[i]) break;
            if (i == cri && (y & (1 << crj))) continue;
            int p2 = p && (y == a[i]);
            int h2 = h || (y == m);
            dp[i + 1][p2][h2] += dp[i][p][h];
          }
        }
      }
    }
    z += dp[nl][0][1];
  }
  return x - z;
}
int main() {
  ios::sync_with_stdio(!cin.tie(0));
  int t;
  cin >> t;
  while (t--) {
    string hl, hr;
    cin >> hl >> hr;
    cout << resi(fh(hr) + 1) - resi(fh(hl)) + (hl == "0") << '\n';
  }
}
