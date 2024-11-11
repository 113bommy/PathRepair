#include <bits/stdc++.h>
using namespace std;
int n;
char num[55];
long long ans;
long long memo[55][20][2];
long long dp(int index, int cur, bool same) {
  if (index == n - 1) {
    if (same)
      return 0;
    else
      return 1;
  }
  if (memo[index][cur][same] != -1) return memo[index][cur][same];
  memo[index][cur][same] = 0;
  int digit = (int)num[index + 1] - '0';
  int nxt = (cur + digit) / 2;
  memo[index][cur][same] += dp(index + 1, nxt, nxt == digit && same);
  if ((cur + digit) % 2 == 1)
    memo[index][cur][same] +=
        dp(index + 1, nxt + 1, (nxt + 1) == digit && same);
  return memo[index][cur][same];
}
int main() {
  scanf(" %s", num);
  n = strlen(num);
  memset(memo, -1, sizeof memo);
  for (int i = 0; i < 10; i++) ans += dp(0, i, i == (int)num[0] - '0');
  printf("%d\n", ans);
  return 0;
}
