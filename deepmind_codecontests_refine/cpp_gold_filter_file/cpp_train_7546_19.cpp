#include <bits/stdc++.h>
using namespace std;
long long i, j, k, l, m, n, a, b, c[222222], d[222222], t, s;
int main() {
  cin >> n;
  l = 1000000007;
  c[0] = 1;
  d[0] = 1;
  for (i = 1; i < 222222; i++) c[i] = (c[i - 1] * i) % l;
  for (i = 1; i < 222222; i++) {
    a = c[i];
    b = l - 2;
    t = 1;
    while (b > 0) {
      if (b % 2 == 1) t = (t * a) % l;
      a = (a * a) % l;
      b = b / 2;
    }
    d[i] = t;
  }
  t = (c[2 * n - 1] * d[n - 1]) % l;
  t = (t * d[n]) % l;
  cout << (t * 2 - n) % l;
}
