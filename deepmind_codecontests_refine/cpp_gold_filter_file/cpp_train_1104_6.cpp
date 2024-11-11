#include <bits/stdc++.h>
using namespace std;
int nrq;
long long dp[11][100][1025][2][2];
int cif[100];
long long din(int b, int lung, int masca, int lzero, int egal) {
  if (lung == 0) {
    if ((masca == 0))
      return 1;
    else
      return 0;
  }
  if ((!egal) && (dp[b][lung][masca][lzero][egal] != -1))
    return dp[b][lung][masca][lzero][egal];
  int cifmax;
  if (egal)
    cifmax = cif[lung];
  else
    cifmax = b - 1;
  long long ans = 0;
  int newlzero, newegal, newmasca;
  for (int c = 0; c <= cifmax; c++) {
    if ((!lzero) || (c != 0))
      newmasca = masca ^ (1 << c);
    else
      newmasca = masca;
    if (lzero && (c == 0))
      newlzero = 1;
    else
      newlzero = 0;
    if (egal && (c == cif[lung]))
      newegal = 1;
    else
      newegal = 0;
    ans += din(b, lung - 1, newmasca, newlzero, newegal);
  }
  dp[b][lung][masca][lzero][egal] = ans;
  return ans;
}
long long solve(long long x, int b) {
  int lung = 0;
  while (x) {
    lung++;
    cif[lung] = x % b;
    x /= b;
  }
  return din(b, lung, 0, 1, 1);
}
int main() {
  long long b, l, r;
  memset(dp, -1, sizeof(dp));
  cin >> nrq;
  while (nrq--) {
    cin >> b >> l >> r;
    cout << solve(r, b) - solve(l - 1, b) << "\n";
  }
  return 0;
}
