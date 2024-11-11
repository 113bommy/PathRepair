#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 100010;
inline int lowbit(int x) { return x & (-x); }
int n, m, x, c;
int s[maxn];
int dp[maxn];
inline int read() {
  int x = 0, f = 1;
  char ch = 0;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
  return x * f;
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) s[i] = read();
  for (int i = 1; i <= n; ++i) {
    int L = max(1, i - m), R = min(n, i + m);
    int PL = max(1, s[i] - m), PR = min(n, s[i] + m);
    int con = max(0, PR - L + 1);
    if (i == 1)
      dp[i] = R - L + 1;
    else
      dp[i] = dp[s[i]] + (R - L + 1) - con;
  }
  for (int i = 1; i <= n; ++i) printf("%d ", dp[i]);
}
