#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void pr1(int x) { write(x), putchar(' '); }
inline void pr2(int x) { write(x), puts(""); }
int n, s[100010];
inline int lowbit(int x) { return x & -x; }
inline void add(int x, int d) {
  while (x <= n) {
    s[x] += d;
    x += lowbit(x);
  }
}
inline int getsum(int x) {
  int sum = 0;
  while (x >= 1) {
    sum += s[x];
    x -= lowbit(x);
  }
  return sum;
}
struct node {
  int x, y, next;
} a[200010];
int len, last[100010];
inline void ins(int x, int y) {
  len++;
  a[len].x = x;
  a[len].y = y;
  a[len].next = last[x];
  last[x] = len;
}
int id, tot[100010], fa[100010], cnt[100010], ys[100010];
inline void dfs(int x) {
  tot[x] = 1;
  ys[x] = ++id;
  for (int k = last[x]; k; k = a[k].next) {
    int y = a[k].y;
    if (y == fa[x]) continue;
    fa[y] = x;
    dfs(y);
    tot[x] += tot[y];
  }
}
bool v[100010];
int main() {
  n = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    ins(x, y), ins(y, x);
    cnt[x]++, cnt[y]++;
  }
  dfs(1);
  bool bk = true;
  for (int i = 1; i <= n; i++) {
    int x = i;
    int w1 = -1, w2 = -1, t1 = 0, t2 = 0, u1, u2;
    for (int k = last[x]; k; k = a[k].next) {
      int y = a[k].y, uf = tot[y];
      if (y == fa[x]) uf = n - tot[x];
      if (w1 == -1)
        w1 = y, t1++, u1 = uf;
      else {
        if (uf != u1) {
          if (w2 == -1 || uf == u2)
            w2 = y, t2++, u2 = uf;
          else {
            bk = false;
            break;
          }
        } else
          t1++;
      }
    }
    if (t1 > 1 && t2 > 1) bk = false;
    if (bk == false) break;
    if (w2 != -1) {
      v[x] = true;
      if (cnt[x] != 2) {
        int p;
        if (t1 == 1)
          p = w1;
        else
          p = w2;
        if (p == fa[x])
          add(ys[x], 1), add(ys[x] + tot[x], -1);
        else {
          add(1, 1);
          add(ys[p], -1), add(ys[p] + tot[p], 1);
        }
      }
    }
  }
  if (bk == false) {
    pr2(-1);
    return 0;
  }
  int ans = -1;
  for (int i = n; i >= 1; i--)
    if (getsum(ys[i]) == 0 && v[i] == false) {
      ans = i;
      break;
    }
  pr2(ans);
  return 0;
}
