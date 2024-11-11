#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
const int mod = 1e9 + 7;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = getchar();
  return x * f;
}
int p[N];
int calc(char *s) {
  int len = strlen(s + 1);
  int res = 0;
  for (int i = 1; i <= len; i++)
    if (s[i] == '1') res |= 1 << (p[i - 1]);
  return res;
}
int dp[N][2];
char s[N], t[N];
int main() {
  int n = read(), m = read(), k = read();
  scanf("%s", t + 1);
  scanf("%s", s + 1);
  int st = 1 << k;
  for (int i = 0; i < st; i++) {
    dp[i][1] = -1e9;
    dp[i][0] = 1e9;
  }
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < k; i++) p[i] = i;
  for (int i = 1; i <= k; i++) cnt1 += (s[i] == '1'), cnt2 += (t[i] == '1');
  dp[calc(t)][0] = 0;
  dp[calc(s)][1] = 0;
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read();
    swap(p[x - 1], p[y - 1]);
    dp[calc(s)][1] = max(dp[calc(s)][1], i);
    dp[calc(t)][0] = min(dp[calc(t)][0], i);
  }
  int ans = 0, la = 1, ra = n;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < st; j++)
      if (j & (1 << i)) {
        dp[j ^ (1 << i)][1] = max(dp[j ^ (1 << i)][1], dp[j][1]);
        dp[j ^ (1 << i)][0] = min(dp[j ^ (1 << i)][0], dp[j][0]);
      }
  }
  for (int j = st - 1; j >= 0; j--) {
    int cnt = __builtin_popcount(j);
    if (cnt1 >= cnt && cnt2 >= cnt) {
      int res = k - (cnt1 + cnt2 - 2 * cnt);
      if (dp[j][1] - dp[j][0] >= m) {
        if (res > ans) {
          ans = res;
          la = dp[j][0] + 1;
          ra = dp[j][1];
        }
      }
    }
  }
  cout << ans << endl;
  cout << la << " " << ra << endl;
}
