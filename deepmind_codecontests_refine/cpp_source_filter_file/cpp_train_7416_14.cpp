#include <bits/stdc++.h>
template <class T>
inline void read(T &res) {
  char ch;
  bool flag = false;
  res = 0;
  while (ch = getchar(), !isdigit(ch) && ch != '-')
    ;
  ch == '-' ? flag = true : res = ch ^ 48;
  while (ch = getchar(), isdigit(ch)) res = res * 10 + ch - 48;
  flag ? res = -res : 0;
}
template <class T>
inline void put(T x) {
  if (x > 9) put(x / 10);
  putchar(x % 10 + 48);
}
template <class T>
inline T Max(T x, T y) {
  return x > y ? x : y;
}
template <class T>
inline T Min(T x, T y) {
  return x < y ? x : y;
}
template <class T>
inline void CkMax(T &x, T y) {
  x < y ? x = y : 0;
}
template <class T>
inline void CkMin(T &x, T y) {
  x > y ? x = y : 0;
}
const int L = 1e9;
const int N = 2e5;
long long f[N];
int n, ed, TAT;
int main() {
  f[1] = 2;
  for (int i = 2; f[i - 1] <= L; ++i) {
    ed = i - 1;
    f[i] = f[i - 1] + (i - 1) + (i << 1);
  }
  read(TAT);
  while (TAT--) {
    read(n);
    int cnt = 0;
    for (int i = ed; i >= 1; --i)
      if (f[i] <= n) n -= f[i], ++cnt;
    printf("%d\n", cnt);
  }
  return 0;
}
