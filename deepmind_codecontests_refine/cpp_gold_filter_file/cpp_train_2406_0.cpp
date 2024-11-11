#include <bits/stdc++.h>
using namespace std;
const int z = 998244353;
void zf(string &s, int z[]) {
  z[0] = s.length();
  int l = 0, r = 0;
  for (int i = 1; i < s.length(); i++) {
    if (i >= r) {
      l = r = i;
      while (r < s.length() && s[r - l] == s[r]) {
        r++;
      }
      z[i] = r - l;
    } else if (i + z[i - l] < r) {
      z[i] = z[i - l];
    } else {
      l = i;
      while (r < s.length() && s[r - l] == s[r]) {
        r++;
      }
      z[i] = r - l;
    }
  }
}
int cs(string &a, int z[], int l1, int i, int j) {
  if (j - i != l1) {
    return j - i < l1 ? -1 : 1;
  }
  if (z[l1 + 1 + i] == l1) {
    return 0;
  }
  return a[l1 + 1 + i + z[l1 + 1 + i]] < a[z[l1 + 1 + i]] ? -1 : 1;
}
int main() {
  ios::sync_with_stdio(false);
  string a, l, r;
  cin >> a;
  cin >> l;
  cin >> r;
  string la = l + '#' + a;
  string ra = r + '#' + a;
  int zl[la.length()], zr[ra.length()];
  zf(la, zl);
  zf(ra, zr);
  int dp[a.length() + 1];
  dp[0] = 1;
  int i1 = 0, i2 = 0, dps = 0;
  for (int i = 1; i <= a.length(); i++) {
    while (i1 < i && cs(ra, zr, r.length(), i1, i) == 1) {
      if (a[i1] != '0') {
        dps = (dps - dp[i1] + z) % z;
      }
      i1++;
    }
    while (i2 < i && cs(la, zl, l.length(), i2, i) >= 0) {
      if (a[i2] != '0') {
        dps = (dps + dp[i2]) % z;
      }
      i2++;
    }
    dp[i] = dps;
    if (l == "0" && a[i - 1] == '0') {
      dp[i] = (dp[i] + dp[i - 1]) % z;
    }
  }
  printf("%d\n", dp[a.length()]);
  return 0;
}
