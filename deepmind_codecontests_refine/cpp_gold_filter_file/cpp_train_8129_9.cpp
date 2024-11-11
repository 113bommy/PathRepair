#include <bits/stdc++.h>
using namespace std;
long long qpow(long long x, long long k, long long mod) {
  long long ret = 1;
  while (k) {
    if (k & 1) {
      ret = ret * x;
      ret = ret % mod;
    }
    x = x * x;
    x = x % mod;
    k = (k >> 1);
  }
  return ret;
}
const int Maxn = 1005;
const int md = 998244353;
int n, m;
int a[Maxn][Maxn];
long long e[Maxn][Maxn];
long long inv[Maxn * Maxn];
long long cnt[2][Maxn];
int r, c;
vector<pair<int, pair<int, int> > > vv;
void pre() {
  for (int i = 1; i < Maxn * Maxn; i++) {
    inv[i] = qpow(i, md - 2, md);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", a[i] + j);
      vv.push_back(pair<int, pair<int, int> >(a[i][j], pair<int, int>(i, j)));
    }
  }
  scanf("%d%d", &r, &c);
  pre();
  sort((vv).begin(), (vv).end());
  long long sume = 0, sumx = 0, sumx2 = 0, sumy = 0, sumy2 = 0, ans = 0;
  for (int i = 0, j = 0; i < vv.size(); i++) {
    if (i && vv[i].first != vv[i - 1].first) {
      for (; j < i; j++) {
        long long nx = vv[j].second.first, ny = vv[j].second.second;
        sume = (sume + e[nx][ny]) % md;
        sumx = (sumx + nx) % md;
        sumx2 = (sumx2 + nx * nx) % md;
        sumy = (sumy + ny) % md;
        sumy2 = (sumy2 + ny * ny) % md;
      }
    }
    long long x = vv[i].second.first, y = vv[i].second.second;
    long long tmp = (sume + sumx2 + sumy2 - sumx * x * 2 - sumy * y * 2) % md;
    if (j) tmp = (tmp * inv[j] + x * x + y * y) % md;
    if (tmp < 0) tmp += md;
    e[x][y] = tmp;
  }
  printf("%lld\n", e[r][c]);
  return 0;
}
