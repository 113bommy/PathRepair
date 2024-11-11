#include <bits/stdc++.h>
using namespace std;
int read() {
  static int res;
  static char op;
  do op = getchar();
  while (op > '9' || op < '0');
  for (res = 0; op >= '0' && op <= '9'; op = getchar())
    res = res * 10 + (op ^ 48);
  return res;
}
signed main(int argc, char **argv) {
  int n = read(), m = read(), k = read(), ans = 0;
  for (int i = 1, x, y; i <= k; ++i)
    x = read(), y = read(),
    ans |= (x >= n - 4 || x <= 5 || y >= m - 4 || y <= 5);
  puts(ans ? "YES" : "NO");
  return 0;
}
