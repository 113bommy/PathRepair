#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long int M = 1000000007;
long long int inv(long long int a, long long int b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
pair<long long int, long long int> neigh[4] = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
long long int dp[2 * 2010][2010];
bool r(long long int n, vector<long long int>& res, long long int i) {
  if (n <= 0) {
    return n == 0;
  }
  if (i >= res.size()) return false;
  if (~dp[i][n]) return dp[i][n];
  return dp[i][n] = (r(n - res[i], res, i + 1) || r(n, res, i + 1));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int _t;
  cin >> _t;
  for (long long int _t1 = 0; _t1 < (_t); _t1++) {
    long long int n;
    cin >> n;
    vector<long long int> a(2 * n);
    for (long long int i = 0; i < (2 * n); i++) cin >> a[i];
    vector<long long int> res;
    long long int last = 0;
    for (long long int i = 0; i < (2 * n); i++)
      for (long long int j = 0; j < (n + 1); j++) dp[i][j] = -1;
    for (long long int i = 1; i < (2 * n); i++) {
      if (a[i] > a[last]) {
        res.push_back(i - last);
        last = i;
      }
    }
    res.push_back(2 * n - last);
    cout << (r(n, res, 0) ? "YES" : "NO") << endl;
  }
}
