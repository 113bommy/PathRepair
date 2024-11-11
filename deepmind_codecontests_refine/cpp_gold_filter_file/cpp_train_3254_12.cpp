#include <bits/stdc++.h>
using namespace std;
const long long MOD2 = 998244353;
const long long MOD = 1e9 + 7;
const long long MAX = 1e5 + 7;
const long long inf = 1e18L + 5;
const double pi = 3.14159265358979323846;
long long fpow(long long n, long long m) {
  long long res = 1;
  while (m > 0) {
    if (m & 1) {
      res *= n;
    }
    m /= 2;
    n *= n;
  }
  return res;
}
long long modInv(long long n) { return fpow(n, MOD - 2); }
const long long nax = 1e3 + 5;
void solve() {
  long long n;
  cin >> n;
  vector<long long> ar(2 * n), grp;
  for (long long i = 0; i < 2 * n; i++) cin >> ar[i];
  long long temp = 1;
  for (int i = 1; i < 2 * n; ++i) {
    if (ar[i] < ar[i - temp]) {
      ++temp;
    } else {
      grp.push_back(temp);
      temp = 1;
    }
  }
  grp.push_back(temp);
  long long gsiz = grp.size();
  bool dp[gsiz + 10][n + 10];
  for (long long i = 0; i < gsiz + 10; i++) fill(dp[i], dp[i] + n + 10, false);
  dp[0][0] = true;
  for (int i = 0; i < gsiz; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (dp[i][j]) {
        dp[i + 1][j] = true;
        if (j + grp[i] <= n) dp[i + 1][j + grp[i]] = true;
      }
    }
  }
  if (dp[gsiz - 1][n] == true)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
