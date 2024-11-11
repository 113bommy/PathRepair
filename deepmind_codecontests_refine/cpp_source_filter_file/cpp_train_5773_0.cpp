#include <bits/stdc++.h>
using namespace std;
inline void read(register int *n) {
  register char c;
  *n = 0;
  do {
    c = getchar();
  } while (c < '0' || c > '9');
  do {
    *n = c - '0' + *n * 10;
    c = getchar();
  } while (c >= '0' && c <= '9');
}
int r, c, rev;
void print(int rr, int cc) {
  if (rev)
    cout << cc << " " << rr << endl;
  else
    cout << rr << " " << cc << endl;
}
void voodoo(int r1, int c1, int r2, int c2) {
  int f = r1 % 2;
  while (r1 <= r2) {
    if (f == r1 % 2)
      for (register int i = (c1); i < (int)(c2 + 1); ++i) print(r1, i);
    else
      for (int i = c2; i >= c1; i--) print(r1, i);
    r1++;
  }
}
int main(int argv, char **argc) {
  cin >> r >> c;
  if (r == 1 && c == 2) {
    cout << "0\n1 1\n1 2\n1 1\n";
    return 0;
  } else if (r == 2 && c == 1) {
    cout << "0\n1 1\n2 1\n1 1\n";
    return 0;
  }
  if (r % 2 && c % 2 == 0) rev = true, swap(r, c);
  if ((r % 2 && c % 2) || (r == 1 && c > 2)) {
    cout << 1 << endl;
    print(r, c);
    print(1, 1);
    voodoo(1, 1, r, c);
    print(1, 1);
  } else {
    cout << 0 << endl;
    print(1, 1);
    voodoo(1, 2, r, c);
    for (int i = r; i >= 1; i--) print(i, 1);
  }
  return 0;
}
