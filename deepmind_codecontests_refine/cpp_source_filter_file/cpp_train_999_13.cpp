#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <typename T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T, class T1>
inline void gn(T &first, T1 &second) {
  gn(first);
  gn(second);
}
template <class T, class T1, class T2>
inline void gn(T &first, T1 &second, T2 &z) {
  gn(first);
  gn(second);
  gn(z);
}
template <typename T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
template <typename T>
inline void println(T first) {
  print(first), putchar('\n');
}
template <typename T>
inline void printsp(T first) {
  print(first), putchar(' ');
}
template <class T, class T1>
inline void print(T first, T1 second) {
  printsp(first), println(second);
}
template <class T, class T1, class T2>
inline void print(T first, T1 second, T2 z) {
  printsp(first), printsp(second), println(z);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int a[300300];
int dp[300300][25];
int main() {
  int n;
  gn(n);
  for (int i = 1; i <= n; i++) gn(a[i]);
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < 25; j++) {
      if (a[i] == 1000) smin(dp[i][j], dp[i - 1][j - 1] + a[i]);
      if (a[i] == 2000 && j > 1) smin(dp[i][j], dp[i - 1][j - 2] + a[i]);
    }
    for (int j = 1; j < 25; j++) {
      for (int k = min(j, a[i] / 100); k >= 0; k--) {
        smin(dp[i][j - k], dp[i - 1][j] + a[i] - 100 * k);
      }
    }
  }
  int ans = 0x3f3f3f3f;
  for (int i = 0; i < 25; i++) smin(ans, dp[n][i]);
  println(ans);
  return 0;
}
