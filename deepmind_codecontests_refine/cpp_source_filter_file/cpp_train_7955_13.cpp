#include <bits/stdc++.h>
using namespace std;
char Buff[(1 << 18)], *_S = Buff, *_T = Buff;
template <typename T>
T read(void) {
  char c = (_S == _T && (_T = (_S = Buff) + fread(Buff, 1, (1 << 18), stdin),
                         _S == _T)
                ? EOF
                : *_S++);
  T f = 1, num = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f = -f;
    c = (_S == _T &&
                 (_T = (_S = Buff) + fread(Buff, 1, (1 << 18), stdin), _S == _T)
             ? EOF
             : *_S++);
  }
  while ('0' <= c && c <= '9') {
    num = (num << 3) + (num << 1) + (c ^ 48);
    c = (_S == _T &&
                 (_T = (_S = Buff) + fread(Buff, 1, (1 << 18), stdin), _S == _T)
             ? EOF
             : *_S++);
  }
  return f * num;
}
int main() {
  int n = read<int>();
  if (n == 5) {
    puts("1 2 1");
    puts("2 3 2");
    puts("3 4 3");
    puts("4 5 3");
    puts("1 5");
    puts("2 5");
  } else {
    int t = n >> 1;
    for (register int i = 1; i <= t; i++) printf("%d %d %d\n", i, i + t, 1);
    for (register int i = 1; i + t < n; i++)
      printf("%d %d %d\n", i + t, i + t + 1, (i << 1) - 1);
    puts("1 3");
    for (register int i = 1; i < t; i++) printf("%d %d\n", i, i + 1);
  }
  return 0;
}
