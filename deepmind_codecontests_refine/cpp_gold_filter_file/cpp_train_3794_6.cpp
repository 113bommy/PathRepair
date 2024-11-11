#include <bits/stdc++.h>
using namespace std;
const int MAXN = 66;
const long long MOD = 1e9 + 7;
long long C[MAXN][MAXN];
long long dp[MAXN][MAXN];
vector<int> bit;
void init() {
  for (int i = 0; i < MAXN; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
}
long long dfs(int len, int sum, int k, bool limit) {
  if (sum > k) return 0;
  if (len == -1) {
    return sum == k ? 1 : 0;
  }
  if (!limit && dp[len][sum] != -1) return dp[len][sum];
  int up = limit ? bit[len] : 1;
  long long res = 0;
  for (int i = 0; i <= up; i++) {
    res += dfs(len - 1, sum + i, k, limit && (i == up));
  }
  if (!limit) dp[len][sum] = res;
  return res;
}
bool judge(long long num, int k, long long m) {
  long long tmp = num;
  bit.clear();
  while (tmp) {
    bit.push_back(tmp & 1);
    tmp >>= 1;
  }
  memset(dp, -1, sizeof(dp));
  long long ans1 = dfs(bit.size() - 1, 0, k, true);
  tmp = num << 1;
  bit.clear();
  while (tmp) {
    bit.push_back(tmp & 1);
    tmp >>= 1;
  }
  long long ans2 = dfs(bit.size() - 1, 0, k, true);
  if (ans2 - ans1 >= m)
    return true;
  else
    return false;
}
int main() {
  long long m;
  int k;
  cin >> m >> k;
  long long l = 1, r = 1000000000000000000LL;
  long long mid;
  long long ans = 0;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (judge(mid, k, m)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
