#include <bits/stdc++.h>
using namespace std;
string str;
int dp[100002][3][2];
pair<int, int> memo[100002][3][2];
int dfs(int now, int mod, int flag) {
  int& ret = dp[now][mod][flag];
  if (ret != -1) return ret;
  ret = 1e9;
  if (now == (int)str.size()) {
    if (mod == 0 && flag) ret = 0;
    return ret;
  }
  if (str[now] - '0' != 0) {
    int dd = dfs(now + 1, mod, 1);
    if (ret > dd) {
      ret = dd;
      memo[now][mod][flag] = make_pair(1, 1);
    }
  } else {
    if (flag) {
      int dd = dfs(now + 1, mod, 1);
      if (ret > dd) {
        ret = dd;
        memo[now][mod][flag] = make_pair(1, 1);
      }
    }
  }
  int nextmod = mod - ((str[now] - '0') % 3);
  while (nextmod < 0) nextmod += 3;
  int dd = dfs(now + 1, nextmod, flag);
  if (ret > dd) {
    ret = dd;
    memo[now][mod][flag] = make_pair(0, flag);
  }
  return ret;
}
void back(int now, int mod, int flag) {
  if (now == (int)str.size()) return;
  int nextmod = mod;
  if (memo[now][mod][flag].first == 1) {
    printf("%c", str[now]);
  } else {
    nextmod -= ((str[now] - '0') % 3);
    while (nextmod < 0) nextmod += 3;
  }
  back(now + 1, nextmod, memo[now][mod][flag].second);
}
int waszero;
int main() {
  cin >> str;
  memset(dp, -1, sizeof(dp));
  int mymod = 0;
  for (int i = 0; i < str.size(); i++) {
    mymod += (str[i] - '0');
    mymod %= 3;
    if (str[i] == '0') waszero = 1;
  }
  int ans = dfs(0, mymod, 0);
  if (ans == 1e9) {
    if (waszero) {
      printf("%d", 0);
      return 0;
    }
    puts("-1");
    return 0;
  }
  back(0, mymod, 0);
}
