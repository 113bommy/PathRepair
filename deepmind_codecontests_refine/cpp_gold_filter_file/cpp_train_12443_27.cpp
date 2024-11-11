#include <bits/stdc++.h>
using namespace std;
long long memo[50][2][2][2];
long long s, xr;
long long solve(int idx, int carry, int fs, int sc) {
  if (idx > 45) {
    if (carry || !fs || !sc) return 0ll;
    return 1ll;
  }
  long long& ans = memo[idx][carry][fs][sc];
  if (ans != -1) return ans;
  ans = 0ll;
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      if (xr & (1ll << idx)) {
        if (i ^ j) {
          if ((s & (1ll << idx)) && (!carry)) {
            ans += solve(idx + 1, 0, i || fs, j || sc);
          }
          if ((!(s & (1ll << idx)) && carry)) {
            ans += solve(idx + 1, 1, i || fs, j || sc);
          }
        }
      } else {
        if (!(i ^ j)) {
          if ((s & (1ll << idx)) && carry) {
            if (i && j) {
              ans += solve(idx + 1, 0, i || fs, j || sc);
            } else {
              ans += solve(idx + 1, 1, i || fs, j || sc);
            }
          }
          if ((!(s & (1ll << idx))) && (!carry)) {
            if (i && j) {
              ans += solve(idx + 1, 1, i || fs, j || sc);
            } else {
              ans += solve(idx + 1, 0, i || fs, j || sc);
            }
          }
        }
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(memo, -1, sizeof(memo));
  cin >> s >> xr;
  cout << solve(0, 0, 0, 0) << '\n';
  return 0;
}
