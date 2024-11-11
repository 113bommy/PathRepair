#include <bits/stdc++.h>
using namespace std;
long long n, m, mod, l, r, u, v;
long long sum(long long gl, long long gr, long long pl, long long pr,
              long long step) {
  if (gl > r) return 0;
  if (u <= pl && v >= pr) {
    if (gr < gl) return 0;
    int old_gl = gl;
    gl = ((l - gl) / step) * step + gl;
    if (gl < l) gl += step;
    gr = ((r - old_gl) / step) * step + old_gl;
    if (gr < gl)
      return 0;
    else {
      long long n = (gr - gl) / step + 1;
      long long z = gl + gr;
      if (!(n % 2))
        return (((n / 2) % mod) * (z % mod) + n) % mod;
      else
        return (((z / 2) % mod) * (n % mod) + n) % mod;
    }
  }
  if (gl + step >= gr) {
    if (gl >= l && gl <= r) {
      return (gl + 1) % mod;
    } else {
      return 0;
    }
  }
  long long pm = (pl + pr + 1) / 2, total = 0;
  if (u < pm) total = (total + sum(gl, gr, pl, pm, step * 2)) % mod;
  if (v >= pm)
    total = (total + sum(gl + step, gr + step * (((pr - pl) % 2 == 0) ? 1 : -1),
                         pm, pr, step * 2)) %
            mod;
  return total;
}
int main() {
  cin >> n >> m >> mod;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> l >> r;
    u--;
    v--;
    l--;
    r--;
    if (v > n - 1) v = n - 1;
    if (r > n - 1) r = n - 1;
    if (r < l || v < u) {
      cout << 0 << endl;
    } else {
      cout << sum(0, n, 0, n, 1);
      cout << endl;
    }
  }
}
