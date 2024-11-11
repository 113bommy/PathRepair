#include <bits/stdc++.h>
using namespace std;
const int MAX = 2005, MOD = 1000003;
int dp[MAX][MAX];
char ss[MAX], rs[MAX];
int n, cnt;
int sol(int pos, int num) {
  if (num < 0)
    return 0;
  else if (num > n)
    return 0;
  else {
    auto &ele = dp[pos][num];
    if (ele != -1) return ele;
    char c = rs[pos];
    if (c == '*' || c == '/')
      return ele = 0;
    else {
      if (c == '+' || c == '-') {
        return ele = (sol(pos, num + 1) + sol(pos + 1, num)) % MOD;
      } else {
        if (pos == cnt - 1) {
          return ele = num == 0;
        } else {
          ele = sol(pos, num + 1);
          ele += sol(pos + 2, num - 1);
          ele %= MOD;
          return ele;
        }
      }
    }
  }
}
int main() {
  scanf("%s", ss);
  n = strlen(ss);
  bool pr = 0;
  for (int i = 0; i < n; i++) {
    if (ss[i] <= '9' && ss[i] >= '0') {
      if (pr == 0) {
        rs[cnt++] = '0';
        pr = 1;
      }
    } else {
      pr = 0;
      rs[cnt++] = ss[i];
    }
  }
  rs[cnt] = 0;
  bool ok = 1;
  for (int i = 0; i < cnt; i++) {
    if (rs[i] == '*' || rs[i] == '/') {
      if (i == 0 || rs[i - 1] != '0') {
        ok = 0;
        break;
      }
    }
  }
  if (ok && rs[cnt - 1] != '0') ok = 0;
  if (!ok) {
    printf("%d\n", 0);
  } else {
    memset(dp, -1, sizeof(dp));
    printf("%d\n", sol(0, 0));
  }
  return 0;
}
