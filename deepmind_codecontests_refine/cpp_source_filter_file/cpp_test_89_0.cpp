#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long ans = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') ans = ans * 10 + c - '0', c = getchar();
  return ans * f;
}
const int maxn = 1e6 + 5;
long long T, n, a[maxn], die[maxn], now;
bool bj;
int main() {
  T = read();
  while (T--) {
    n = read();
    for (register int i = 1; i <= n; i++) a[i] = read();
    bj = 1;
    for (register int i = 1; i <= n; i++) {
      die[i] = -1;
      for (register int j = n; j >= 1; j--) {
        if (a[i] % (j + 1) != 0) {
          die[i] = i - j;
          break;
        }
      }
      if (die[i] == -1) bj = 0;
    }
    for (register int i = 1; i <= n; i++)
      if (die[i] > i - 1) {
        bj = 0;
      }
    if (!bj)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
