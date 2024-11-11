#include <bits/stdc++.h>
using namespace std;
const int L = 6;
const int N = 15e4 + 5, P = 4 * N;
int n, Q, p, i, x, y, k;
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
struct arr {
  int x, k;
};
bool operator<(arr A, arr B) { return A.k > B.k; }
struct tree {
  int n;
  arr a[L + 1];
} f[P], Cl, ans;
int cv[P], num[P];
int q[N], g[N];
arr a[3 * L];
tree operator+(tree A, tree B) {
  tree C;
  int i, n = A.n + B.n, m = 0;
  for (i = 1; i <= A.n; i++) q[i] = A.a[i].x, g[A.a[i].x] += A.a[i].k;
  for (i = 1; i <= B.n; i++) q[i + A.n] = B.a[i].x, g[B.a[i].x] += B.a[i].k;
  for (i = 1; i <= n; i++)
    if (g[q[i]]) {
      a[++m] = (arr){q[i], g[q[i]]};
      g[q[i]] = 0;
    }
  sort(a + 1, a + m + 1);
  if (m > L) m = L;
  C.n = m;
  for (i = 1; i <= m; i++) C.a[i] = a[i];
  return C;
}
void up(int p) { f[p] = f[p << 1] + f[p << 1 | 1]; }
void cover(int p, int k) {
  cv[p] = k;
  f[p].n = 1;
  f[p].a[1] = (arr){k, num[p]};
}
void down(int p) {
  if (cv[p]) {
    cover(p << 1, cv[p]);
    cover(p << 1 | 1, cv[p]);
    cv[p] = 0;
  }
}
void change(int p, int l, int r) {
  if (x <= l && r <= y) {
    cover(p, k);
    return;
  }
  int m = l + r >> 1;
  down(p);
  if (x <= m) change(p << 1, l, m);
  if (y > m) change(p << 1 | 1, m + 1, r);
  up(p);
}
void ask(int p, int l, int r) {
  if (x <= l && r <= y) {
    ans = ans + f[p];
    return;
  }
  int m = l + r >> 1;
  down(p);
  if (x <= m) ask(p << 1, l, m);
  if (y > m) ask(p << 1 | 1, m + 1, r);
}
void build(int p, int l, int r) {
  num[p] = r - l + 1;
  if (l == r) {
    f[p].n = 1;
    f[p].a[1] = (arr){read(), 1};
    return;
  }
  int m = l + r >> 1;
  build(p << 1, l, m);
  build(p << 1 | 1, m + 1, r);
  up(p);
}
int main() {
  n = read();
  Q = read();
  p = 100 / read();
  for (build(1, 1, n); Q--;) {
    int opt = read();
    x = read();
    y = read();
    if (opt == 1)
      k = read(), change(1, 1, n);
    else {
      ans = Cl;
      ask(1, 1, n);
      int t = min(p, ans.n);
      write(t);
      for (i = 1; i <= t; i++) putchar(' '), write(ans.a[i].x);
      putchar('\n');
    }
  }
}
