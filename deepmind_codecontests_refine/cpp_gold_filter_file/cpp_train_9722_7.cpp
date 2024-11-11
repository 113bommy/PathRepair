#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long dp[110000][2];
char s[110000], t[110000];
long long j[220000];
int main() {
  int len;
  cin >> len;
  getchar();
  dp[0][0] = 1;
  dp[0][1] = 1;
  gets(s), gets(t);
  j[0] = 1;
  for (int i = 1; i <= 200000; i++) j[i] = j[i - 1] * 10 % mod;
  int num = 0;
  for (int i = 0; i < len; i++) num += (s[i] == '?') + (t[i] == '?');
  int flag0 = 1, flag1 = 1;
  long long summ = 1;
  for (int i = 0; i < len; i++) {
    char x = s[i], y = t[i];
    if (x != '?' && y != '?') {
      if (x > y)
        flag1 = 0;
      else if (x < y)
        flag0 = 0;
      if (x != y) summ = 0;
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] = dp[i][1];
    } else if (x == '?' && y == '?') {
      dp[i + 1][0] = dp[i][0] * 55 % mod;
      dp[i + 1][1] = dp[i][1] * 55 % mod;
      summ = summ * 10 % mod;
    } else {
      int tmp, tmp2;
      if (x != '?') {
        tmp = x - '0' + 1;
        tmp2 = 11 - tmp;
      } else {
        tmp2 = y - '0' + 1;
        tmp = 11 - tmp2;
      }
      dp[i + 1][0] = dp[i][0] * tmp % mod;
      dp[i + 1][1] = dp[i][1] * tmp2 % mod;
    }
  }
  if (!flag0 && !flag1)
    cout << j[num] << endl;
  else if (flag0 == 0)
    cout << (j[num] - dp[len][1] + mod) % mod << endl;
  else if (flag1 == 0)
    cout << (j[num] - dp[len][0] + mod) % mod << endl;
  else
    cout << (j[num] - dp[len][1] - dp[len][0] + summ + 2 * mod) % mod << endl;
}
