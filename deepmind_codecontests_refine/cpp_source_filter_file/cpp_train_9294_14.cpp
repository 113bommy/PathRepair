#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
inline int read() {
  int x = 0, neg = 1;
  char op = getchar();
  while (!isdigit(op)) {
    if (op == '-') neg = -1;
    op = getchar();
  }
  while (isdigit(op)) {
    x = 10 * x + op - '0';
    op = getchar();
  }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
const int N = 110005;
int ok[N];
int pre[N], lst[N];
int a[N], n;
struct Bit {
  int c[N];
  void init() {
    memset(c, 0x3f, sizeof(c));
    c[0] = 0;
  }
  void add(int x, int v) {
    while (x < N) {
      c[x] = min(c[x], v);
      x += x & -x;
    }
  }
  int qry(int x) {
    int ret = 1e9;
    while (x > 0) {
      ret = min(ret, c[x]);
      x ^= x & -x;
    }
    return ret;
  }
} bit;
int main() {
  n = read();
  bool same = 1;
  for (int i = 1; i <= n; i++) {
    a[i] = read(), same &= a[i] == 1;
    pre[i] = lst[a[i]], lst[a[i]] = i;
  }
  if (same) {
    puts("2");
    return 0;
  }
  bit.init();
  for (int i = 1; i <= n + 1; i++) bit.add(i, lst[i]);
  for (int i = 1; i <= n + 1; i++) {
    if (lst[i] != n && bit.qry(i - 1) > lst[i]) ok[i] = 1;
  }
  for (int i = n; i >= 1; i--) {
    bit.add(a[i], pre[i]);
    if (pre[i] != i && bit.qry(a[i] - 1) > pre[i]) ok[a[i]] = 1;
  }
  int cur = 1;
  while (ok[cur]) cur++;
  printf("%d\n", cur);
  return 0;
}
