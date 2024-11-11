#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;
template <class T>
void read(T &x) {
  char ch;
  bool ok;
  for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') ok = 1;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  if (ok) x = -x;
}
int main() {
  read(t);
  while (t--) {
    read(a);
    read(b);
    read(c);
    if (a == b && a >= c)
      printf("YES\n%d %d %d\n", a, b, c);
    else if (a == c && a >= b)
      printf("YES\n%d %d %d\n", b, a, c);
    else if (b == c && b >= a)
      printf("YES\n%d %d %d\n", a, c, b);
    else
      puts("NO");
  }
  return 0;
}
