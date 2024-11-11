#include <bits/stdc++.h>
using namespace std;
template <typename T>
void get_int(T &x) {
  char t = getchar();
  bool neg = false;
  x = 0;
  for (; (t > '9' || t < '0') && t != '-'; t = getchar())
    ;
  if (t == '-') neg = true, t = getchar();
  for (; t <= '9' && t >= '0'; t = getchar()) x = x * 10 + t - '0';
  if (neg) x = -x;
}
template <typename T>
void print_int(T x) {
  if (x < 0) putchar('-'), x = -x;
  short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
const int inf = 0x3f3f3f3f;
const long long Linf = 1ll << 61;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
int pre[1000111][22];
int q, r, n, mn[1000111];
void prework() {
  pre[0][0] = 1;
  for (int i = 1; i <= 20; i++) pre[0][i] = pre[0][i - 1] + 2;
  for (int i = 1; i <= 1000000; i++)
    for (int j = 0; j <= 20; j++) {
      pre[i][j] = pre[i - 1][j];
      if (j) pre[i][j] += pre[i][j - 1];
      if (pre[i][j] >= mod) pre[i][j] -= mod;
    }
  for (int i = 2; i <= 1000000; i++) {
    if (mn[i]) continue;
    for (int j = i; j <= 1000000; j += i) mn[j] = i;
  }
}
int main() {
  prework();
  get_int(q);
  for (int i = 1, n, r; i <= q; i++) {
    get_int(r), get_int(n);
    int ans = 1;
    while (mn[n]) {
      int cnt = 0, tmp = mn[n];
      while (n % tmp == 0) {
        n /= tmp;
        cnt++;
      }
      ans = 1ll * ans * (pre[r][cnt] + mod - pre[r][cnt - 1]) % mod;
    }
    print_int(ans), puts("");
  }
  return 0;
}
