#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long ans = 0;
int v[200];
long long dp[105][212345];
long long solve(int pos, long long mult) {
  if (mult > n) return 0;
  if (mult < 212345 and dp[pos][mult] != -1) return dp[pos][mult];
  if (pos == k) return mult;
  long long ret = 0;
  ret -= solve(pos + 1, mult / v[pos]);
  ret += solve(pos + 1, mult);
  if (mult >= 212345) return ret;
  return dp[pos][mult] = ret;
}
int main(void) {
  cin >> n >> k;
  for (int i = 0; i < k; i++) cin >> v[i];
  memset(dp, -1, sizeof dp);
  sort(v, v + k);
  set<int> s;
  for (int i = 0; i < k; i++) {
    bool flag = true;
    for (int j = 0; j < i; j++)
      if (v[i] % v[j] == 0) flag = false;
    if (flag) s.insert(v[i]);
  }
  k = 0;
  for (auto it : s) v[k++] = it;
  reverse(v, v + k);
  cout << solve(0, n) << endl;
  return 0;
}
