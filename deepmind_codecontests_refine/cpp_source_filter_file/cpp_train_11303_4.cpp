#include <bits/stdc++.h>
using namespace std;
string s;
long long n;
vector<long long> V;
long long dp[70];
long long calc(string tmp) {
  if (tmp.size() > 11) return 1e18 + 1;
  long long cur = 0;
  for (int i = 0; i < tmp.size(); i++) cur = cur * 10 + tmp[i] - '0';
  return cur;
}
long long cnt = 0;
void get(long long x) {
  while (x) {
    cnt++;
    x /= 10;
  }
}
long long solve(int idx) {
  if (idx < 0) return 0;
  long long &ret = dp[idx];
  if (ret != -1) return ret;
  ret = 1e18 + 1;
  string tmp = "";
  for (int i = idx; i >= 0; i--) {
    tmp = s[i] + tmp;
    if (tmp.size() > cnt || tmp.size() > 1 && tmp[0] == '0' || calc(tmp) >= n)
      continue;
    long long cur = calc(tmp);
    long long ans = solve(i - 1);
    if (log(cur) + log(n) <= log(1e18)) {
      ret = min(ret, cur + ans * n);
    }
  }
  return ret;
}
int main() {
  cin >> n >> s;
  get(n);
  memset(dp, -1, sizeof(dp));
  cout << solve(s.size() - 1) << '\n';
  return 0;
}
