#include <bits/stdc++.h>
using namespace std;
int n, m;
int x;
int F[1000086];
long long f[1000086], g[1000086];
vector<long long> v[1000086];
int l[1000086];
int main() {
  scanf("%d", &n);
  memset(f, -0x3f, sizeof(f)), f[0] = 0;
  for (int i = 0, y = 1; i < 6; i++, y *= 10) {
    scanf("%d", &x), F[i] = x;
    int z = 3 * y;
    for (int j = 0; j < z; j++) v[j].clear(), l[j] = 0;
    for (int j = 0; j < 1000086; j++) {
      int q = j / z, r = j % z;
      while (v[r].size() > l[r] && j - v[r][l[r]] > 1ll * z * 3 * (n - 1))
        l[r]++;
      while (v[r].size() > l[r] &&
             f[j] - 1ll * q * x >= f[v[r].back()] - 1ll * v[r].back() / z * x)
        v[r].pop_back();
      v[r].push_back(j);
      g[j] = 1ll * q * x + f[v[r][l[r]]] - 1ll * v[r][l[r]] / z * x;
    }
    for (int j = 0; j < 1000086; j++) f[j] = g[j];
  }
  for (int i = 0, y = 1; i < 6; i++, y *= 10) {
    for (int j = 1000086 - 1; j; j--) {
      for (int k = 1; k <= 9 && j - y * k >= 0; k++) {
        f[j] = max(f[j], f[j - y * k] + (k % 3 ? 0 : 1ll * k / 3 * F[i]));
      }
    }
  }
  scanf("%d", &m);
  while (m--) {
    scanf("%d", &x);
    printf("%lld\n", f[x]);
  }
}
