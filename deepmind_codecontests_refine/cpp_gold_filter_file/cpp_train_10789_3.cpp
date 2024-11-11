#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
bool Finish_read;
template <class T>
inline void read(T &x) {
  Finish_read = 0;
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    if (ch == EOF) return;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  x *= f;
  Finish_read = 1;
}
template <class T>
inline void print(T x) {
  if (x / 10 != 0) print(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
inline void writeln(T x) {
  if (x < 0) putchar('-');
  x = abs(x);
  print(x);
  putchar('\n');
}
template <class T>
inline void write(T x) {
  if (x < 0) putchar('-');
  x = abs(x);
  print(x);
}
const int maxn = 1005, maxc = 10005;
long long n, w, b, x, v[maxn], c[maxn], dp[maxn][maxc], o;
int main() {
  read(n);
  read(w);
  read(b);
  read(x);
  for (int i = 1; i <= n; i++) read(v[i]);
  for (int i = 1; i <= n; i++) read(c[i]);
  memset(dp, -1, sizeof dp);
  dp[1][0] = w;
  for (int i = 1; i <= n; o += v[i], i++)
    for (int j = 0; j <= o && ~dp[i][j]; j++)
      for (int k = 0; k <= v[i] && dp[i][j] - k * c[i] >= 0; k++)
        dp[i + 1][j + k] = max(dp[i + 1][j + k],
                               min(w + (j + k) * b, dp[i][j] - k * c[i] + x));
  for (int i = maxc; ~i; i--)
    if (~dp[n + 1][i]) {
      printf("%d\n", i);
      return 0;
    }
}
