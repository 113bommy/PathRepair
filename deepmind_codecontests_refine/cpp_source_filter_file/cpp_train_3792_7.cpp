#include <bits/stdc++.h>
using namespace std;
long int mod = 1000000007;
int dp[1010][5010][2];
int n;
vector<long long> arr;
long long rec(int pos, int sum, int count) {
  if (pos >= n) {
    if (count && sum == 0) {
      return 1;
    } else {
      return 0;
    }
  }
  int &ans = dp[pos][sum][count];
  if (ans != -1) return ans;
  ans = 0;
  if (count == 0) {
    ans = (ans + rec(pos + 1, sum, count)) % mod;
    ans = (ans + rec(pos + 1, labs(sum + arr[pos]), 1)) % mod;
    ans = (ans + rec(pos + 1, labs(sum - arr[pos]), 1)) % mod;
  } else {
    ans = (ans + rec(pos + 1, labs(sum + arr[pos]), 1)) % mod;
    ans = (ans + rec(pos + 1, labs(sum - arr[pos]), 1)) % mod;
    ans = (ans + rec(n, sum, 1)) % mod;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  arr.resize(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  memset(dp, -1, sizeof dp);
  cout << rec(0, 0, 0);
  return 0;
}
