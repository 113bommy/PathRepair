#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, l, r, memo[200005][3], c[3];
long long solve(long long x = 0, long long rem = 0) {
  if (x == n) return (!rem ? 1 : 0);
  long long &ans = memo[x][rem];
  if (~ans) return ans;
  ans = 0;
  for (int i = 0; i < 3; i++)
    ans =
        (ans + (solve(x + 1, (rem + i) % 3) * c[i]) % 1000000007 + 1000000007) %
        1000000007;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(memo, -1, sizeof memo);
  cin >> n >> l >> r;
  c[0] = r / 3 - l / 3 + (l % 3 == 0);
  long long tmp = (l / 3 + 1) * 3, tmp1 = (r / 3) * 3;
  c[1] = tmp1 / 3 - tmp / 3;
  c[2] = tmp1 / 3 - tmp / 3;
  for (int i = l; i < tmp; i++) c[1] += (i % 3 == 1), c[2] += (i % 3 == 2);
  for (int i = tmp1 + 1; i <= r; i++)
    c[1] += (i % 3 == 1), c[2] += (i % 3 == 2);
  cout << solve();
  return 0;
}
