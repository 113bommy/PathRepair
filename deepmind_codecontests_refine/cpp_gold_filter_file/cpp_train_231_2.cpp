#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
template <class T>
inline void in(T &);
template <class T>
inline void out(const T &);
using std::abs;
using std::max;
using std::min;
using std::sort;
using namespace std;
int t, n, s1, s2;
int main() {
  in(t);
  while (t--) {
    in(n);
    s1 = s2 = 0;
    while (n % 2 == 0) n /= 2, s1++;
    while (n % 3 == 0) n /= 3, s2++;
    if (n == 1 && s1 <= s2)
      out(2 * s2 - s1);
    else
      out(-1);
    putchar('\n');
  }
  return 0;
}
template <class T>
void in(T &Re) {
  T k = 0;
  char ch = getchar();
  int flag = 1;
  while (!(ch >= '0' && ch <= '9')) {
    if (ch == '-') {
      flag = -1;
    }
    ch = getchar();
  }
  while ((ch >= '0' && ch <= '9')) {
    k = (k << 1) + (k << 3) + ch - '0';
    ch = getchar();
  }
  Re = flag * k;
}
template <class T>
void out(const T &Wr) {
  if (Wr < 0) {
    putchar('-');
    out(-Wr);
  } else {
    if (Wr < 10) {
      putchar(Wr + '0');
    } else {
      out(Wr / 10);
      putchar((Wr % 10) + '0');
    }
  }
}
