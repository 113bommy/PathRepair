#include <bits/stdc++.h>
using namespace std;
constexpr long long mod = 1000000007;
const long long INF = mod * mod;
const double eps = 1e-6;
const double pi = acosl(-1.0);
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
const int max_n = 1 << 21;
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
pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
  if (a.second <= b.second)
    return a;
  else
    return b;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(k, vector<int>(n));
  for (int i = 0; i < k; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  vector<pair<int, int>> swaped;
  for (int i = 0; i < k; i++) {
    int mem = -1;
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0) {
        if (mem >= 0) {
          cout << -1 << "\n";
          return;
        } else {
          mem = j;
        }
      }
    }
    if (mem < i) {
      cout << -1 << "\n";
      return;
    }
    if (i != mem) {
      swaped.push_back({i, mem});
      for (int j = 0; j < k; j++) {
        swap(a[j][i], a[j][mem]);
      }
    }
  }
  if (k == 1) {
    vector<vector<int>> vs(n);
    vector<int> par(n);
    for (int j = 0; j < n; j++) {
      vs[a[0][j]].push_back(j);
    }
    vector<pair<int, int>> ans;
    if (vs[0] != vector<int>{0}) {
      cout << -1 << "\n";
      return;
    }
    for (int i = 1; i <= n - 1; i++) {
      if (vs[i].size()) {
        if (vs[i - 1].empty()) {
          cout << -1 << "\n";
          return;
        }
        for (int id : vs[i]) {
          ans.push_back({vs[i - 1][0], id});
        }
      }
    }
    vector<int> trans(n);
    for (int i = 0; i < n; i++) trans[i] = i;
    for (pair<int, int> p : swaped) swap(trans[p.first], trans[p.second]);
    for (int i = 0; i < n - 1; i++) {
      cout << trans[ans[i].first] + 1 << " " << trans[ans[i].second] + 1
           << "\n";
    }
    return;
  }
  for (int i = 0; i < k; i++) {
    if (a[i][i] != 0) {
      cout << -1 << "\n";
      return;
    }
    for (int j = 0; j < n; j++)
      if (i != j) {
        if (a[i][j] == 0) {
          cout << -1 << "\n";
          return;
        }
      }
  }
  vector<pair<int, int>> par(n);
  for (int i = 0; i < n; i++) {
    par[i] = {0, a[0][i]};
  }
  vector<bool> ded(n);
  ded[0] = true;
  for (int i = 1; i < k; i++) {
    int d = a[0][i];
    vector<int> mem(d + 1, -1);
    for (int j = 0; j < n; j++) {
      if (a[0][j] + a[i][j] == d) {
        if (mem[a[0][j]] >= 0) {
          cout << -1 << "\n";
          return;
        }
        mem[a[0][j]] = j;
      }
    }
    for (int j = 1; j < d; j++)
      if (mem[j] < 0) {
        cout << -1 << "\n";
        return;
      }
    vector<bool> chked(n);
    mem[0] = 0;
    mem[d] = i;
    chked[0] = chked[i] = true;
    for (int j = 1; j <= d; j++) {
      pair<int, int> np = {mem[j - 1], 1};
      int id = mem[j];
      ded[id] = true;
      par[id] = merge(par[id], np);
      chked[id] = true;
    }
    for (int j = 0; j < n; j++)
      if (!chked[j]) {
        if (a[0][j] - a[i][j] == d) {
          pair<int, int> np = {i, a[i][j]};
          par[j] = merge(par[j], np);
        } else if (a[i][j] - a[0][j] == d) {
          pair<int, int> np = {0, a[0][j]};
          par[j] = merge(par[j], np);
        } else {
          int r = a[0][j] + a[i][j] - d;
          if (r % 2 == 0 && r >= 0) {
            int u = a[0][j] - r / 2;
            if (u > 0 && u < d) {
              pair<int, int> np = {mem[u], r / 2};
              par[j] = merge(par[j], np);
            } else {
              cout << -1 << "\n";
              return;
            }
          } else {
            cout << -1 << "\n";
            return;
          }
        }
      }
  }
  map<pair<int, int>, int> mp;
  for (int j = 0; j < n; j++)
    if (!ded[j]) {
      mp[par[j]] = j;
    }
  vector<vector<int>> G(n);
  vector<pair<int, int>> ans;
  for (int i = 1; i < n; i++) {
    pair<int, int> p = par[i];
    if (p.second == 1) {
      G[p.first].push_back(i);
      G[i].push_back(p.first);
      ans.push_back({i, p.first});
    } else {
      if (mp.find({p.first, p.second - 1}) == mp.end()) {
        cout << -1 << "\n";
        return;
      } else {
        int to = mp[{p.first, p.second - 1}];
        G[i].push_back(to);
        G[to].push_back(i);
        ans.push_back({i, to});
      }
    }
  }
  for (int i = 0; i < k; i++) {
    vector<int> dist(n, mod);
    queue<int> q;
    q.push(i);
    dist[i] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int to : G[v]) {
        if (dist[to] > dist[v] + 1) {
          dist[to] = dist[v] + 1;
          q.push(to);
        }
      }
    }
    for (int j = 0; j < n; j++) {
      if (a[i][j] != dist[j]) {
        cout << -1 << "\n";
        return;
      }
    }
  }
  vector<int> trans(n);
  for (int i = 0; i < n; i++) trans[i] = i;
  for (pair<int, int> p : swaped) swap(trans[p.first], trans[p.second]);
  for (int i = 0; i < n - 1; i++) {
    cout << trans[ans[i].first] + 1 << " " << trans[ans[i].second] + 1 << "\n";
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
