#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, mod = 998244353;
const double pi = 3.1415926535897932, eps = 1e-6;
void chmax(int &x, int y) {
  if (x < y) x = y;
}
void chmin(int &x, int y) {
  if (x > y) x = y;
}
struct SQR {
  long long sqr, sum, len;
  void add(long long x) {
    sqr += x * x;
    sum += x;
    len++;
  }
  long long query(long long x) { return x * x * len + sqr - 2 * sum * x; }
} xx, yy;
map<int, int> mp;
int n, m, a[1005][1005], cnt, sx, sy;
vector<pair<int, int> > vals[1000005];
long long co[1000005], dp[1000005], pre[1000005];
long long qpow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
long long cinv(long long x) { return qpow(x, mod - 2); }
long long inv[1000005];
int main() {
  scanf("%d%d", &n, &m);
  for (int(i) = (1); (i) <= (n); (i)++)
    for (int(j) = (1); (j) <= (m); (j)++) scanf("%d", &a[i][j]);
  scanf("%d%d", &sx, &sy);
  int v = a[sx][sy];
  for (int(i) = (1); (i) <= (n); (i)++)
    for (int(j) = (1); (j) <= (m); (j)++) {
      if (a[i][j] <= v) mp[a[i][j]] = 0;
    }
  for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    it->second = ++cnt;
  for (int(i) = (1); (i) <= (n); (i)++)
    for (int(j) = (1); (j) <= (m); (j)++) {
      if (a[i][j] < a[sx][sy] || (i == sx && j == sy)) {
        a[i][j] = mp[a[i][j]];
        vals[a[i][j]].push_back(make_pair(i, j));
      }
    }
  for (int(i) = (1); (i) <= (n * m); (i)++) inv[i] = cinv(i);
  for (int(i) = (1); (i) <= (cnt); (i)++) {
    long long xv = 0, yv = 0;
    for (int(j) = (0); (j) < (vals[i].size()); (j)++) {
      int p1 = vals[i][j].first, p2 = vals[i][j].second;
      xv += xx.query(p1);
      yv += yy.query(p2);
      xv %= mod;
      yv %= mod;
    }
    co[i] = (xv + yv) % mod * inv[vals[i].size()] % mod * inv[xx.len] % mod;
    for (int(j) = (0); (j) < (vals[i].size()); (j)++) {
      int p1 = vals[i][j].first, p2 = vals[i][j].second;
      xx.add(p1);
      yy.add(p2);
    }
  }
  long long sumw = vals[1].size();
  for (int(i) = (2); (i) <= (cnt); (i)++) {
    long long w = vals[i].size();
    dp[i] = (pre[i - 1] * inv[sumw] % mod + co[i]) % mod;
    pre[i] = (pre[i - 1] + dp[i] * w % mod) % mod;
    sumw += w;
  }
  printf("%d\n", dp[a[sx][sy]]);
  return 0;
}
