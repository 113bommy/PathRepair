#include <bits/stdc++.h>
#pragma GCC optimize "-O3"
using ll = long long;
using ld = long double;
using ull = uint64_t;
using namespace std;
vector<pair<int, int>> pts;
const int MAXN = 7845;
const int MOD = 1e9 + 7;
ll pw(ll a, ll b = MOD - 2) {
  if (!b) {
    return 1;
  }
  ll v = pw(a, b / 2);
  v = (v * v) % MOD;
  if (b & 1) {
    v = (v * a) % MOD;
  }
  return v;
}
int f[MAXN][MAXN + 1];
ll rev[MAXN];
ll ans[MAXN];
int n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int p[4];
int r;
bool g(int x, int y) { return x * x + y * y <= r * r; }
int gtid(int nx, int ny) {
  pair<int, int> p{nx, ny};
  int id = lower_bound(pts.begin(), pts.end(), p) - pts.begin();
  return id;
}
const int MV = 102;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(20);
  cin >> r;
  ll s = 0;
  for (int& x : p) {
    cin >> x;
    s += x;
  }
  s = pw(s, MOD - 2);
  for (int& x : p) {
    x = (s * x) % MOD;
  }
  for (int i = -r; i <= r; ++i) {
    for (int j = -r; j <= r; ++j) {
      if (g(i, j)) {
        pts.emplace_back(i, j);
      }
    }
  }
  n = pts.size();
  for (int i = 0; i < n; ++i) {
    f[i][i] = 1;
    f[i][n] = 1;
    int x = pts[i].first, y = pts[i].second;
    for (int j = 0; j < 4; ++j) {
      int nx = x + dx[j], ny = y + dy[j];
      if (g(nx, ny)) {
        int id = gtid(nx, ny);
        f[i][id] = -p[j];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    assert(f[i][i]);
    vector<int> ids = {n};
    int rg = min(n, i + MV);
    for (int j = i; j < rg; ++j) {
      ids.push_back(j);
    }
    rev[i] = pw(f[i][i]);
    for (int j = i + 1; j < rg; ++j) {
      ll cmul = f[j][i] * rev[i] % MOD;
      if (!cmul) {
        continue;
      }
      for (int id : ids) {
        f[j][id] = (f[j][id] - f[i][id] * cmul) % MOD;
      }
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    ll cf = f[i][n];
    int rg = min(n, i + MV);
    for (int j = i + 1; j < rg; ++j) {
      cf = (cf - ans[j] * f[i][j]) % MOD;
    }
    ans[i] = cf * rev[i] % MOD;
  }
  int id = gtid(0, 0);
  if (ans[id] < 0) {
    ans[id] += MOD;
  }
  cout << ans[id] << "\n";
}
