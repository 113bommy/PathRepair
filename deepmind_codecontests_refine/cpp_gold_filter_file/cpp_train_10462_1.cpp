#include <bits/stdc++.h>
using namespace std;
long long cmp(int z, int x, int y, int p) {
  if (p + z < x + y) return 0;
  long long u = min(p, (p + z - x - y) / 2);
  return (u + 1) * (u + 2) / 2;
}
int main() {
  long long a, b, c, l;
  cin >> a >> b >> c >> l;
  long long r = 0;
  for (int i = 0; i <= l; i++) {
    r += (l - i + 1) * (l - i + 2) / 2;
  }
  for (int i = 0; i <= l; i++) {
    r -= cmp(a, b, c, i);
    r -= cmp(b, c, a, i);
    r -= cmp(c, a, b, i);
  }
  cout << r;
  return 0;
}
