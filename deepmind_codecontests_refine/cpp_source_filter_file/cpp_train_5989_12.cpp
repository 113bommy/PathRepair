#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
const long long Linf = 1ll << 61;
const double EPS = 1e-10;
void get_int(int &x) {
  char t = getchar();
  bool neg = false;
  x = 0;
  for (; (t > '9' || t < '0') && t != '-'; t = getchar())
    ;
  if (t == '-') neg = true, t = getchar();
  for (; t <= '9' && t >= '0'; t = getchar()) x = x * 10 + t - '0';
  if (neg) x = -x;
}
void get_int(long long &x) {
  char t = getchar();
  bool neg = false;
  x = 0;
  for (; (t > '9' || t < '0') && t != '-'; t = getchar())
    ;
  if (t == '-') neg = true, t = getchar();
  for (; t <= '9' && t >= '0'; t = getchar()) x = x * 10 + t - '0';
  if (neg) x = -x;
}
void print_int(int x) {
  if (x < 0) putchar('-'), x = -x;
  short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
void print_int(long long x) {
  if (x < 0) putchar('-'), x = -x;
  short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
const int maxlog = 20;
const long long mod = 1000000007;
const int maxn = 105;
int row[maxn], col[maxn];
char s[maxn];
int main() {
  int n;
  get_int(n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= n; j++)
      if (s[j] == 'C') {
        row[i]++;
        col[j]++;
      }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += row[i] * (row[i - 1]) / 2;
    ans += col[i] * (col[i - 1]) / 2;
  }
  print_int(ans), puts("");
  return 0;
}
