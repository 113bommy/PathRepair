#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0;
  char zf = 1;
  char ch;
  while (ch != '-' && !isdigit(ch)) ch = getchar();
  if (ch == '-') zf = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * zf;
}
void write(long long y) {
  if (y < 0) putchar('-'), y = -y;
  if (y > 9) write(y / 10);
  putchar(y % 10 + 48);
}
void writeln(const long long y) {
  write(y);
  putchar('\n');
}
void bemin(long long &x, const long long y) {
  if (y < x) x = y;
}
void bemax(long long &x, const long long y) {
  if (y > x) x = y;
}
int i, j, k, m, n, x, y, z, cnt;
int v[200010];
struct tree {
  double L, R, len;
  double sum, tag1, tag2;
} a[1600010];
void up(const int x) { a[x].sum = a[x << 1].sum + a[x << 1 | 1].sum; }
void build(const int x, const int L, const int R) {
  a[x].L = L;
  a[x].R = R;
  a[x].tag1 = 1;
  a[x].len = (R - L + 1);
  if (L == R) {
    a[x].sum = v[L];
    return;
  }
  const int mid = L + R >> 1;
  build(x << 1, L, mid);
  build(x << 1 | 1, mid + 1, R);
  up(x);
}
void down(const int x) {
  a[x].sum = a[x].sum * a[x].tag1 + a[x].tag2 * a[x].len;
  a[x << 1].tag1 *= a[x].tag1;
  a[x << 1].tag2 *= a[x].tag1;
  a[x << 1 | 1].tag1 *= a[x].tag1;
  a[x << 1 | 1].tag2 *= a[x].tag1;
  a[x << 1].tag2 += a[x].tag2;
  a[x << 1 | 1].tag2 += a[x].tag2;
  a[x].tag1 = 1;
  a[x].tag2 = 0;
}
double query(const int x, const int L, const int R) {
  down(x);
  down(x << 1);
  down(x << 1 | 1);
  if (a[x].L > R || a[x].R < L) return 0;
  if (a[x].L >= L && a[x].R <= R) return a[x].sum;
  return query(x << 1, L, R) + query(x << 1 | 1, L, R);
}
void change(const int x, const int L, const int R, const double mul,
            const double sum) {
  down(x);
  down(x << 1);
  down(x << 1 | 1);
  if (a[x].L > R || a[x].R < L) return;
  if (a[x].L >= L && a[x].R <= R) {
    const int len = a[x].R - a[x].L + 1;
    a[x].tag1 = a[x].tag1 * mul;
    a[x].tag2 = a[x].tag2 * mul;
    a[x].tag2 += sum;
    down(x);
    return;
  }
  change(x << 1, L, R, mul, sum);
  change(x << 1 | 1, L, R, mul, sum);
  up(x);
}
int main() {
  n = read();
  m = read();
  for (register int i = 1; i <= n; i++) v[i] = read();
  build(1, 1, n);
  while (m--) {
    int opt = read();
    if (opt == 1) {
      const int L1 = read(), R1 = read(), L2 = read(), R2 = read();
      double ans1 = query(1, L1, R1), ans2 = query(1, L2, R2);
      change(1, L1, R1, (double)(R1 - L1) / (R1 - L1 + 1),
             ans2 / (R2 - L2 + 1) / (R1 - L1 + 1));
      change(1, L2, R2, (double)(R2 - L2) / (R2 - L2 + 1),
             ans1 / (R1 - L1 + 1) / (R2 - L2 + 1));
    } else {
      const int L = read(), R = read();
      printf("%.6f\n", query(1, L, R));
    }
  }
  return 0;
}
