#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int u = 0, f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    u = (u << 1) + (u << 3) + ch - 48;
    ch = getchar();
  }
  return u * f;
}
int main() {
  int x = read(), y = read(), z = read(), t1 = read(), t2 = read(), t3 = read();
  if ((abs(z - x) + abs(y - x)) * t2 + 2 * t3 <= abs(x - y) * t1)
    puts("YES");
  else
    puts("NO");
  return 0;
}
