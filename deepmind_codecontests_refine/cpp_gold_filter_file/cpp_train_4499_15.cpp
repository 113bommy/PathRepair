#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
const long long INF = 1000000000000000000LL;
map<long long, int> dp;
int res;
vector<long long> f;
int solve(long long n) {
  vector<int> r;
  for (int i = f.size() - 1; i >= 0; --i)
    if (n >= f[i]) {
      r.push_back(i);
      n -= f[i];
    }
  reverse((r).begin(), (r).end());
  int dp[r.size()][2];
  dp[0][1] = 1;
  dp[0][0] = r.front() / 2;
  for (int i = 1; i <= r.size() - 1; ++i) {
    int j = r[i - 1];
    dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
    dp[i][0] = 0;
    int k = r[i];
    while (k - 2 > j) dp[i][0] += dp[i][1], k -= 2;
    if (k - 2 == j) dp[i][0] += dp[i - 1][0];
  }
  return dp[r.size() - 1][0] + dp[r.size() - 1][1];
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  f.push_back(1), f.push_back(2);
  while (f.back() <= INF) f.push_back(f.back() + f[f.size() - 2]);
  f.pop_back();
  int z;
  cin >> z;
  while (z--) {
    long long n;
    cin >> n;
    cout << solve(n) << endl;
  }
  return 0;
}
