#include <bits/stdc++.h>
using namespace std;
long long k, x, n, m;
inline void rd(long long &x) {
  x = 0;
  char ch;
  while ((ch = getchar()) < 48)
    ;
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
}
inline long long Fun(long long x) {
  if (x % 4 == 1) return 1;
  if (x % 4 == 2) return x + 1;
  if (x % 4 == 3) return 0;
  return x;
}
int main() {
  rd(n);
  while (n--) {
    rd(x);
    rd(m);
    k = k ^ Fun(x - 1) ^ Fun(x + m - 1);
  }
  if (k & 1)
    printf("tolik\n");
  else
    printf("bolik\n");
  return 0;
}
