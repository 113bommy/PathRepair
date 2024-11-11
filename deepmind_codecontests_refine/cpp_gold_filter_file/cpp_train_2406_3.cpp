#include <bits/stdc++.h>
using namespace std;
const int z = 998244353;
const int z0 = 999999929;
const int z1 = 233;
int fp(int a, int x) {
  if (x == 0) {
    return 1;
  }
  if (x % 2 == 1) {
    return 1ll * a * fp(a, x - 1) % z0;
  }
  int t = fp(a, x / 2);
  return 1ll * t * t % z0;
}
int inv(int a) { return fp(a, z0 - 2); }
void h(string &s, int h[]) {
  h[0] = 0;
  int q = 1;
  for (int i = 0; i < s.length(); i++) {
    h[i + 1] = (h[i] + 1ll * q * (s[i] - '0')) % z0;
    q = 1ll * q * z1 % z0;
  }
}
int cs(string &a, int ha[], int i, int j, string &s, int hs[], int iz1[]) {
  if (j - i != s.length()) {
    return j - i > s.length() ? 1 : -1;
  }
  int l = -1, r = j - i;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (1ll * (ha[i + mid + 1] - ha[i] + z0) * iz1[i] % z0 == hs[1 + mid]) {
      l = mid;
    } else {
      r = mid;
    }
  }
  if (r == j - i) {
    return 0;
  } else {
    return a[i + r] < s[r] ? -1 : 1;
  }
}
int main() {
  ios::sync_with_stdio(false);
  string a, l, r;
  cin >> a;
  cin >> l;
  cin >> r;
  int ha[a.length() + 1], hl[l.length() + 1], hr[r.length() + 1];
  h(a, ha);
  h(l, hl);
  h(r, hr);
  int iz1[a.length() + 1];
  iz1[0] = 1, iz1[1] = inv(z1);
  for (int i = 2; i <= a.length(); i++) {
    iz1[i] = 1ll * iz1[i - 1] * iz1[1] % z0;
  }
  int dp[a.length() + 1];
  dp[0] = 1;
  int i1 = 0, i2 = 0, dps = 0;
  for (int i = 1; i <= a.length(); i++) {
    while (i1 < i && cs(a, ha, i1, i, r, hr, iz1) == 1) {
      if (a[i1] != '0') {
        dps = (dps - dp[i1] + z) % z;
      }
      i1++;
    }
    while (i2 < i && cs(a, ha, i2, i, l, hl, iz1) >= 0) {
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
