#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long n;
long long arr[23][26];
long long mArr[26];
long long ans[8488608];
long long dp[8488608];
stack<vector<long long>> curMin;
bool vis[8488608];
void dfs(long long x, int k) {
  vector<long long> v;
  if (x != 0) {
    vector<long long> vv = curMin.top();
    for (int i = 0; i < 26; ++i) v.push_back(min(vv[i], arr[k][i]));
  } else
    for (int i = 0; i < 26; ++i) v.push_back(1e5);
  curMin.push(v);
  vis[x] = true;
  if (x != 0) {
    ans[x] = 1;
    for (long long i = 0; i < 26; ++i) {
      ans[x] *= (v[i] + 1);
      ans[x] %= MOD;
    }
  }
  int num = 0;
  for (int i = 0; i < n; ++i)
    if (x & (1 << i)) num++;
  if (num % 2 == 0) ans[x] = MOD - ans[x];
  for (long long i = 0; i < n; ++i) {
    if ((x & (1 << i))) continue;
    if (vis[x | (1 << i)]) continue;
    vector<long long> t;
    dfs(x | (1 << i), i);
  }
  curMin.pop();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (long long j = 0; j < s.size(); ++j) arr[i][s[j] - 'a']++;
  }
  dfs(0, 0);
  for (long long i = 0; i < (1 << n); ++i) {
    dp[i] = ans[i];
  }
  for (long long i = 0; i < n; ++i) {
    for (long long mask = 0; mask < (1 << n); ++mask) {
      if (mask & (1 << i)) {
        dp[mask] += dp[mask ^ (1 << i)];
        dp[mask] %= MOD;
      }
    }
  }
  long long fAns = 0;
  for (long long i = 0; i < (1 << n); ++i) {
    long long num = 0;
    for (long long j = 0; j < n; ++j)
      if (i & (1 << j)) ++num;
    long long nNum = 0;
    for (long long j = 0; j < n; ++j)
      if (i & (1 << j)) nNum += (1 + j);
    long long mult = (num * nNum);
    long long tAns = mult * (dp[i] % MOD);
    fAns ^= tAns;
  }
  cout << fAns << endl;
  return 0;
}
