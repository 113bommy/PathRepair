#include <bits/stdc++.h>
using namespace std;
inline long long input(void) {
  char t;
  long long x = 0;
  int neg = 0;
  t = getchar();
  while ((t < 48 || t > 57) && t != '-') t = getchar();
  if (t == '-') {
    neg = 1;
    t = getchar();
  }
  while (t >= 48 && t <= 57) {
    x = (x << 3) + (x << 1) + t - 48;
    t = getchar();
  }
  if (neg) x = -x;
  return x;
}
inline void output(long long x) {
  char a[20];
  int i = 0, j;
  a[0] = '0';
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x == 0) putchar('0');
  while (x) {
    a[i++] = x % 10 + 48;
    x /= 10;
  }
  for (j = i - 1; j >= 0; j--) {
    putchar(a[j]);
  }
  putchar('\n');
}
char s[5010][5010];
int l[5010][5010];
int main() {
  long long n, m, i, j, d, k, x, ans = 0;
  n = input();
  m = input();
  for (i = 0; i < n; i++) scanf("%s", s[i]);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (s[i][j] == '1') {
        x = j;
        while (x < m && s[i][x] == '1') x++;
        x--;
        l[j][x]++;
        j = x;
      }
    }
  }
  for (i = 0; i < m; i++)
    for (j = m - 1; j >= i; j--) {
      if (j != m - 1) l[i][j] += l[i][j + 1];
      if (i != 0) l[i][j] += l[i - 1][j];
      if (i != 0 && j != m - 1) l[i][j] -= l[i - 1][j + 1];
      ans = max(ans, (j - i + 1) * l[i][j]);
    }
  output(ans);
  return 0;
}
