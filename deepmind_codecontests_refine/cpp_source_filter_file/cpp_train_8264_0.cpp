#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int MOD = 1e9 + 7;
int fx[] = {-1, +0, +1, +0, +1, +1, -1, -1, +0};
int fy[] = {+0, -1, +0, +1, +1, -1, +1, -1, +0};
template <typename T>
inline T GCD(T a, T b) {
  a = abs(a);
  b = abs(b);
  if (a < b) swap(a, b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
template <typename T>
inline T EGCD(T a, T b, T &x, T &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  T x1, y1;
  T d = EGCD(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
template <typename T>
inline T LCM(T x, T y) {
  T tp = GCD(x, y);
  if ((x / tp) * 1. * y > 9e18) return 9e18;
  return (x / tp) * y;
}
template <typename T>
inline T BigMod(T A, T B, T M = MOD) {
  T ret = 1;
  while (B) {
    if (B & 1) ret = (ret * A) % M;
    A = (A * A) % M;
    B = B >> 1;
  }
  return ret;
}
template <typename T>
inline T InvMod(T A, T M = MOD) {
  return BigMod(A, M - 2, M);
}
template <typename T>
T scani(T &n) {
  n = 0;
  bool negative = false;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') negative = true;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    n = n * 10 + c - 48;
    c = getchar();
  }
  if (negative) n = ~(n - 1);
  return n;
}
template <typename T>
void write(T n, int type = true) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (!n) {
    putchar('0');
    if (type == 32)
      putchar(' ');
    else if (type)
      putchar('\n');
    return;
  }
  char buff[22];
  int len = 0;
  while (n) buff[len++] = n % 10 + 48, n /= 10;
  for (int i = len - 1; i >= 0; i--) putchar(buff[i]);
  if (type == 32)
    putchar(' ');
  else if (type)
    putchar('\n');
}
int scans(char *a) {
  int i = 0;
  char c = 0;
  while (c < 33) c = getchar();
  while (c > 33) {
    a[i++] = c;
    c = getchar();
  }
  a[i] = 0;
  return i;
}
const int N = 200005;
int Tree[N << 2];
bool typ[N];
int in[N], m, n, qr;
void built(int node, int b, int e) {
  if (b == e) {
    Tree[node] = in[b];
    return;
  }
  int mid = (b + e) >> 1;
  int lf = node << 1;
  int rt = lf | 1;
  typ[lf] = typ[rt] = typ[node] ^ 1;
  built(lf, b, mid);
  built(rt, mid + 1, e);
  if (typ[node])
    Tree[node] = Tree[lf] | Tree[rt];
  else
    Tree[node] = Tree[lf] ^ Tree[rt];
}
void update(int node, int b, int e, int i, int val) {
  if (b == e) {
    Tree[node] = val;
    return;
  }
  int mid = (b + e) >> 1;
  int lf = node << 1;
  int rt = lf | 1;
  if (i <= mid)
    update(lf, b, mid, i, val);
  else
    update(rt, mid + 1, e, i, val);
  if (typ[node])
    Tree[node] = Tree[lf] | Tree[rt];
  else
    Tree[node] = Tree[lf] ^ Tree[rt];
}
int main() {
  scani(m), scani(qr);
  n = 1 << m;
  for (int i = (0); i < (n); ++i) scani(in[i + 1]);
  if (m & 1) typ[1] = true;
  built(1, 1, n);
  while (qr--) {
    int x, val;
    scani(x), scani(val);
    update(1, 1, n, x, val);
    write(Tree[1]);
  }
  return 0;
}
