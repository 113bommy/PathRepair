#include <bits/stdc++.h>
using namespace std;
int n;
char s[1200000];
long long int dp[1200000][5][5];
long long int bul(int i, int a, int b) {
  long long int &ret = dp[i][a][b];
  if (ret != -1) return ret;
  if (i == n + 1) {
    if (b == 3 or (b == 1 and a == 3) or (b == 0 and a != 3)) return ret = 1;
    return ret = 0;
  }
  ret = 0;
  if (s[i] == '0' or s[i] == '?') {
    if (!((b == 3) or (b == 2) or (b == 1 and a != 3) or (b == 0 and a == 3)))
      ret += bul(i + 1, b, 0);
  }
  if (s[i] == '1' or s[i] == '?') {
    if (!((b == 2) or (b == 1 and a != 3) or (b == 0 and a == 3)))
      ret += bul(i + 1, b, 1);
  }
  if (s[i] == '2' or s[i] == '?') {
    if (!((b == 2) or (b == 1 and a != 3) or (b == 0 and a == 3)))
      ret += bul(i + 1, b, 2);
  }
  if (s[i] == '*' or s[i] == '?') {
    if (b == 3 or (a == 3) + 1 == b) ret += bul(i + 1, b, 3);
  }
  ret %= 1000000007;
  return ret;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  memset(dp, -1, sizeof dp);
  for (int i = n; i >= 1; i--)
    for (int j = 0; j <= 3; j++)
      for (int k = 0; k <= 3; k++) bul(i, j, k);
  long long int res = 0;
  if (n == 1) {
    if (s[1] == '0') return puts("1");
    if (s[1] == '1' or s[1] == '2') return puts("0");
    if (s[1] == '*') return puts("1");
    return puts("2");
  }
  for (int i = 0; i <= 3; i++)
    for (int j = 0; j <= 3; j++) {
      if (s[1] != '?' and !(s[1] == '0' and i == 0) and
          !(s[1] == '1' and i == 1) and !(s[1] == '2' and i == 2) and
          !(s[1] == '*' and i == 3))
        continue;
      if (s[2] != '?' and !(s[2] == '0' and i == 0) and
          !(s[2] == '1' and i == 1) and !(s[2] == '2' and i == 2) and
          !(s[2] == '*' and i == 3))
        continue;
      if ((j == 0 and i == 3) or (j == 2 and i != 3) or (j == 3 and i == 0))
        continue;
      if ((i == 0 and j == 3) or (i == 1 and j != 3) or (i == 2) or
          (i == 3 and j == 0))
        continue;
      res = (res + bul(3, i, j)) % 1000000007LL;
    }
  cout << res << endl;
}
