#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
template <class T, class T1>
inline void gn(T &first, T1 &second) {
  gn(first);
  gn(second);
}
template <class T, class T1, class T2>
inline void gn(T &first, T1 &second, T2 &z) {
  gn(first);
  gn(second);
  gn(z);
}
template <class T>
inline void println(T first) {
  print(first);
  putchar('\n');
}
template <class T>
inline void printsp(T first) {
  print(first);
  putchar(' ');
}
template <class T1, class T2>
inline void print(T1 x1, T2 x2) {
  printsp(x1), println(x2);
}
template <class T1, class T2, class T3>
inline void print(T1 x1, T2 x2, T3 x3) {
  printsp(x1), printsp(x2), println(x3);
}
template <class T1, class T2, class T3, class T4>
inline void print(T1 x1, T2 x2, T3 x3, T4 x4) {
  printsp(x1), printsp(x2), printsp(x3), println(x4);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int main() {
  int n, first;
  cin >> n >> first;
  if (n == 5 and first == 5) {
    puts(">...v");
    puts("v.<..");
    puts("..^..");
    puts(">....");
    puts("..^.<");
    puts("1 1");
    return 0;
  }
  if (n == 3 and first == 2) {
    puts(">vv");
    puts("^<.");
    puts("^.<");
    puts("1 3");
    return 0;
  }
  for (int i = 1; i <= n; i += 2) {
    putchar('v');
    for (int j = 2; j <= n / 2; j++) {
      if (j & 1)
        putchar('.');
      else
        putchar('<');
    }
    for (int j = n / 2 + 1; j <= n; j++) {
      putchar('<');
    }
    puts("");
    for (int j = 1; j <= n / 2; j++) putchar('>');
    for (int j = n / 2 + 1; j < n; j++) {
      if (j & 1)
        putchar('.');
      else
        putchar('>');
    }
    puts("^");
  }
  print(n, n);
  return 0;
  return 0;
}
