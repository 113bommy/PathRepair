#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int maxm = 200005;
const int maxn = 2005;
int fac[maxm], inv[maxm];
struct node {
  int x, y, ans;
} z[maxn];
int ret[maxn];
bool cmp(node p, node q) { return p.x + p.y < q.x + q.y; }
int modExp(int a, int b) {
  long long t = 1, y = a;
  while (b) {
    if (b & 1) t = t * y % MOD;
    y = y * y % MOD;
    b >>= 1;
  }
  return t;
}
int C(int n, int m) {
  if (n == m || m == 0) return 1;
  return (long long)fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
int Solve(int x, int y) { return C(x + y - 2, y - 1); }
int main() {
  fac[0] = 1;
  for (int i = 1; i < maxn; i++) fac[i] = (long long)fac[i - 1] * i % MOD;
  for (int i = 0; i < maxn; i++) inv[i] = modExp(fac[i], MOD - 2);
  int ans = 0, h, w, n, x, y;
  scanf("%d%d%d", &h, &w, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &z[i].x, &z[i].y);
  }
  z[n].x = h;
  z[n].y = w;
  ++n;
  sort(z, z + n, cmp);
  for (int i = 0; i < n; i++) {
    ret[i] = Solve(z[i].x, z[i].y);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (z[j].x >= z[i].x && z[j].y >= z[i].y) {
        ret[j] -= (long long)ret[i] *
                  Solve(z[j].x - z[i].x + 1, z[j].y - z[i].y + 1) % MOD;
        if (ret[j] < 0) ret[j] += MOD;
      }
    }
  }
  printf("%d\n", ret[n - 1]);
  return 0;
}
