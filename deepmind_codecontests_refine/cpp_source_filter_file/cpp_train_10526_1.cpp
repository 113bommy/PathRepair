#include <bits/stdc++.h>
using namespace std;
template <typename Tp>
inline int getmin(Tp &x, Tp y) {
  return y < x ? x = y, 1 : 0;
}
template <typename Tp>
inline int getmax(Tp &x, Tp y) {
  return y > x ? x = y, 1 : 0;
}
template <typename Tp>
inline void read(Tp &x) {
  x = 0;
  int f = 0;
  char ch = getchar();
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') f = 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  if (f) x = -x;
}
int n, L, R, mid;
char c0, op[10];
int main() {
  scanf("%d", &n);
  L = 0;
  R = 1e9;
  printf("%d %d\n", 0, 0);
  fflush(stdout);
  scanf("%s", op);
  c0 = op[0];
  for (int i = 2; i <= n; i++) {
    mid = (L + R) >> 1;
    printf("%d %d\n", mid, 0);
    fflush(stdout);
    scanf("%s", op);
    if (op[0] == c0)
      L = mid;
    else
      R = mid;
  }
  printf("%d %d %d %d\n", R, 1, R + 1, 3);
  fflush(stdout);
  return 0;
}
