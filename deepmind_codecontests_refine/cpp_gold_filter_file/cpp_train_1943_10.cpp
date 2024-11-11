#include <bits/stdc++.h>
using namespace std;
const int MAXL = 1005, P = 1000000007;
int digit[MAXL], lucky[10], LIMIT, LEN;
long long dp[MAXL][MAXL], Pow10[MAXL], topMod[MAXL];
char str[MAXL];
long long rec(int pos, int dist, int bound) {
  if (pos == -1) return 0;
  if (!bound && dp[pos][dist] != -1) return dp[pos][dist];
  long long ret = 0;
  int end = bound ? digit[pos] : 9;
  for (int d = 0; d <= end; d++) {
    int nBound = bound && d == end;
    if (lucky[d] && dist)
      ret += nBound ? (topMod[pos] + 1) : Pow10[pos];
    else
      ret += rec(pos - 1,
                 lucky[d] ? 1 : ((dist && dist + 1 <= LIMIT) ? dist + 1 : 0),
                 nBound);
  }
  ret %= P;
  if (!bound) dp[pos][dist] = ret;
  return ret;
}
long long calc(char number[]) {
  LEN = strlen(number);
  for (int i = 0; i < LEN; i++) {
    digit[i] = number[LEN - 1 - i] - '0';
    topMod[i + 1] = Pow10[i] * digit[i] + (i ? topMod[i] : 0);
    topMod[i + 1] %= P;
  }
  return rec(LEN - 1, 0, 1);
}
void init() {
  Pow10[0] = 1;
  for (int i = 1; i < MAXL; i++) Pow10[i] = Pow10[i - 1] * 10 % P;
  memset(dp, -1, sizeof(dp));
  lucky[4] = lucky[7] = 1;
}
int checkLucky(char number[]) {
  int len = strlen(number);
  for (int i = 0, dist = 0; i < len; i++) {
    if (dist && lucky[number[i] - '0']) return 1;
    dist = lucky[number[i] - '0']
               ? 1
               : ((dist && dist + 1 <= LIMIT) ? dist + 1 : 0);
  }
  return 0;
}
int main() {
  init();
  for (int qnum; ~scanf("%d %d", &qnum, &LIMIT);) {
    while (qnum--) {
      scanf("%s", str);
      int luckyL = checkLucky(str);
      long long resL = calc(str);
      scanf("%s", str);
      long long resR = calc(str);
      long long res = ((resR - resL + luckyL) % P + P) % P;
      cout << res << endl;
    }
  }
  return 0;
}
