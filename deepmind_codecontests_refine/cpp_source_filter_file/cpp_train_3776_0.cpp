#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
constexpr long long mod = 998244353;
const long long INF = mod * mod;
const long double eps = 1e-12;
const long double pi = acosl(-1.0);
long long mod_pow(long long x, long long n, long long m = mod) {
  if (n < 0) {
    long long res = mod_pow(x, -n, m);
    return mod_pow(res, m - 2, m);
  }
  if (abs(x) >= m) x %= m;
  if (x < 0) x += m;
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}
struct modint {
  long long n;
  modint() : n(0) { ; }
  modint(long long m) : n(m) {
    if (n >= mod)
      n %= mod;
    else if (n < 0)
      n = (n % mod + mod) % mod;
  }
  operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) {
  a.n += b.n;
  if (a.n >= mod) a.n -= mod;
  return a;
}
modint operator-=(modint& a, modint b) {
  a.n -= b.n;
  if (a.n < 0) a.n += mod;
  return a;
}
modint operator*=(modint& a, modint b) {
  a.n = ((long long)a.n * b.n) % mod;
  return a;
}
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, long long n) {
  if (n == 0) return modint(1);
  modint res = (a * a) ^ (n / 2);
  if (n % 2) res = res * a;
  return res;
}
long long inv(long long a, long long p) {
  return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) {
  a = a / b;
  return a;
}
const int max_n = 1 << 17;
modint fact[max_n], factinv[max_n];
void init_f() {
  fact[0] = modint(1);
  for (int i = 0; i < max_n - 1; i++) {
    fact[i + 1] = fact[i] * modint(i + 1);
  }
  factinv[max_n - 1] = modint(1) / fact[max_n - 1];
  for (int i = max_n - 2; i >= 0; i--) {
    factinv[i] = factinv[i + 1] * modint(i + 1);
  }
}
modint comb(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return fact[a] * factinv[a - b];
}
int gcd(int a, int b) {
  if (a < b) swap(a, b);
  while (b) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
  vector<int> a(m), b(m);
  vector<vector<int>> G(n);
  vector<int> ids;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
    ids.push_back(a[i]);
    ids.push_back(b[i]);
  }
  sort((ids).begin(), (ids).end());
  ids.erase(unique((ids).begin(), (ids).end()), ids.end());
  vector<vector<int>> vid;
  vector<bool> used(n);
  for (int i = 0; i < ids.size(); i++) {
    int id = ids[i];
    if (used[id]) continue;
    vector<int> cur;
    queue<int> q;
    q.push(id);
    used[id] = true;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      cur.push_back(v);
      for (int to : G[v])
        if (!used[to]) {
          used[to] = true;
          q.push(to);
        }
    }
    vid.push_back(cur);
  }
  vector<int> trans(n, -1);
  for (int i = 0; i < vid.size(); i++) {
    for (int j = 0; j < vid[i].size(); j++) {
      trans[vid[i][j]] = j;
    }
  }
  vector<vector<vector<modint>>> memo(vid.size());
  for (int i = 0; i < vid.size(); i++) {
    int len = vid[i].size();
    vector<bool> can(1 << len);
    can[0] = true;
    vector<vector<bool>> exi(len, vector<bool>(len));
    for (int id : ids) {
      for (int to : G[id]) {
        exi[trans[id]][trans[to]] = true;
      }
    }
    for (int j = 1; j < (1 << len); j++) {
      vector<int> cc;
      for (int k = 0; k < len; k++)
        if (j & (1 << k)) cc.push_back(k);
      int nj = j ^ (1 << cc[0]);
      if (!can[nj]) {
        can[j] = false;
        continue;
      }
      can[j] = true;
      for (int k = 1; k < cc.size(); k++) {
        if (exi[cc[0]][cc[k]]) can[j] = false;
      }
    }
    memo[i].resize(1 << len);
    for (int j = 0; j < (1 << len); j++) {
      int cnt = 0;
      for (int k = 0; k < len; k++)
        if (j & (1 << k)) cnt++;
      memo[i][j].resize(cnt + 1);
      if (can[j]) memo[i][j][cnt] = 1;
    }
    for (int j = 0; j < len; j++)
      for (int k = 0; k < (1 << len); k++)
        if (k & (1 << j))
          for (int l = 0; l < memo[i][k ^ (1 << j)].size(); l++) {
            memo[i][k][l] += memo[i][k ^ (1 << j)][l];
          }
  }
  vector<int> ads(n + 1);
  vector<int> decs(n + 1);
  for (int i = 0; i < n; i++) {
    if (trans[i] < 0) {
      ads[l[i]]++;
      decs[r[i]]++;
    }
  }
  int cnt = 0;
  modint ans = 0;
  for (int c = 1; c <= n; c++) {
    cnt += ads[c];
    vector<modint> dp = {1};
    for (int i = 0; i < vid.size(); i++) {
      int s = 0;
      for (int j = 0; j < vid[i].size(); j++) {
        int id = vid[i][j];
        if (l[id] <= c && c <= r[id]) s |= (1 << j);
      }
      vector<modint>& vdp = memo[i][s];
      vector<modint> ndp(dp.size() + vdp.size() - 1);
      for (int j = 0; j < dp.size(); j++)
        for (int k = 0; k < vdp.size(); k++) {
          ndp[j + k] += dp[j] * vdp[k];
        }
      swap(dp, ndp);
    }
    modint csum = 0;
    for (int j = 0; j < dp.size(); j++) {
      if (j > c) continue;
      int r = c - j;
      csum += comb(cnt, r) * dp[j];
    }
    ans += csum;
    cnt -= decs[c];
  }
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init_f();
  solve();
  return 0;
}
