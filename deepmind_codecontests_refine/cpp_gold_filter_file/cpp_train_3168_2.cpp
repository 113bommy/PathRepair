#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m, Q;
long long mx;
struct Tree {
  long long del[5000005], dei[5000005];
  int n;
  void Clear(int u) {
    memset(del, 0, sizeof(del));
    memset(dei, 0, sizeof(dei));
    n = u;
  }
  int lowbit(int x) { return x & (-x); }
  void Add(int x, long long y) {
    for (int i = x; i; i -= lowbit(i)) del[i] += y;
    for (int i = x; i <= n; i += lowbit(i)) dei[i] += x * y;
  }
  long long Sum(int x) {
    long long ans = 0, ans2 = 0;
    for (int i = x; i <= n; i += lowbit(i)) ans += del[i];
    for (int i = x - 1; i; i -= lowbit(i)) ans2 += dei[i];
    return ans * x + ans2;
  }
  long long Query(int x, int y) { return Sum(y) - Sum(x - 1); }
} X, Y;
int main() {
  n = read();
  m = read();
  Q = read();
  mx = 0;
  X.Clear(m);
  Y.Clear(n);
  while (Q--) {
    int opt = read(), x1 = read(), y1 = read(), x2 = read(), y2 = read();
    if (opt == 0) {
      long long v = read(), addx, addy;
      addx = v * (y2 - y1 + 1);
      addy = v * (x2 - x1 + 1);
      Y.Add(x2, addx);
      if (x1 - 1) Y.Add(x1 - 1, -addx);
      X.Add(y2, addy);
      if (y1 - 1) X.Add(y1 - 1, -addy);
      mx += (y2 - y1 + 1) * (x2 - x1 + 1) * v;
    }
    if (opt == 1) {
      long long ans = -mx;
      ans += X.Query(y1, y2);
      ans += Y.Query(x1, x2);
      printf("%I64d\n", ans);
    }
  }
  return 0;
}
