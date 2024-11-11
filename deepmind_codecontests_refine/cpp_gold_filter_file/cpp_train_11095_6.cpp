#include <bits/stdc++.h>
using namespace std;
inline void ri(int &x) {
  x = 0;
  static char c;
  bool t = 0;
  while (c = getchar(), c < '0' || c > '9')
    if (c == '-')
      t = 1;
    else
      t = 0;
  do x = x * 10 + c - '0';
  while (c = getchar(), c >= '0' && c <= '9');
  if (t) x = -x;
}
int main() {
  int i, T, l, r, u, d;
  ri(T);
  cout << "YES\n";
  while (T--) {
    ri(l);
    ri(u);
    ri(r);
    ri(d);
    l = abs(min(l, r));
    u = abs(min(u, d));
    if ((l & 1) && (u & 1)) puts("1");
    if ((l & 1) && (~u & 1)) puts("2");
    if ((~l & 1) && (u & 1)) puts("3");
    if ((~l & 1) && (~u & 1)) puts("4");
  }
  return 0;
}
