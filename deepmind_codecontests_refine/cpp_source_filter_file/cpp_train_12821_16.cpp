#include <bits/stdc++.h>
const int N = 1005;
int r[N], c[N], ir[N], ic[N];
int x[N], y[N], z[N], w[N];
int n, m;
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n;
  for (int i = 1; i <= n; ++i) std::cin >> r[i], ir[r[i]] = i;
  for (int i = 1; i <= n; ++i) std::cin >> c[i], ic[c[i]] = i;
  for (int i = 1; i <= n; ++i) {
    int p = ir[i], q = ic[i];
    if (p == i && q == i) continue;
    x[m] = i, y[m] = q, z[m] = p, w[m++] = i;
    std::swap(r[i], r[p]), std::swap(ir[r[i]], ir[r[p]]);
    std::swap(c[i], c[q]), std::swap(ic[c[i]], ic[c[p]]);
  }
  std::cout << m << '\n';
  for (int i = 0; i < m; ++i)
    std::cout << x[i] << ' ' << y[i] << ' ' << z[i] << ' ' << w[i] << '\n';
  return 0;
}
