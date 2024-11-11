#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chkmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline void chkmax(T &a, T b) {
  if (a < b) a = b;
}
inline int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') ch = getchar(), f = -1;
  while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
  return ~f ? s : -s;
}
const int maxn = 2000 + 20;
bitset<maxn> f[1 << 16];
int n;
int a[maxn], k;
inline void init() {
  n = read();
  k = read();
  for (int i = (1), _end_ = (n); i <= _end_; i++) a[i] = read();
  f[0].set(0);
  for (int i = (1), _end_ = (n); i <= _end_; i++) f[1 << i - 1].set(a[i]);
}
inline void doing() {
  for (int i = (1), _end_ = ((1 << n) - 1); i <= _end_; i++) {
    for (int j = 2000 / k * k; j; j -= k)
      if (f[i][j]) f[i][j / k] = 1;
    for (int x = (1), _end_ = (n); x <= _end_; x++)
      if (~i >> x - 1 & 1) f[i | (1 << x - 1)] |= f[i] << a[x];
  }
  int M = 1 << n;
  M -= 1;
  if (!f[M][1])
    puts("NO");
  else {
    puts("YES");
    set<pair<int, int> > ANS;
    int tim = n, val = 1, add = 0;
    while (tim--) {
      int VAL = val, flg = 0, tx = 0;
      while (VAL <= 2000) {
        for (int x = (1), _end_ = (n); x <= _end_; x++)
          if (M >> x - 1 & 1)
            if (a[x] <= VAL && f[M ^ (1 << x - 1)][VAL - a[x]]) {
              flg = 1;
              tx = x;
              break;
            }
        if (flg) {
          break;
        } else
          VAL *= k, add++;
      }
      val = VAL - a[tx];
      M ^= 1 << tx - 1;
      ANS.insert(make_pair(add, a[tx]));
    }
    while (((int)ANS.size()) >= 2) {
      set<pair<int, int> >::iterator a = ANS.end(), b;
      a--;
      b = a;
      b--;
      int cadd = a->first, c = a->second + b->second;
      while (c % k == 0) c /= k, cadd--;
      printf("%d %d\n", a->second, b->second);
      ANS.erase(a);
      ANS.erase(b);
      ANS.insert(make_pair(cadd, c));
    }
  }
}
int main() {
  init();
  doing();
  return 0;
}
