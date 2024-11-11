#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 105;
const int mod = 1e9 + 7;
const double Pi = acos(-1.0);
const long long INF = 1e18;
const int G = 3, Gi = 332748118;
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int n, m;
int root[N], num[N];
long long res = 0, val[N];
int Find(int x) { return x == root[x] ? x : root[x] = Find(root[x]); }
struct node {
  int u, v;
  long long w;
} g[N];
bool cmp(node a, node b) { return a.w > b.w; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= n; ++i) {
    root[i] = i;
    num[i] = 1;
  }
  for (int i = 1; i <= n; ++i) scanf("%lld", &val[i]);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &g[i].u, &g[i].v);
    g[i].w = min(val[g[i].u], val[g[i].v]);
  }
  sort(g + 1, g + m + 1, cmp);
  for (int i = 1; i <= m; ++i) {
    int x = g[i].u, y = g[i].v;
    long long w = g[i].w;
    int tx = Find(x), ty = Find(y);
    if (tx != ty) {
      res += w * num[tx] * num[ty];
      root[tx] = ty;
      num[ty] += num[tx];
      num[tx] = 0;
    }
  }
  printf("%lf\n", (double)(res * 2.0 / (1ll * n * (n - 1))));
  return 0;
}
