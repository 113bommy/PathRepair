#include <bits/stdc++.h>
const int MAXN = 1e5 + 10;
const long long MOD = 1e9 + 7;
using namespace std;
inline long long in() {
  long long x = 0, flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * flag;
}
int n, mx, odd;
int a[MAXN];
int gcd(int x, int y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
char ch[233333];
int main() {
  n = in();
  for (int i = 1; i <= n; i++) {
    a[i] = in();
    mx = gcd(mx, a[i]);
    odd += a[i] % 2;
  }
  if (odd >= 2) {
    printf("0\n");
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= a[i]; j++) printf("%c", 'a' + i - 1);
    return 0;
  } else if (odd == 1) {
    int len = 0, od = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] % 2) {
        od = i;
        printf("%d\n", mx);
        continue;
      }
      for (int j = 1; j <= a[i] / mx / 2; j++) ch[++len] = 'a' + i - 1;
    }
    for (int i = 1; i <= a[i] / mx; i++) ch[i + len] = 'a' + od - 1;
    for (int i = 1; i <= len; i++) ch[i + len + a[od] / mx] = ch[len - i + 1];
    len = len * 2 + a[od] / mx;
    for (int j = 1; j <= mx; j++)
      for (int i = 1; i <= len; i++) printf("%c", ch[i]);
  } else {
    int len = 0;
    printf("%d\n", mx);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= a[i] / mx; j++) ch[++len] = i + 'a' - 1;
    for (int i = 1; i <= mx; i++) {
      if (i % 2 == 1)
        for (int j = 1; j <= len; j++) printf("%c", ch[j]);
      else
        for (int j = len; j >= 1; j--) printf("%c", ch[j]);
    }
  }
  return 0;
}
