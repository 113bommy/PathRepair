#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T& a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T& a, T b) {
  return a < b ? a = b, 1 : 0;
}
int f[200010] = {1, 1}, t[524290], t2[524290], tl[524290], ta[524299];
int n, m, T = 1;
int get(int a, int b, int l, int r) {
  if (l == 1 && r == tl[a]) return t2[a];
  if (l != 0 || r != tl[a]) {
    if (r <= tl[a << 1]) return get(a << 1, b, l, r);
    if (l >= tl[a << 1])
      return get(a << 1 ^ 1, b, l - tl[a << 1], r - tl[a << 1]);
    else
      return (get(a << 1, b, l, tl[a << 1]) +
              get(a << 1 ^ 1, b + tl[a << 1] - l, 0, r - tl[a << 1])) %
             1000000000;
  }
  return ((long long)t[a] * f[b] + (long long)t2[a] * (b ? f[b - 1] : 0)) %
         1000000000;
}
void change(int a, int l, int r, int d) {}
int main() {
  for (int i = 1; ++i != 200010;) f[i] = (f[i - 1] + f[i - 2]) % 1000000000;
  {
    {
      char __next__char__;
      while (!isdigit(__next__char__ = getchar()))
        ;
      n = __next__char__ - 48;
      while (isdigit(__next__char__ = getchar()))
        n = n * 10 + __next__char__ - 48;
    };
    {
      char __next__char__;
      while (!isdigit(__next__char__ = getchar()))
        ;
      m = __next__char__ - 48;
      while (isdigit(__next__char__ = getchar()))
        m = m * 10 + __next__char__ - 48;
    };
  };
  while (T < n) T <<= 1;
  for (int i = -1; ++i != n; t2[i + T] = 0) {
    char __next__char__;
    while (!isdigit(__next__char__ = getchar()))
      ;
    t[i + T] = __next__char__ - 48;
    while (isdigit(__next__char__ = getchar()))
      t[i + T] = t[i + T] * 10 + __next__char__ - 48;
  };
  for (int i = T; i--;) tl[i + T] = 1;
  for (int i = T; --i;) {
    tl[i] = tl[i << 1] << 1;
    t[i] = (get(i << 1, 0, 0, tl[i << 1]) +
            get(i << 1 ^ 1, tl[i << 1], 0, tl[i << 1])) %
           1000000000;
    t2[i] = (get(i << 1, 0, 1, tl[i << 1]) +
             get(i << 1 ^ 1, tl[i << 1] - 1, 0, tl[i << 1])) %
            1000000000;
  }
  while (m--) {
    int x;
    {
      char __next__char__;
      while (!isdigit(__next__char__ = getchar()))
        ;
      x = __next__char__ - 48;
      while (isdigit(__next__char__ = getchar()))
        x = x * 10 + __next__char__ - 48;
    };
    if (x == 2) {
      int l, r;
      {
        {
          char __next__char__;
          while (!isdigit(__next__char__ = getchar()))
            ;
          l = __next__char__ - 48;
          while (isdigit(__next__char__ = getchar()))
            l = l * 10 + __next__char__ - 48;
        };
        {
          char __next__char__;
          while (!isdigit(__next__char__ = getchar()))
            ;
          r = __next__char__ - 48;
          while (isdigit(__next__char__ = getchar()))
            r = r * 10 + __next__char__ - 48;
        };
      };
      l--;
      printf("%d\n", get(1, 0, l, r));
    } else if (x == 1) {
      int i, v;
      {
        {
          char __next__char__;
          while (!isdigit(__next__char__ = getchar()))
            ;
          i = __next__char__ - 48;
          while (isdigit(__next__char__ = getchar()))
            i = i * 10 + __next__char__ - 48;
        };
        {
          char __next__char__;
          while (!isdigit(__next__char__ = getchar()))
            ;
          v = __next__char__ - 48;
          while (isdigit(__next__char__ = getchar()))
            v = v * 10 + __next__char__ - 48;
        };
      };
      i += T - 1;
      t[i] = v;
      while (i >>= 1) {
        t[i] = (get(i << 1, 0, 0, tl[i << 1]) +
                get(i << 1 ^ 1, tl[i << 1], 0, tl[i << 1])) %
               1000000000;
        t2[i] = (get(i << 1, 0, 1, tl[i << 1]) +
                 get(i << 1 ^ 1, tl[i << 1] - 1, 0, tl[i << 1])) %
                1000000000;
      }
    } else {
      int l, r, d;
      {
        {
          char __next__char__;
          while (!isdigit(__next__char__ = getchar()))
            ;
          l = __next__char__ - 48;
          while (isdigit(__next__char__ = getchar()))
            l = l * 10 + __next__char__ - 48;
        };
        {
          char __next__char__;
          while (!isdigit(__next__char__ = getchar()))
            ;
          r = __next__char__ - 48;
          while (isdigit(__next__char__ = getchar()))
            r = r * 10 + __next__char__ - 48;
        };
        {
          char __next__char__;
          while (!isdigit(__next__char__ = getchar()))
            ;
          d = __next__char__ - 48;
          while (isdigit(__next__char__ = getchar()))
            d = d * 10 + __next__char__ - 48;
        };
      };
    }
  }
  return 0;
}
