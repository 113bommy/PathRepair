#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353LL;
vector<int> nums[2];
const int LEFT_VAL = 0;
const int RIGHT_VAL = 1;
const int OTHER = 2;
long long calcRes(int pos, int prevVal, int k, int lVal, int rVal,
                  vector<vector<long long>>& dp) {
  if (pos == dp.size()) {
    return (prevVal != RIGHT_VAL && (prevVal != LEFT_VAL || lVal != rVal));
  }
  if (dp[pos][prevVal] != -1) {
    return dp[pos][prevVal];
  }
  long long res = 0;
  if (rVal > 0 && prevVal != RIGHT_VAL &&
      (prevVal != LEFT_VAL || lVal != rVal)) {
    res = calcRes(pos + 1, RIGHT_VAL, k, lVal, rVal, dp);
  }
  if (lVal > 0 && rVal != lVal && prevVal != LEFT_VAL &&
      (prevVal != RIGHT_VAL || lVal != rVal)) {
    res = (res + calcRes(pos + 1, LEFT_VAL, k, lVal, rVal, dp)) % mod;
  }
  long long mul = k;
  if (lVal > 0) {
    mul--;
  }
  if (rVal > 0 && rVal != lVal) {
    mul--;
  }
  if (prevVal == OTHER) {
    mul--;
  }
  res += (mul * calcRes(pos + 1, OTHER, k, lVal, rVal, dp)) % mod;
  res %= mod;
  return dp[pos][prevVal] = res;
}
long long getRes(vector<int>& a, int k) {
  int l = 0;
  long long res = 1;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != -1) {
      if (l <= i - 1) {
        vector<vector<long long>> dp(i - l, vector<long long>(3, -1));
        int lVal = l > 0 ? a[l - 1] : -1;
        int rVal = a[i];
        res = (res * calcRes(0, LEFT_VAL, k, lVal, rVal, dp)) % mod;
      }
      l = i + 1;
    }
  }
  if (l != a.size()) {
    vector<vector<long long>> dp(a.size() - l, vector<long long>(3, -1));
    int lVal = l > 0 ? a[l - 1] : -1;
    int rVal = -2;
    res = (res * calcRes(0, LEFT_VAL, k, lVal, rVal, dp)) % mod;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> all;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    nums[i % 2].push_back(a);
    all.push_back(a);
  }
  long long res = 1;
  for (int i = 0; i < n - 2; ++i) {
    if (all[i] == all[i + 2] && all[i] != -1) {
      res = 0;
      break;
    }
  }
  for (int i = 0; i < 2; ++i) {
    res = (res * getRes(nums[i], k)) % mod;
  }
  cout << res << endl;
  return 0;
}
