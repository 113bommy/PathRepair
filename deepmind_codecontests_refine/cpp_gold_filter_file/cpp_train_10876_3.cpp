#include <bits/stdc++.h>
using namespace std;
int a[400];
long long memo[400][51][3][3][2];
long long solve(int pos, int have, int sign1, int sign2, int active) {
  if (have < 0) return -800000;
  if (pos == -1) {
    if (have == 0) return 0;
    return -800000;
  }
  long long &ret = memo[pos][have][sign1 + 1][sign2 + 1][active];
  if (ret == -1) {
    ret = -800000;
    if (active == 1) {
      long long aux2 = solve(pos - 1, have, sign1, sign2, 1);
      if (aux2 != -800000) ret = max(ret, aux2 + (sign1 + sign2) * a[pos]);
      long long aux3 = solve(pos, have, sign1, sign2, 0);
      if (aux3 != -800000) ret = max(ret, aux3);
    } else {
      long long aux1 = solve(pos - 1, have, sign1, sign2, 0);
      if (aux1 != -800000) ret = max(ret, aux1);
      long long aux2 = solve(pos - 1, have - 1, -sign2, (have == 1 ? 0 : 1), 1);
      if (aux2 != -800000)
        ret = max(ret, aux2 + (-sign2 + (have == 1 ? 0 : 1)) * a[pos]);
      long long aux3 =
          solve(pos - 1, have - 1, -sign2, (have == 1 ? 0 : -1), 1);
      if (aux3 != -800000)
        ret = max(ret, aux3 + (-sign2 + (have == 1 ? 0 : -1)) * a[pos]);
    }
  }
  return ret;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  memset(memo, -1, sizeof memo);
  cout << solve(n - 1, k, 0, 0, 0) << '\n';
  return 0;
}
