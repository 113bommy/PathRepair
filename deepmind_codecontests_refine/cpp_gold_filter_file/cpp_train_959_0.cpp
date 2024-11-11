#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double PI = 2 * acos(0.0);
int cc, bb;
char ch;
int F() {
  while (ch = getchar(), (ch < 48 || ch > 57) && ch != '-')
    ;
  ch == '-' ? cc = bb = 0 : (cc = ch - '0', bb = 1);
  while (ch = getchar(), ch > 47 && ch < 58)
    cc = (cc << 1) + (cc << 3) + (ch ^ 48);
  return bb ? cc : -cc;
}
void write(int x) {
  int y = 10, len = 1;
  while (y <= x) {
    y *= 10;
    len++;
  }
  while (len--) {
    y /= 10;
    putchar(x / y + 48);
    x %= y;
  }
}
int n;
int a[400007];
int s[1 << 25];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int p = 0;
  int res = 0;
  int buf, l, r;
  for (int i = 0; i < 25; i++) {
    p <<= 1;
    p |= 1;
    memset(s, 0, (p + 1) << 2);
    long long sum = 0;
    for (int j = 0; j < n; j++) s[a[j] & p]++;
    for (int j = 1; j <= p; j++) s[j] += s[j - 1];
    for (int j = 0; j < n; j++) {
      buf = a[j] & p;
      r = p - buf;
      l = (1 << i) - buf - 1;
      sum += s[r] - (l >= 0 ? s[l] : 0);
      l = min(p, p + (1 << i) - buf);
      sum += s[p] - s[l];
      if ((a[j] << 1) & (1 << i)) sum--;
    }
    if (sum % 4) res |= (1 << i);
  }
  printf("%d\n", res);
  ;
  return 0;
}
