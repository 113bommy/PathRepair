#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char now[1 << 16], *S, *T;
  if (T == S) {
    T = (S = now) + fread(now, 1, 1 << 16, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
inline long long read() {
  register long long x = 0, f = 1;
  char ch = gc();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = gc();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = gc();
  }
  return (f == 1) ? x : -x;
}
bool dp[2][5050];
int n, K;
char s[10101];
signed main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  K = log2(n);
  int nd = n - (1 << K) + 1;
  bool cur = 0;
  int MX = (1 << K) - 1;
  for (int i = 0; i <= MX; i++) dp[cur][i] = 1;
  for (int i = 0; i < nd; i++) {
    cur ^= 1;
    memset(dp[cur], 0, sizeof dp[cur]);
    char nans = 'z';
    for (int j = 0; j <= MX; j++) {
      if (dp[cur ^ 1][j] || dp[cur][j]) {
        nans = min(nans, s[i + j + 1]);
        dp[cur][j] = 1;
        for (int k = MX ^ j; k; k ^= (k & -k)) {
          dp[cur][j ^ (k & -k)] = 1;
        }
        continue;
      }
    }
    for (int j = 0; j < MX; j++) {
      if (s[i + j + 1] == nans && dp[cur][j]) {
        dp[cur][j] = 1;
      } else {
        dp[cur][j] = 0;
      }
    }
    putchar(nans);
  }
  return 0;
}
