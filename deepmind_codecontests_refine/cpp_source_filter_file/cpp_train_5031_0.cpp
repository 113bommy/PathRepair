#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
long long a[2000005], h[2000005];
int m, n;
int cont(long long in) {
  return upper_bound(a, a + 2 * n, in) - lower_bound(a, a + 2 * n, in);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  a[n] = h[0] = 1;
  for (int i = 1; i < n; i++) a[n + i] = h[i] = 13331 * h[i - 1];
  int x, y;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    x--;
    y--;
    a[x] += h[y];
    a[y] += h[x];
    a[n + x] += h[y];
    a[n + y] += h[x];
  }
  sort(a, a + 2 * n);
  int ans = 0;
  for (int i = 0; i < 2 * n; i++) ans += cont(a[i]);
  cout << ans / 2 - n << endl;
  return 0;
}
