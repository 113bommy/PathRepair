#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long x = 0;
  int op = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') op = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return x * op;
}
inline void write(long long a) {
  if (a < 0) putchar('-'), a = -a;
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
const int N = 1010;
int n, m, k;
long long a[N][N], s1[N][N], s2[N][N];
int main() {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + read();
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= m; j++) {
      s1[i][j] = s1[i - 1][j + 1] + a[i][j] -
                 ((i - k >= 0 && j + k <= m) ? a[i - k][j + k] : 0);
      if (j)
        s2[i][j] = s2[i - 1][j - 1] + a[i][j] -
                   ((i - k >= 0 && j - k >= 0) ? a[i - k][j - k] : 0);
    }
  long long mx = -1, x, y;
  for (int i = k; i <= n - k + 1; i++)
    for (int j = k; j <= m - k + 1; j++) {
      long long tmp = s1[i + k - 1][j] + s1[i - 1][j - k] -
                      s2[i - 1][j + k - 1] - s2[i + k - 1][j - 1];
      if (tmp > mx) {
        mx = tmp;
        x = i;
        y = j;
      }
    }
  write(x);
  putchar(' ');
  write(y);
  return 0;
}
