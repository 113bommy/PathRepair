#include <bits/stdc++.h>
using namespace std;
long long i, j, k, s, l, m, n, t, a, c, b, d, e[11][11];
string p, q, r, f;
int main() {
  cin >> n >> a >> m >> b;
  a = abs(b - a);
  s = 0;
  for (i = 1; i <= m; i++) {
    b = abs(a - i);
    c = a + i;
    t = 0;
    if (n >= c) {
      t = 2 * (b - c);
    }
    if (n >= b && n < c) t = 1 + (n - b) * 2;
    if (b == 0) t--;
    if (t == 0) k++;
    s += t;
  }
  swap(n, m);
  for (i = 1; i <= m; i++) {
    b = abs(a - i);
    c = a + i;
    t = 0;
    if (n >= c) {
      t = 2 * (b - c);
    }
    if (n >= b && n < c) t = 1 + (n - b) * 2;
    if (b == 0) t--;
    if (t == 0) k++;
    s += t;
  }
  if (s == 0)
    cout << s / 2 + k;
  else
    cout << s / 2 + 2 + k;
  return 0;
}
