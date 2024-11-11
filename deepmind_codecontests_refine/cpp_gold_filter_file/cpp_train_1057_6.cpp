#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  bool w = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    w |= s == '-';
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    s = getchar();
  }
  return w ? -x : x;
}
long long x, y, z, a, b;
long long ans, num;
int main() {
  x = read();
  y = read();
  z = read();
  ans += x / z + y / z;
  a = x % z;
  b = y % z;
  if (a + b >= z && a > b) num = z - a, ans++;
  if (a + b >= z && a <= b) num = z - b, ans++;
  printf("%I64d %I64d\n", ans, num);
  return 0;
}
