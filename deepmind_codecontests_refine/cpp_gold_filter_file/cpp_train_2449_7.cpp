#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000;
const int maxn = 62849;
void read(int &x) {
  char ch;
  bool flag = 0;
  for (ch = getchar(); !isdigit(ch) && ((flag |= (ch == '-')) || 1);
       ch = getchar())
    ;
  for (x = 0; isdigit(ch); x = (x << 1) + (x << 3) + ch - 48, ch = getchar())
    ;
  x *= 1 - 2 * flag;
}
int main() {
  int n, n1, m, m1;
  read(n), read(n1);
  read(m), read(m1);
  if (m <= 2 * (n1 + 1) && m >= n1 - 1) {
    puts("YES");
    return 0;
  }
  if ((m1 <= 2 * (n + 1) && m1 >= n - 1)) {
    puts("YES");
    return 0;
  }
  puts("NO");
  return 0;
}
