#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chkmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void chkmin(T &a, T b) {
  if (a > b) a = b;
}
inline int read() {
  int sum = 0, p = 1;
  char ch = getchar();
  while (!(('0' <= ch && ch <= '9') || ch == '-')) ch = getchar();
  if (ch == '-') p = -1, ch = getchar();
  while ('0' <= ch && ch <= '9') sum = sum * 10 + ch - 48, ch = getchar();
  return sum * p;
}
const int maxn = 4e3 + 100;
int n, a[maxn], all;
int b[maxn], p[maxn], q[maxn], id[maxn];
inline void init() {
  n = read();
  all = 1 << n;
  int sum = 0;
  for (int i = (0), _end_ = ((1 << n) - 1); i <= _end_; i++)
    a[i] = read(), sum ^= a[i];
  if (sum) puts("Fou"), exit(0);
}
inline void doing() {
  for (int i = (0), _end_ = (all - 1); i <= _end_; i++)
    p[i] = q[i] = id[i] = i, b[i] = 0;
  for (int th = (1), _end_ = (all - 1); th <= _end_; th++) {
    int x = b[th] ^ a[th], i = 0, j = th, t = id[p[i] ^ x];
    b[th] ^= x;
    b[0] ^= x;
    while (t != i) {
      id[p[i]] = t;
      id[p[t]] = i;
      swap(p[i], p[t]);
      if (t == j) break;
      swap(q[j], q[t]);
      x = b[j] ^ p[j] ^ q[j];
      i = t;
      t = id[p[i] ^ x];
    }
  }
  puts("Shi");
  for (int i = (0), _end_ = (all - 1); i <= _end_; i++) printf("%d ", p[i]);
  puts("");
  for (int i = (0), _end_ = (all - 1); i <= _end_; i++) printf("%d ", q[i]);
  puts("");
}
int main() {
  init();
  doing();
  return 0;
}
