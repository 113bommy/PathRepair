#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) {
  return a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) {
  return a < b ? a : b;
}
const char lf = '\n';
namespace ae86 {
const int bufl = 1 << 15;
char buf[bufl], *s = buf, *t = buf;
inline int fetch() {
  if (s == t) {
    t = (s = buf) + fread(buf, 1, bufl, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
inline int ty() {
  int a = 0;
  int b = 1, c = fetch();
  while (!isdigit(c)) b ^= c == '-', c = fetch();
  while (isdigit(c)) a = a * 10 + c - 48, c = fetch();
  return b ? a : -a;
}
}  // namespace ae86
using ae86::ty;
void make3(int a, int b, int c) {
  cout << 3 << ' ' << a << ' ' << b << ' ' << c << lf;
}
void make4(int a, int b, int c, int d) {
  cout << 4 << ' ' << a << ' ' << b << ' ' << c << ' ' << d << lf;
}
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  int n = ty();
  if (n & 1) {
    cout << (n - 1) + (n - 1) * ((n - 3) / 2) / 2 << lf;
    for (int i = 2; i <= n; i += 2) {
      make3(1, i, i + 1), make3(1, i, i + 1);
      for (int j = 2; j < i; j += 2)
        make4(i, j, i + 1, j + 1), make4(i, j, i + 1, j + 1);
    }
  } else {
    cout << (n - 2) * (n - 2) / 4 + (n - 2) << lf;
    make4(1, 2, 3, 4), make4(1, 3, 4, 2), make4(1, 4, 2, 3);
    for (int i = 5; i <= n; i += 2) {
      make3(1, i, i + 1), make3(2, i, i + 1), make4(1, i, 2, i + 1);
      for (int j = 3; j < i; j += 2)
        make4(i, j, i + 1, j + 1), make4(i, j, i + 1, j + 1);
    }
  }
  return 0;
}
