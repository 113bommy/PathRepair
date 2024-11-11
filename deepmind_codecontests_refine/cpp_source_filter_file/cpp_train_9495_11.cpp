#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &f) {
  f = 0;
  T fu = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') {
      fu = -1;
    }
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    f = (f << 3) + (f << 1) + (c & 15);
    c = getchar();
  }
  f *= fu;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x < 10)
    putchar(x + 48);
  else
    print(x / 10), putchar(x % 10 + 48);
}
template <typename T>
void print(T x, char t) {
  print(x);
  putchar(t);
}
const long long md = 1000000000000ll;
const long long f0 = 354898000000ll, f1 = 677449000001ll;
const long long L = 333786750000ll;
int main() {
  int n, a, d;
  read(n);
  read(a);
  read(d);
  print(L * a + 1, ' ');
  print(L * d, '\n');
  return 0;
}
