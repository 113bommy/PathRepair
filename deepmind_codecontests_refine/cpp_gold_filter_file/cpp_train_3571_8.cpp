#include <bits/stdc++.h>
using namespace std;
int mylog(int a) {
  int ans = 0;
  if (a & 0xffff0000) {
    ans += 16;
    a >>= 16;
  }
  if (a & 0x0000ff00) {
    ans += 8;
    a >>= 8;
  }
  if (a & 0x000000f0) {
    ans += 4;
    a >>= 4;
  }
  if (a & 0x0000000c) {
    ans += 2;
    a >>= 2;
  }
  if (a & 0x00000002) {
    ans += 1;
    a >>= 1;
  }
  return ans;
}
inline long long read() {
  register long long a = 0, b = 1;
  register char c;
  c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') b = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    a *= 10;
    a += c - '0';
    c = getchar();
  }
  return a * b;
}
const int MAXN = 2010;
double dp[MAXN][MAXN];
int main() {
  int w = read(), b = read();
  for (int i = 1; i <= (w); ++i) dp[i][0] = 1;
  for (int i = 1; i <= (b); ++i) dp[0][i] = 0;
  for (int i = 1; i <= (w); ++i) {
    for (int j = 1; j <= (b); ++j) {
      dp[i][j] += (double)i / (i + j);
      if (j >= 3) {
        dp[i][j] += (double)j / (i + j) * (j - 1) / (i + j - 1) * (j - 2) /
                    (i + j - 2) * dp[i][j - 3];
      }
      if (i >= 1 && j >= 2) {
        dp[i][j] += (double)j / (i + j) * (j - 1) / (i + j - 1) * (i) /
                    (i + j - 2) * dp[i - 1][j - 2];
      }
    }
  }
  printf("%.9lf", dp[w][b]);
  return 0;
}
