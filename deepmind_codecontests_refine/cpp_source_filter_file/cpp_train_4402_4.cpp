#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int num = 0;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar())
    num = (num << 1) + (num << 3) + (c ^ 48);
  return num;
}
vector<int> a;
long long dp[40][2];
inline void solve(vector<int> s, int p) {
  if (s.empty() || p < 0) return;
  vector<int> L, R;
  int cnt1 = 0, cnt2 = 0;
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < s.size(); ++i) {
    int x = s[i];
    if ((x >> p) & 1) {
      ans2 += cnt1;
      ++cnt2;
      R.push_back(x);
    } else {
      ans1 += cnt2;
      ++cnt1;
      L.push_back(x);
    }
  }
  dp[p][0] += ans2;
  dp[p][1] += ans1;
  solve(L, p - 1);
  solve(R, p - 1);
}
int main() {
  int n = read();
  for (int i = 1; i <= n; ++i) {
    int x = read();
    a.push_back(x);
  }
  reverse(a.begin(), a.end());
  solve(a, 30);
  long long Ans = 0;
  int res = 0;
  for (int i = 30; ~i; --i) {
    if (dp[i][0] > dp[i][1])
      Ans += dp[i][1], res ^= 1 << i;
    else
      Ans += dp[i][0];
  }
  printf("%lld %d", Ans, res);
  return 0;
}
