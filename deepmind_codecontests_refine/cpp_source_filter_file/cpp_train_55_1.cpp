#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, o = 1;
  char ch = getchar();
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
const int N = 105;
int sum1, sum2, ans1, ans2, f[N][N * N];
struct ppx {
  int res, val;
} a[N];
inline bool cmp(ppx x, ppx y) {
  return x.val == y.val ? x.res > y.res : x.val > y.val;
}
int main() {
  int n = read();
  for (int i = 1; i <= n; ++i) {
    a[i].res = read();
    sum1 += a[i].res;
  }
  for (int i = 1; i <= n; ++i) {
    a[i].val = read();
    sum2 += a[i].val;
  }
  int now = 0;
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    now += a[i].val;
    if (now >= sum1) {
      ans1 = i;
      break;
    }
  }
  memset(f, -1, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = sum2; j >= a[i].val; --j)
      for (int k = 1; k <= ans1; ++k)
        f[k][j] = max(f[k][j], f[k - 1][j - a[i].val] + a[i].res);
  for (int i = sum1; i <= sum2; ++i) ans2 = max(ans2, f[ans1][i]);
  printf("%d %d\n", ans1, sum1 - ans2);
  return 0;
}
