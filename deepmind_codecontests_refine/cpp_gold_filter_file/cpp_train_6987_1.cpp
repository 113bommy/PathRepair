#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
constexpr long long mod = 1000000007;
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
const int max_n = 100;
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
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> nex(n), pre(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    if (mp.find(a[i]) == mp.end()) {
      pre[i] = -1;
    } else {
      pre[i] = mp[a[i]];
    }
    mp[a[i]] = i;
  }
  mp.clear();
  for (int i = n - 1; i >= 0; i--) {
    if (mp.find(a[i]) == mp.end()) {
      nex[i] = n;
    } else {
      nex[i] = mp[a[i]];
    }
    mp[a[i]] = i;
  }
  modint ans = 0;
  function<void(int, int)> yaru = [&](int l, int r) {
    if (l + 1 == r) {
      long long cl = l - pre[l] - 1;
      long long cr = nex[l] - l - 1;
      ans += cl * cr;
      return;
    }
    int m = (l + r) / 2;
    yaru(l, m);
    yaru(m, r);
    vector<int> x1, y1, x2, y2;
    int nl = m, nr = n - m;
    for (int i = m; i < r; i++) {
      if (pre[i] >= m) break;
      nl = min(nl, m - 1 - pre[i]);
      nr = min(nr, nex[i] - m);
      x1.push_back(nl);
      y1.push_back(nr);
    }
    nl = m, nr = n - m;
    for (int i = m - 1; i >= l; i--) {
      if (nex[i] < m) break;
      nl = min(nl, m - 1 - pre[i]);
      nr = min(nr, nex[i] - m);
      x2.push_back(nl);
      y2.push_back(nr);
    }
    vector<long long> rx2(x2.size() + 1);
    for (int i = 0; i < x2.size(); i++) rx2[i + 1] = rx2[i] + x2[i];
    vector<long long> ry2(x2.size() + 1);
    for (int i = 0; i < x2.size(); i++) ry2[i + 1] = ry2[i] + y2[i];
    vector<long long> rxy2(x2.size() + 1);
    for (int i = 0; i < x2.size(); i++)
      rxy2[i + 1] = rxy2[i] + (long long)(i + 1) * y2[i];
    vector<long long> rx2y2(x2.size() + 1);
    for (int i = 0; i < x2.size(); i++)
      rx2y2[i + 1] = rx2y2[i] + (long long)x2[i] * y2[i];
    vector<long long> rx(x2.size() + 1);
    for (int i = 0; i < x2.size(); i++) rx[i + 1] = rx[i] + (i + 1);
    modint mem = ans;
    for (int i = 0; i < x1.size(); i++) {
      int le = -1, ri = x2.size();
      while (ri - le > 1) {
        int mid = (le + ri) / 2;
        if (y2[mid] <= i)
          ri = mid;
        else
          le = mid;
      }
      ri = min(ri, x1[i]);
      int l1 = -1, r1 = ri;
      while (r1 - l1 > 1) {
        int mid = (l1 + r1) / 2;
        if (x2[mid] < x1[i])
          r1 = mid;
        else
          l1 = mid;
      }
      int l2 = -1, r2 = ri;
      while (r2 - l2 > 1) {
        int mid = (l2 + r2) / 2;
        if (y2[mid] < y1[i])
          r2 = mid;
        else
          l2 = mid;
      }
      int y = i;
      if (0 < min(r1, r2)) {
        int rs = min(r1, r2);
        ans += (long long)x1[i] * (y1[i] - (y + 1)) * rs;
        ans += -(long long)(y1[i] - (y + 1)) * rx[rs];
      }
      if (r1 < r2) {
        ans += (y1[i] - (y + 1)) * (rx2[r2] - rx2[r1]);
        ans += -(y1[i] - (y + 1)) * (rx[r2] - rx[r1]);
      }
      if (r2 < r1) {
        ans += x1[i] * (ry2[r1] - ry2[r2]);
        ans += -(long long)x1[i] * (y + 1) * (r1 - r2);
        ans += -(rxy2[r1] - rxy2[r2]);
        ans += (y + 1) * (rx[r1] - rx[r2]);
      }
      if (max(r1, r2) < ri) {
        int ls = max(r1, r2);
        ans += rx2y2[ri] - rx2y2[ls];
        ans += -(y + 1) * (rx2[ri] - rx2[ls]);
        ans += -(rxy2[ri] - rxy2[ls]);
        ans += (y + 1) * (rx[ri] - rx[ls]);
      }
    }
  };
  yaru(0, n);
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
