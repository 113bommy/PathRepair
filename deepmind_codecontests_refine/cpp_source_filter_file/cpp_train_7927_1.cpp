#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(long long a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(long long a) {
  write(a);
  puts("");
}
inline void wri(long long a) {
  write(a);
  putchar(' ');
}
inline unsigned long long rnd() {
  return ((unsigned long long)rand() << 30 ^ rand()) << 4 | rand() % 4;
}
const int N = 1 << 12 | 2;
int p[N], q[N], b[N], a[N], sum, to[N];
void fix(int x, int y) {
  if ((p[x] ^ q[x]) == a[x] && (p[y] ^ q[y]) == a[y]) return;
  int t = to[a[x] ^ q[x]];
  swap(p[t], p[x]);
  swap(to[p[t]], to[p[x]]);
  swap(q[y], q[t]);
  fix(t, y);
}
void opt(int x, int y, int de) {
  a[x] ^= de;
  a[y] ^= de;
  fix(x, y);
}
int main() {
  int k = read(), n = 1 << k;
  for (int i = (int)(0); i <= (int)(n - 1); i++) {
    b[i] = read();
    sum ^= a[i];
    p[i] = q[i] = to[i] = i;
  }
  if (sum) {
    puts("Fou");
    return 0;
  }
  puts("Shi");
  for (int i = (int)(0); i <= (int)(n - 2); i++) {
    opt(i, i + 1, b[i]);
    b[i + 1] ^= b[i];
  }
  for (int i = (int)(0); i <= (int)(n - 1); i++) wri(p[i]);
  puts("");
  for (int i = (int)(0); i <= (int)(n - 1); i++) wri(q[i]);
}
