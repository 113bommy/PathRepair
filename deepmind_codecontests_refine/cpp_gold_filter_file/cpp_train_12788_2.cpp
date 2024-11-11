#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

bitset <N> one, two;
int a, b, c, d, e, f;

int main() {
  cin >> a >> b >> c >> d >> e >> f;
  one[0] = two[0] = 1;

  for (int i = a; i <= f; i += a) {
    one |= one << i;
  }
  for (int i = b; i <= f; i += b) {
    one |= one << i;
  }
  for (int i = c; i <= f; i += c) {
    two |= two << i;
  }
  for (int i = d; i <= f; i += d) {
    two |= two << i;
  }

  int up = 0, down = a;
  for (int i = 1; i <= f; ++i) {
    if (!one[i]) continue;
    for (int j = 0; 100 * i + j <= f and j <= e * i; ++j) {
      if (!two[j]) continue;
      if (j * down > i * up) {
        up = j, down = i;
      }
    }
  }

  printf("%d %d\n", 100 * down + up, up);
  return 0;
}
