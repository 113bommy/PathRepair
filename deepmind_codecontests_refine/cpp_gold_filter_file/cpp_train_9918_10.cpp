#include <bits/stdc++.h>
using namespace std;
constexpr long long mod = 1000000007;
const long long INF = mod * mod;
const long double eps = 1e-8;
const long double pi = acosl(-1.0);
long long mod_pow(long long x, long long n, long long m = mod) {
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
const int max_n = 1 << 19;
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
  int n;
  cin >> n;
  if (n % 2 == 0) {
    int cop = n;
    int tmp = 0;
    while (cop % 2 == 0) {
      tmp++;
      cop /= 2;
    }
    int s = (1 << tmp);
    cout << "First" << endl;
    vector<pair<int, int>> v;
    for (int i = 0; i < 2 * n / (2 * s); i++) {
      for (int j = 0; j < s; j++) {
        v.push_back({i * 2 * s + 1 + j, i * 2 * s + 1 + j + s});
      }
    }
    vector<int> ans(2 * n + 1);
    for (int j = 0; j < v.size(); j++) {
      ans[v[j].first] = ans[v[j].second] = j + 1;
    }
    for (int i = 1; i <= 2 * n; i++) {
      if (i > 1) cout << " ";
      cout << ans[i];
    }
    cout << endl;
    int res;
    cin >> res;
    return;
  } else {
    cout << "Second" << endl;
    vector<vector<int>> b(n, vector<int>(2, -1));
    vector<int> p(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) cin >> p[i];
    p[0] = p[2 * n];
    for (int i = 0; i < 2 * n; i++) {
      p[i]--;
      if (b[p[i]][0] < 0) {
        b[p[i]][0] = i;
      } else
        b[p[i]][1] = i;
    }
    vector<bool> used(n, false);
    vector<vector<int>> vl, vr;
    vector<int> cl, cr;
    for (int i = 0; i < n; i++) {
      if (used[i]) continue;
      int cur = i;
      vector<int> ls, rs;
      while (true) {
        int to = b[p[cur]][0] ^ b[p[cur]][1] ^ cur;
        ls.push_back(cur);
        rs.push_back(to);
        if (to == i + n) {
          used[i] = true;
          break;
        }
        cur = (to + n) % (2 * n);
        used[cur % n] = true;
      }
      int c0 = 0, c1 = 0;
      for (int id : ls)
        if (id >= n) c0++;
      for (int id : rs)
        if (id >= n) c1++;
      cl.push_back(c0);
      cr.push_back(c1);
      vl.push_back(ls);
      vr.push_back(rs);
    }
    int chk = -1;
    for (int i = 0; i < cl.size(); i++)
      if ((cl[i] + cr[i]) % 2) chk = i;
    vector<int> ans;
    int tmp = 0;
    for (int i = 0; i < cl.size(); i++)
      if (i != chk) {
        for (int id : vl[i]) ans.push_back(id);
        tmp += cl[i];
      }
    if ((tmp + cl[chk]) % 2 == (n / 2) % 2) {
      for (int id : vl[chk]) ans.push_back(id);
    } else {
      for (int id : vr[chk]) ans.push_back(id);
    }
    for (int i = 0; i < ans.size(); i++)
      if (ans[i] == 0) ans[i] = 2 * n;
    sort((ans).begin(), (ans).end());
    for (int i = 0; i < n; i++) {
      if (i > 0) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
}
signed main() {
  solve();
  return 0;
}
