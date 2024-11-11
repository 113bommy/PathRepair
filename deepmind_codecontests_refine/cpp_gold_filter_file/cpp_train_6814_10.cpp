#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ '0');
    ch = getchar();
  }
  return x * f;
}
int main() {
  long long a = read();
  long long b = ((long long)1e18 % a * 9 % a * 9 % a + 1) % a;
  printf("%lld %lld\n", a - b + 1, a - b + (long long)1e18);
}
