#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
inline long long read() {
  register long long x = 0, f = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  int n = read(), p = read();
  long long sum = 0;
  while (n--) {
    long long tmp = n + 1;
    int k = n + 1;
    while (k) {
      (tmp *= 10) += k % 10;
      k /= 10;
    }
    (sum += tmp) %= p;
  }
  printf("%lld", sum);
  return 0;
}
