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
template <class T>
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
template <class T>
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
template <class T>
inline void printsp(T first) {
  print(first);
  putchar(' ');
}
template <class T>
inline void println(T first) {
  print(first);
  putchar('\n');
}
template <class T, class U>
inline void print(T first, U second) {
  printsp(first);
  println(second);
}
template <class T, class U, class V>
inline void print(T first, U second, V z) {
  printsp(first);
  printsp(second);
  println(z);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int row[2020], col[2020];
double dp[2020][2020];
int main() {
  int n, m;
  gn(n, m);
  for (int i = 0; i < m; i++) {
    int u, v;
    gn(u, v);
    row[u] = 1;
    col[v] = 1;
  }
  int r = n, c = n;
  for (int i = 1; i <= n; i++) r -= row[i];
  for (int i = 1; i <= n; i++) c -= col[i];
  for (int i = 0; i <= r; i++)
    for (int j = 0; j <= r; j++) {
      if (i == 0 && j == 0) continue;
      double a = 1.0 * (n - i) * (n - j) / n / n;
      double b = 1.0 * i * (n - j) / n / n;
      double c = 1.0 * j * (n - i) / n / n;
      double d = 1.0 * i * j / n / n;
      dp[i][j] = 1;
      if (i) dp[i][j] += b * dp[i - 1][j];
      if (j) dp[i][j] += c * dp[i][j - 1];
      if (i && j) dp[i][j] += d * dp[i - 1][j - 1];
      dp[i][j] /= 1 - a;
    }
  cout << fixed << setprecision(20) << dp[r][c] << endl;
  return 0;
}
