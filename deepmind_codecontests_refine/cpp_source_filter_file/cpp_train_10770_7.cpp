#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n, l, x, y, a[N];
bool X, Y;
int main() {
  scanf("%d%d%d%d", &n, &l, &x, &y);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) {
    X |= binary_search(a, a + n, a[i] + x);
    Y |= binary_search(a, a + n, a[i] + y);
  }
  if (X && Y) return puts("0");
  if (X ^ Y) return !printf("1\n%d\n", X ? y : x);
  for (int _y, i = 0; i < n; ++i) {
    if (a[i] >= y) {
      _y = y - a[i];
      if (binary_search(a, a + n, _y - x) || binary_search(a, a + n, _y + x))
        return !printf("1\n%d\n", _y);
    }
    if (a[i] + y <= l) {
      _y = y + a[i];
      if (binary_search(a, a + n, _y - x) || binary_search(a, a + n, _y + x))
        return !printf("1\n%d\n", _y);
    }
  }
  printf("2\n%d %d\n", x, y);
  return 0;
}
