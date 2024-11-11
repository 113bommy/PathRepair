#include <bits/stdc++.h>
inline void read(int& x) {
  x = 0;
  int ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    ;
  for (; isdigit(ch); ch = getchar()) {
    x = x * 10 + ch - '0';
  }
}
int main() {
  int T = 1;
  for (int n, S; T; T--) {
    S = 0;
    read(n);
    if (S) {
      printf("%d\n", (n - 1) / 2 + 1);
    } else {
      if (!(n & 1)) {
        for (int i = 30; i >= 0; i--) {
          if (n & (1 << (i - 1))) {
            n -= (n & (1 << (i - 1)));
            break;
          }
        }
      }
      printf("%d\n", n / 2);
    }
  }
  return 0;
}
