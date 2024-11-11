#include <bits/stdc++.h>
using namespace std;
int gi() {
  int x = 0, w = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') w = 0, ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return w ? x : -x;
}
const int N = 5005;
const unsigned long long base = 20020415;
int n, a, b, q[N], hd = 1, tl, f[N];
char s[N];
unsigned long long hsh[N], pw[N];
unsigned long long cal(int l, int r) {
  return hsh[r] - hsh[l - 1] * pw[r - l + 1];
}
bool check(int l, int r, int x, int y) {
  if (y - x > r - l) return false;
  unsigned long long val = cal(x, y);
  for (int i = l; i + y - x <= r; ++i)
    if (cal(i, i + y - x) == val) return true;
  return false;
}
int main() {
  n = gi();
  a = gi();
  b = gi();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) hsh[i] = hsh[i - 1] * base + s[i];
  for (int i = pw[0] = 1; i <= n; ++i) pw[i] = pw[i - 1] * base;
  for (int i = 1, j = 1; i <= n; ++i) {
    f[i] = f[i - 1] + a;
    while (j < i && !check(1, j, j + 1, i)) ++j;
    while (hd <= tl && q[hd] < j) ++hd;
    if (hd <= tl) f[i] = min(f[i], f[q[hd]] + b);
    while (hd <= tl && f[i] <= f[q[tl]]) --tl;
    q[++tl] = i;
  }
  printf("%d\n", f[n]);
  return 0;
}
