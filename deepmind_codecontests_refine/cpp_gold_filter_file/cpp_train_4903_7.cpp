#include <bits/stdc++.h>
using namespace std;
struct DSU {
  vector<long long> M;
  DSU(long long n) {
    M.resize(n);
    for (long long i = 0; i < n; i++) {
      M[i] = i;
    }
  }
  long long root(long long x) {
    while (M[x] != x) {
      long long nx = M[x];
      M[x] = M[nx];
      x = nx;
    }
    return x;
  }
  bool join(long long x, long long y) {
    long long xr = root(x);
    long long yr = root(y);
    if (xr == yr) {
      return false;
    } else {
      M[yr] = xr;
      return true;
    }
  }
  bool check(long long x, long long y) { return root(x) == root(y); }
};
long long u[2005];
int main() {
  ios::sync_with_stdio(0);
  long long n, m, q, x, y;
  cin >> n >> m >> q;
  long long z = n + m - 1;
  DSU dsu(n + m);
  for (long long i = 0; i < q; i++) {
    cin >> x >> y;
    x--;
    y--;
    if (dsu.join(x, y + n)) z--;
  }
  cout << z;
  return 0;
}
