#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char now[1 << 16], *S, *T;
  if (T == S) {
    T = (S = now) + fread(now, 1, 1 << 16, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
inline int read() {
  int x = 0, f = 1;
  char ch = gc();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = gc();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
  return x * f;
}
const int N = 2e5 + 10;
int a[N], n, L, b[N], gr[N << 1];
inline bool check(int len) {
  static int br[N << 1];
  int top = 0;
  for (int i = 1; i <= n; ++i)
    if (b[i] >= len) br[++top] = b[i];
  for (int i = 1; i <= n; ++i)
    if (b[i] + len < L) br[++top] = b[i] + L;
  int i = 1, j = 1;
  while (i <= top) {
    while (j <= 2 * n && abs(br[i] - gr[j]) > len) ++j;
    if (j == 2 * n + 1) break;
    ++i;
    ++j;
  }
  return i == top + 1;
}
int main() {
  n = read();
  L = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= n; ++i) b[i] = read();
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; ++i) gr[i] = a[i], gr[n + i] = a[i] + L;
  int l = 0, r = L >> 1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}
