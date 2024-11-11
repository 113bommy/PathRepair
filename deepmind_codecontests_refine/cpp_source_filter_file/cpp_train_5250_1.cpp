#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return (a == 0) ? b : (b == 0) ? a : gcd(b, a % b); }
int str_div(char *s, int n) {
  int y = 0, ln = strlen(s);
  for (int i = 0; i < ln; ++i) y = (y * 10 + (s[i] - 48)) % n;
  return y;
}
int get() {
  int y = 0, s = 1, i = 10;
  char c = getchar();
  while (!(c >= 48 && c <= 57)) {
    if (c == '-') s = -1;
    c = getchar();
  }
  while ((c >= 48 && c <= 57)) {
    y = y * 10 + (c - '0'), c = getchar();
  }
  if (c != '.') return y;
  c = getchar();
  while ((c >= 48 && c <= 57)) y = y + (c - '0') / i, i *= 10, c = getchar();
  return y * s;
}
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int main() {
  ios_base::sync_with_stdio(false);
  char s1[1001];
  gets(s1);
  int ln = strlen(s1), ans = -1, tmp = 0, dp[1001];
  for (int i = 0; i < ln; ++i) {
    for (int j = 0; j < i; ++j)
      if (s1[i] == s1[j] && (i - j) & 1) dp[i] = max(dp[i], dp[j] + 1);
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans + 1);
}
