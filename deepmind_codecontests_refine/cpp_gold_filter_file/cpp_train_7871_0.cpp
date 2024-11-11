#include <bits/stdc++.h>
using namespace std;
int a, _xor, _or, cnt, n;
char c;
int main() {
  scanf("%d", &n);
  int x = 0, y = 1023;
  for (int i = (1); i <= (n); ++i) {
    scanf(" %c%d", &c, &a);
    if (c == '|') x |= a, y |= a;
    if (c == '&') x &= a, y &= a;
    if (c == '^') x ^= a, y ^= a;
  }
  for (int i = (0); i <= (9); ++i) {
    int a = (x >> i) & 1, b = (y >> i) & 1;
    if (a && b) _or |= 1 << i;
    if (a == 1 && b == 0) _xor |= 1 << i;
    if (!a && !b) _or |= 1 << i, _xor |= 1 << i;
  }
  if (_or) ++cnt;
  if (_xor) ++cnt;
  printf("%d\n", cnt);
  if (_or) printf("| %d\n", _or);
  if (_xor) printf("^ %d\n", _xor);
  return 0;
}
