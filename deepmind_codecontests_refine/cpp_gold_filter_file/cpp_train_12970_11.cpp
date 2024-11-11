#include <bits/stdc++.h>
using namespace std;
const int N = 1e9;
string s;
int dp[100001][3][2];
int calc(int idx, int mod, bool take) {
  if (idx == s.size()) return (mod == 0 && take ? 0 : 1e9);
  int &ret = dp[idx][mod][take];
  if (ret != -1) return ret;
  ret = 1 + calc(idx + 1, mod, take);
  if (s[idx] == '0') {
    if (take) {
      ret = min(ret, calc(idx + 1, (mod * 10 + (s[idx] - '0')) % 3, 1));
    }
  } else
    ret = min(ret, calc(idx + 1, (mod * 10 + (s[idx] - '0')) % 3, 1));
  return ret;
}
string ans = "";
void build(int idx, int mod, bool take) {
  if (idx == s.size()) return;
  if (1 + calc(idx + 1, mod, take) == calc(idx, mod, take)) {
    build(idx + 1, mod, take);
    return;
  }
  if (s[idx] == '0') {
    if (take && calc(idx + 1, (mod * 10 + s[idx] - '0') % 3, 1) ==
                    calc(idx, mod, idx)) {
      ans += '0';
      build(idx + 1, (mod * 10 + s[idx] - '0') % 3, 1);
      return;
    }
  } else {
    if (calc(idx + 1, (mod * 10 + (s[idx] - '0')) % 3, 1) ==
        calc(idx, mod, take)) {
      ans += s[idx];
      build(idx + 1, (mod * 10 + (s[idx] - '0')) % 3, 1);
      return;
    }
  }
}
int main() {
  cin >> s;
  memset(dp, -1, sizeof dp);
  int u = calc(0, 0, 0);
  if (u == 1e9) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        puts("0");
        return 0;
      }
    }
    puts("-1");
    return 0;
  }
  build(0, 0, 0);
  cout << ans << endl;
  return 0;
}
