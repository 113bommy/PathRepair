#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector<long long> v;
long long dp[55];
bool chk(long long x) {
  if (x == 1 || x == 2) return 1;
  return 0;
}
long long solve(long long idx) {
  if (idx == n) return 1;
  long long &ret = dp[idx];
  if (~ret) return ret;
  ret = 0;
  for (long long i = idx; i < n; i++) {
    if (chk(i - idx + 1)) ret += solve(i + 1);
    ret = min(ret, (long long)1e18 + 1);
  }
  return ret;
}
vector<long long> con(vector<long long> a, vector<long long> b) {
  for (auto c : b) a.push_back(c);
  return a;
}
int main() {
  while (cin >> n >> k) {
    vector<long long> ans;
    vector<long long> tmp;
    memset(dp, -1, sizeof dp);
    while (ans.size() != n) {
      tmp.clear();
      vector<long long> cut;
      long long cnt = 0;
      for (long long i = 0; i < ans.size(); i++) cut.push_back(0);
      for (long long i = ans.size(); i < n; i++) {
        tmp.push_back(i);
        long long x = 0;
        if (chk((long long)tmp.size())) x = solve(i + 1);
        cnt += x;
        cut.push_back(cnt);
      }
      long long take = 0;
      long long idx = ans.size() + 1;
      for (long long i = ans.size(); i < n; i++) {
        if (cut[i] >= k) {
          idx = i + 1;
          break;
        }
        k -= (cut[i] - (i ? cut[i - 1] : 0));
      }
      k -= take;
      vector<long long> vo;
      for (long long i = ans.size(); i < idx; i++) vo.push_back(i);
      reverse(vo.begin(), vo.end());
      ans = con(ans, vo);
      if (k == 0)
        while (ans.size() < n) ans.push_back(ans.size());
    }
    for (long long i = 0; i < ans.size(); i++) cout << ans[i] + 1 << ' ';
    puts("");
  }
}
