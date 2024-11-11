#include <bits/stdc++.h>
using namespace std;
inline int Read() {
  int e = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (f == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    e = e * 10 + (ch - '0');
    ch = getchar();
  }
  return e * f;
}
int main() {
  int l = Read(), r = Read(), L = Read(), R = Read(), k = Read();
  long long tmp;
  bool flag = false;
  for (int i = l; i <= r; i++) {
    tmp = (long long)i * k;
    if (L <= tmp && tmp < R) {
      flag = true;
      break;
    }
  }
  puts(flag ? "YES" : "NO");
  return 0;
}
