#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <typename T>
inline void read(T &x) {
  char c;
  bool nega = 0;
  while ((!isdigit(c = getchar())) && (c != '-'))
    ;
  if (c == '-') {
    nega = 1;
    c = getchar();
  }
  x = c - 48;
  while (isdigit(c = getchar())) x = x * 10 + c - 48;
  if (nega) x = -x;
}
template <typename T>
inline void writep(T x) {
  if (x > 9) writep(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  writep(x);
}
template <typename T>
inline void writeln(T x) {
  write(x);
  putchar('\n');
}
int n, m, k;
int a[101];
int p[101];
int main() {
  read(n);
  read(m);
  read(k);
  for (int i = (1); i <= (k); i++) {
    read(p[i]);
    a[p[i]] = i;
  }
  int res = 0;
  for (int i = (1); i <= (n); i++) {
    int x;
    for (int j = (1); j <= (m); j++) {
      read(x);
      res += p[x];
      reverse(a + 1, a + p[x] + 1);
      reverse(a + 2, a + p[x] + 1);
      for (int i = (1); i <= (k); i++) p[a[i]] = i;
    }
  }
  writeln(res);
}
