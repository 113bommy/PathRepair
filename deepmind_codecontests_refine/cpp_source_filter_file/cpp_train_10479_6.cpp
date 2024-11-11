#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 8005;
long double sq(int x, int y) { return sqrt(x * x + y * y); }
vector<pair<int, int> > pt;
int id[105][105];
long long r, p1, p2, p3, p4;
long long poww(long long x, long long nn) {
  long long res = 1;
  while (nn) {
    if (nn & 1) res = res * x % mod;
    x = x * x % mod;
    nn >>= 1;
  }
  return res;
}
int g[N][N];
void gauss() {
  int len = r * 2;
  for (int i = 1; i <= pt.size(); i++) {
    long long inv = poww(g[i][i], mod - 2);
    for (int j = i + 1, tot1 = 0; j <= pt.size() && tot1 <= len; j++, tot1++) {
      long long P = inv * g[j][i] % mod;
      if (P) {
        for (int k = i, tot2 = 0; k <= pt.size() && tot2 <= len; k++, tot2++)
          g[j][k] = (g[j][k] - P * g[i][k] % mod) % mod;
        g[j][0] = (g[j][0] - P * g[i][0] % mod) % mod;
      }
    }
  }
  for (int i = pt.size(), low = id[0 + 50][0 + 50]; i >= low; i--) {
    g[i][0] = 1ll * g[i][0] * poww(g[i][i], mod - 2) % mod;
    for (int j = i - 1; j >= low; j--)
      g[j][0] = (g[j][0] - 1ll * g[j][i] * g[i][0] % mod) % mod;
  }
}
int main() {
  cin >> r >> p1 >> p2 >> p3 >> p4;
  long long sum = poww((p1 + p2 + p3 + p4) % mod, mod - 2);
  p1 = p1 * sum % mod;
  p2 = p2 * sum % mod;
  p3 = p3 * sum % mod;
  p4 = p4 * sum % mod;
  for (int x = r; x >= -r; x--)
    for (int y = -r; y <= r; y++)
      if (sq(x, y) <= r) {
        pt.push_back(make_pair(x, y));
        id[x + 50][y + 50] = pt.size();
      }
  for (int x = r; x >= -r; x--)
    for (int y = -r; y <= r; y++) {
      int f = id[x + 50][y + 50];
      if (!f) continue;
      g[f][f] = g[f][0] = -1;
      if (id[x - 1 + 50][y + 50]) g[f][id[x - 1 + 50][y + 50]] = p1;
      if (id[x + 50][y - 1 + 50]) g[f][id[x + 50][y - 1 + 50]] = p2;
      if (id[x + 1 + 50][y + 50]) g[f][id[x + 1 + 50][y + 50]] = p3;
      if (id[x + 50][y + 1 + 50]) g[f][id[x + 50][y + 1 + 50]] = p4;
    }
  gauss();
  printf("%lld\n", (g[id[0 + 50][0 + 50]][0] + mod) % mod);
  return 0;
}
