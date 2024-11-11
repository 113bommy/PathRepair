#include <bits/stdc++.h>
using namespace std;
const int N = 205, M = 100005, mod = 1e9 + 7;
template <class T>
inline void gmin(T &x, const T &y) {
  if (x > y) x = y;
}
template <class T>
inline void gmax(T &x, const T &y) {
  if (x < y) x = y;
}
inline void ch(int &x, int y) { x = (x + y) % mod; }
template <class T>
inline void read(T &x) {
  x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}
template <class T>
inline void print(T x) {
  if (!x) {
    puts("0");
    return;
  }
  int a[20], m = 0;
  while (x) a[m++] = x % 10, x /= 10;
  while (m--) putchar(a[m] + '0');
  puts("");
}
int n, m, L, a[N], b[N], dp[N][N];
int main() {
  ios::sync_with_stdio(0);
  m = 4;
  L = 160;
  scanf("%d", &n);
  dp[0][0] = 1;
  for (int i = 1; i <= L; i++)
    for (int j = 0; j <= m; j++) {
      dp[i][j] = dp[i - 1][j];
      if ((i - 1) % m + 1 == j) dp[i][j] += dp[i - 1][j - 1];
    }
  for (int i = 1; i <= L / m; i++) a[i] = dp[i * m][m];
  for (int i = L / m; i; i--) b[i] = n / a[i], n %= a[i];
  for (int i = L / m; i; i--) {
    for (int j = 1; j <= b[i]; j++) putchar('e');
    printf("dcba");
  }
  puts(" edcba");
  return 0;
}
