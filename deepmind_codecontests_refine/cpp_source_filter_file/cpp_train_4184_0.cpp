#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n) {
  long long r = 1 % P;
  for (a %= P; n; a = a * a % P, n >>= 1)
    if (n & 1) r = r * a % P;
  return r;
}
long long inv(long long first) {
  return first <= 1 ? 1 : inv(P % first) * (P - P / first) % P;
}
inline int rd() {
  int first = 0;
  char p = getchar();
  while (p < '0' || p > '9') p = getchar();
  while (p >= '0' && p <= '9') first = first * 10 + p - '0', p = getchar();
  return first;
}
const int N = 3e6 + 10;
int n;
char s[N];
int f[10][10][10];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  memset(f, 0x3f, sizeof f);
  for (int i = 0; i <= 9; ++i)
    for (int j = 0; j <= 9; ++j) {
      for (int ii = 0; ii <= 9; ++ii)
        for (int jj = 0; jj <= 9; ++jj)
          if (!i || !j || ii || jj) {
            f[i][j][(i * ii + j * jj) % 10] =
                min(f[i][j][(i * ii + j * jj) % 10], ii + jj);
          }
    }
  for (int i = 0; i <= 9; ++i) {
    for (int j = 0; j <= 9; ++j) {
      int now = 0, ans = 0;
      for (int k = 1; k <= n; ++k) {
        if (k == 1 && s[k] == '0')
          continue;
        else if (k == 1)
          ++ans;
        int delta = (s[k] - '0' - now) % 10;
        if (delta < 0) delta += 10;
        if (s[k] == s[k - 1])
          ans += f[i][j][0] - 1;
        else
          ans += max(0, f[i][j][delta] - 1);
        now = s[k] - '0';
        if (ans >= INF - 10) break;
      }
      if (ans >= INF - 10) ans = -1;
      printf("%d ", ans);
    }
    putchar(10);
  }
}
