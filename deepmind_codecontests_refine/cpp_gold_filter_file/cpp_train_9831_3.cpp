#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int p, ans, n, m, a[5050], c[5050];
set<int> z;
int f(int x) {
  int s = 0;
  for (int d = 2; d * d <= x; ++d)
    if (0 == x % d) {
      int t = z.count(d) ? -1 : 1;
      while (0 == x % d) s += t, x /= d;
    }
  if (x > 1) s += z.count(x) ? -1 : 1;
  return s;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  c[0] = a[0];
  for (int i = 1; i < n; ++i) c[i] = gcd(a[i], c[i - 1]);
  for (int i = 0; i < m; ++i) scanf("%d", &p), z.insert(p);
  for (int i = 0; i < n; ++i) ans += f(a[i]);
  int g = 1;
  for (int i = n; i >= 0; i--) {
    int x = f(c[i] / g);
    if (x < 0) g = c[i], ans -= x * (i + 1);
  }
  cout << ans << endl;
}
