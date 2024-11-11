#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
char O[1 << 14], *S = O, *T = O;
inline long long read() {
  long long x = 0, f = 1;
  char ch =
      (S == T && (T = (S = O) + fread(O, 1, 1 << 14, stdin), S == T) ? -1
                                                                     : *S++);
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = (S == T && (T = (S = O) + fread(O, 1, 1 << 14, stdin), S == T) ? -1
                                                                        : *S++);
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = (S == T && (T = (S = O) + fread(O, 1, 1 << 14, stdin), S == T) ? -1
                                                                        : *S++);
  }
  return x * f;
}
int main() {
  long long n = read();
  int q = read();
  while (q--) {
    long long x = read();
    while (!(x & 1)) x += n - (x >> 1);
    printf("%d\n", (x + 1) >> 1);
  }
  return 0;
}
