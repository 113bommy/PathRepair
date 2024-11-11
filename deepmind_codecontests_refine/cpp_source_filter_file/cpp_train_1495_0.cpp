#include <bits/stdc++.h>
using namespace std;
int fastMax(int x, int y) { return (((y - x) >> (32 - 1)) & (x ^ y)) ^ y; }
int fastMin(int x, int y) { return (((y - x) >> (32 - 1)) & (x ^ y)) ^ x; }
const long long int MAXN = 1e5 + 3;
long long int dp[20][2][10][10];
vector<long long int> digits;
void convert_to_digits(long long int n) {
  digits.clear();
  if (n == 0) digits.push_back(0);
  while (n > 0) {
    digits.push_back(n % 10);
    n = n / 10;
  }
}
long long int recursion(long long int idx, bool flag, long long int first,
                        long long int last) {
  if (idx == -1) {
    if (first == last && first != 0) return 1;
    return 0;
  }
  if (dp[idx][flag][first][last] != -1) return dp[idx][flag][first][last];
  long long int ans = 0;
  long long int n = (flag) ? digits[idx] : 9;
  for (int i = (0); i <= (n); ++i) {
    bool nflag = (i == n) ? flag : 0;
    long long int nfirst = (first == 0 and i != 0) ? i : first;
    long long int nlast = i;
    ans = ans + recursion(idx - 1, nflag, nfirst, nlast);
  }
  return dp[idx][flag][first][last] = ans;
}
void solve() {
  long long int l, r;
  cin >> l >> r;
  memset(dp, -1, sizeof(dp));
  convert_to_digits(l);
  long long int ans = recursion(digits.size() - 1, 1, 0, 0);
  memset(dp, -1, sizeof(dp));
  if (l > 1) {
    convert_to_digits(r);
    ans -= recursion(digits.size() - 1, 1, 0, 0);
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
}
