#include <bits/stdc++.h>
using namespace std;
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
int n, m;
int a[1001];
int main() {
  read(n);
  read(m);
  {
    int c;
    for (int i = (1); i <= (m); i++) {
      read(c);
      a[c]++;
    }
  }
  for (int i = (2); i <= (n); i++) a[1] = min(a[i], a[i]);
  writeln(a[1]);
}
