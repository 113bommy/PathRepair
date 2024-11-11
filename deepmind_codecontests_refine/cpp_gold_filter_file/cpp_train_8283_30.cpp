#include <bits/stdc++.h>
using namespace std;
int a[5];
inline int read() {
  int res = 0, f_f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f_f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    res = (res << 3) + (res << 1) + ch - '0';
    ch = getchar();
  }
  return res * f_f;
}
int main() {
  for (int i = 1; i <= 4; i++) a[i] = read();
  printf("%d\n",
         ((a[1] ^ a[2]) & (a[3] | a[4])) ^ ((a[2] & a[3]) | (a[1] ^ a[4])));
  return 0;
}
