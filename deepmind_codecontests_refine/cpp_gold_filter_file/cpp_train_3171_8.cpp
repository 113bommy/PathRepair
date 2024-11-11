#include <bits/stdc++.h>
const int N = 1e5 + 5;
int n, m, i, st, ed, a[N], f[N];
int read() {
  char c = getchar();
  int k = 0;
  for (; c < 48 || c > 57; c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) k = (k << 3) + (k << 1) + c - 48;
  return k;
}
void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + 48);
}
void add(int x, int k) {
  for (a[x] += k; x <= n; x += x & -x) f[x] += k;
}
int sum(int x) {
  int k = 0;
  for (; x; x -= x & -x) k += f[x];
  return k;
}
int ask(int l, int r) { return sum(r) - sum(l - 1); }
void fold_it() {
  int k = read();
  if (st <= ed) {
    int len = ed - st + 1;
    if (k * 2 <= len) {
      for (i = st + k - 1; i >= st; i--) add(2 * st + 2 * k - 1 - i, a[i]);
      st = st + k;
    } else {
      for (i = st + k; i <= ed; i++) add(2 * st + 2 * k - 1 - i, a[i]);
      ed = st;
      st = st + k - 1;
    }
  } else {
    int len = st - ed + 1;
    if (k * 2 <= len) {
      for (i = st - k + 1; i <= st; i++) add(2 * st - 2 * k + 1 - i, a[i]);
      st = st - k;
    } else {
      for (i = st - k; i >= ed; i--) add(2 * st - 2 * k + 1 - i, a[i]);
      ed = st;
      st = st - k + 1;
    }
  }
}
void query_it() {
  int l = read(), r = read() - 1;
  if (st <= ed)
    write(ask(st + l, st + r));
  else
    write(ask(st - r, st - l));
  putchar('\n');
}
int main() {
  n = read();
  m = read();
  st = 1;
  ed = n;
  for (i = 1; i <= n; i++) a[i] = 1, f[i] = i & -i;
  for (; m--;) {
    int opt = read();
    if (opt == 1)
      fold_it();
    else
      query_it();
  }
}
