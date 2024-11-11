#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 69;
int dp[205][205][405];
string s, t, ans;
int f(int is, int it, int cnt) {
  if (cnt < 0 || cnt >= s.size() + t.size()) return inf;
  if (is == s.size() && it == t.size() && cnt >= 0) return cnt;
  if (is > s.size() || it > t.size()) return inf;
  if (dp[is][it][cnt] != -1) return dp[is][it][cnt];
  int res = inf;
  res = min(res, 1 + f(is, it, cnt + 1));
  if (is < s.size() && it < t.size() && s[is] == t[it])
    res = min(res, 1 + f(is + 1, it + 1, cnt + (s[is] == '(' ? 1 : -1)));
  else {
    if (is < s.size())
      res = min(res, 1 + f(is + 1, it, cnt + (s[is] == '(' ? 1 : -1)));
    if (it < t.size())
      res = min(res, 1 + f(is, it + 1, cnt + (t[it] == '(' ? 1 : -1)));
  }
  return dp[is][it][cnt] = res;
}
void b(int is, int it, int cnt) {
  if (is == s.size() && it == t.size() && cnt >= 0) {
    for (int i = 0; i < cnt; i++) ans.push_back(')');
    return;
  }
  int res = f(is, it, cnt);
  if (res == 1 + f(is, it, cnt + 1)) {
    ans.push_back('(');
    b(is, it, cnt + 1);
    return;
  }
  if (is < s.size() && it < t.size() && s[is] == t[it]) {
    if (res == 1 + f(is + 1, it + 1, cnt + (s[is] == '(' ? 1 : -1))) {
      ans.push_back(s[is]);
      b(is + 1, it + 1, cnt + (s[is] == '(' ? 1 : -1));
      return;
    }
  } else {
    if (is < s.size() &&
        res == 1 + f(is + 1, it, cnt + (s[is] == '(' ? 1 : -1))) {
      ans.push_back(s[is]);
      b(is + 1, it, cnt + (s[is] == '(' ? 1 : -1));
      return;
    }
    if (it < t.size() &&
        res == 1 + f(is, it + 1, cnt + (t[it] == '(' ? 1 : -1))) {
      ans.push_back(t[it]);
      b(is, it + 1, cnt + (t[it] == '(' ? 1 : -1));
      return;
    }
  }
  return;
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> s >> t;
  f(0, 0, 0);
  b(0, 0, 0);
  cout << ans << endl;
  return 0;
}
