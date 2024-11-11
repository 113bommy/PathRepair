#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7, B = 52;
long long power(long long b, long long e) {
  if (!e) return 1;
  long long tmp = power(b, e >> 1);
  tmp = 1ll * tmp * tmp % Mod;
  if (e & 1) tmp = 1ll * tmp * b % Mod;
  return tmp;
}
long long inv(long long x) { return power(x, Mod - 2); }
long long p1, p2, p3, p4, R, f[110][110][110], g[110][110], a[110][110], b[110],
    x[110];
bool in(long long x, long long y) { return x * x + y * y <= R * R; }
long long adj(long long x) { return (x % Mod + Mod) % Mod; }
void upd(long long x, long long y) {
  for (long long z = -R + 1; z <= R - 1; z++)
    f[x + 1 + B][y + B][z + B] =
        adj(f[x + B][y + B][z + B] - p1 * f[x - 1 + B][y + B][z + B] -
            p2 * f[x + B][y - 1 + B][z + B] - p4 * f[x + B][y + 1 + B][z + B]) *
        inv(p3) % Mod;
  g[x + 1 + B][y + B] =
      adj(g[x + B][y + B] - p1 * g[x - 1 + B][y + B] -
          p2 * g[x + B][y - 1 + B] - p4 * g[x + B][y + 1 + B] - 1) *
      inv(p3) % Mod;
}
void gauss(long long n) {
  for (long long i = 1; i <= n; i++) {
    for (long long j = i; j <= n; j++)
      if (a[j][i]) {
        for (long long k = 1; k <= n; k++) swap(a[i][k], a[j][k]);
        swap(b[i], b[j]);
        break;
      }
    for (long long j = 1; j <= n; j++)
      if (i != j) {
        long long rate = a[j][i] * inv(a[i][i]) % Mod;
        for (long long k = 1; k <= n; k++)
          a[j][k] = adj(a[j][k] - a[i][k] * rate);
        b[j] = adj(b[j] - b[i] * rate);
      }
  }
  for (long long i = 1; i <= n; i++) x[i] = b[i] * inv(a[i][i]) % Mod;
}
signed main() {
  long long a1, a2, a3, a4;
  cin >> R >> a1 >> a2 >> a3 >> a4;
  if (!R) {
    cout << 1;
    return 0;
  }
  p1 = a1 * inv(a1 + a2 + a3 + a4) % Mod;
  p2 = a2 * inv(a1 + a2 + a3 + a4) % Mod;
  p3 = a3 * inv(a1 + a2 + a3 + a4) % Mod;
  p4 = a4 * inv(a1 + a2 + a3 + a4) % Mod;
  for (long long y = -R + 1; y <= R - 1; y++) {
    long long x = -sqrt(R * R - y * y);
    f[x + B][y + B][y + B] = 1;
  }
  for (long long x = -R; x <= -1; x++)
    for (long long y = -R; y <= R; y++)
      if (in(x, y) && in(x + 1, y)) upd(x, y);
  for (long long z = -R + 1; z <= R - 1; z++) {
    f[0 + B][-R + B][z + B] = p4 * f[0 + B][-R + 1 + B][z + B] % Mod;
    f[0 + B][R + B][z + B] = p2 * f[0 + B][R - 1 + B][z + B] % Mod;
  }
  g[0 + B][-R + B] = (p4 * g[0 + B][-R + 1 + B] + 1) % Mod;
  g[0 + B][R + B] = (p2 * g[0 + B][R - 1 + B] + 1) % Mod;
  for (long long x = 0; x <= R - 1; x++)
    for (long long y = -R; y <= R; y++)
      if (in(x, y) && in(x + 1, y)) upd(x, y);
  for (long long y = -R + 1; y <= R - 1; y++) {
    long long x = sqrt(R * R - y * y);
    for (long long z = -R + 1; z <= R - 1; z++)
      a[y + R][z + R] = adj(
          f[x + B][y + B][z + B] - p1 * f[x - 1 + B][y + B][z + B] -
          p2 * f[x + B][y - 1 + B][z + B] - p4 * f[x + B][y + 1 + B][z + B]);
    b[y + R] = adj(p1 * g[x - 1 + B][y + B] + p2 * g[x + B][y - 1 + B] +
                   p4 * g[x + B][y + 1 + B] + 1 - g[x + B][y + B]);
  }
  gauss(R * 2 - 1);
  long long ans = g[0 + B][0 + B];
  for (long long z = -R + 1; z <= R - 1; z++)
    ans = adj(ans + x[z + R] * f[0 + B][0 + B][z + B]);
  cout << ans << endl;
  return 0;
}
