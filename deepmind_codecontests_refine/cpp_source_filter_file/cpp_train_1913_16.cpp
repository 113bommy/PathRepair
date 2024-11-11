#include <bits/stdc++.h>
using namespace std;
long long n, x, y, c;
int main() {
  scanf("%I64d %I64d %I64d %I64d", &n, &x, &y, &c);
  if (c == 1) {
    printf("0");
    return 0;
  }
  long long top, bot;
  top = 2 * n + 3;
  bot = 1;
  while (top > bot) {
    long long tr = (top + bot) / 2;
    long long s1, s2, s3, s4, s5, s6, s7, s8, s9;
    tr++;
    s1 = 2 * tr * tr - 2 * tr + 1;
    tr--;
    s2 = max(tr - x + 1, 0LL);
    s2 = s2 * s2;
    s3 = max(tr - n + x, 0LL);
    s3 = s3 * s3;
    s4 = max(tr - y + 1, 0LL);
    s4 = s4 * s4;
    s5 = max(tr - n + y, 0LL);
    s5 = s5 * s5;
    s6 = max(tr - (x + y) + 1, 0LL);
    s6 = s6 * (s6 + 1) / 2;
    s7 = max(tr - (n - x + y), 0LL);
    s7 = s7 * (s7 + 1) / 2;
    s8 = max(tr - (n - x + n - y), 0LL);
    s8 = s8 * (s8 + 1) / 2;
    s9 = max(tr - (n - y + x), 0LL);
    s9 = s9 * (s9 + 1) / 2;
    long long surf;
    surf = s1 - s2 - s3 - s4 - s5 + s6 + s7 + s8 + s9;
    if (surf >= c)
      top = tr;
    else
      bot = tr + 1;
  }
  printf("%I64d\n", top);
}
