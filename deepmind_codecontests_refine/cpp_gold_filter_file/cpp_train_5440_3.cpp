#include <bits/stdc++.h>
using namespace std;
inline int read_int() {
  int t = 0;
  bool sign = false;
  char c = getchar();
  while (!isdigit(c)) {
    sign |= c == '-';
    c = getchar();
  }
  while (isdigit(c)) {
    t = (t << 1) + (t << 3) + (c & 15);
    c = getchar();
  }
  return sign ? -t : t;
}
inline long long read_LL() {
  long long t = 0;
  bool sign = false;
  char c = getchar();
  while (!isdigit(c)) {
    sign |= c == '-';
    c = getchar();
  }
  while (isdigit(c)) {
    t = (t << 1) + (t << 3) + (c & 15);
    c = getchar();
  }
  return sign ? -t : t;
}
inline void write(long long x) {
  register char c[21], len = 0;
  if (!x) return putchar('0'), void();
  if (x < 0) x = -x, putchar('-');
  while (x) c[++len] = x % 10, x /= 10;
  while (len) putchar(c[len--] + 48);
}
inline void space(long long x) { write(x), putchar(' '); }
inline void enter(long long x) { write(x), putchar('\n'); }
const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN << 1];
int main() {
  int n = read_int(), p = read_int(), A = 0;
  for (int i = (0); i < (n); ++i) {
    a[i] = read_int();
    A = max(A, a[i]);
  }
  for (int i = (0); i < (n); ++i) b[max(0, a[i] - (A - n))]++;
  for (int i = (1); i < (n << 1); ++i) b[i] += b[i - 1];
  int st = 1, en = n;
  for (int i = (1); i <= (n); ++i) {
    while (b[st + (i - 1)] < i) st++;
  }
  for (int i = (0); i < (n); ++i) {
    while (b[en + i] - i >= p) en--;
  }
  st += (A - n), en += (A - n);
  if (st <= en) {
    enter(en - st + 1);
    for (int i = (st); i <= (en); ++i) {
      if (i != st) putchar(' ');
      write(i);
    }
  } else
    enter(0);
  return 0;
}
