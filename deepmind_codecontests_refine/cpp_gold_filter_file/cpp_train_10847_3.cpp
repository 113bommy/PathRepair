#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
void read(int &a) {
  a = 0;
  int d = 1;
  char ch;
  while (ch = getchar(), ch > '9' || ch < '0')
    if (ch == '-') d = -1;
  a = ch ^ 48;
  while (ch = getchar(), ch >= '0' && ch <= '9')
    a = (a << 3) + (a << 1) + (ch ^ 48);
  a *= d;
}
long long g(int a, int b) {
  long long res = 0;
  long long num = 0;
  for (register int i = 1; i <= b; i <<= 1) {
    if (b & i) {
      b ^= i;
      if (!(b & a)) res += 1ll << num;
    }
    if (!(a & i)) num++;
  }
  return res;
}
long long cal(int a, int b) {
  if (a == b) return 0;
  if (a == 0) return 2 * b - 1 + cal(1, b);
  long long res = 0;
  if (a & 1) {
    res += (g(a, b) - g(a, a)) << 1;
    a++;
  }
  if (b & 1) {
    res += (g(b - 1, b) - g(b - 1, a)) << 1;
    b--;
  }
  return res + 3 * cal(a / 2, b / 2);
}
int main() {
  int T;
  read(T);
  while (T--) {
    int a, b;
    read(a), read(b);
    printf("%I64d\n", cal(a, b + 1));
  }
  return 0;
}
