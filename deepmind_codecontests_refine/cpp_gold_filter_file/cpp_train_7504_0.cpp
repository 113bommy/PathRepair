#include <bits/stdc++.h>
using namespace std;
unsigned GCD(unsigned u, unsigned v) {
  unsigned r;
  while (v != 0) {
    r = u % v;
    u = v;
    v = r;
  }
  return u;
}
int64_t xGCD(int64_t a, int64_t b, int64_t &x, int64_t &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int64_t x1, y1, gcd = xGCD(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return gcd;
}
int64_t inv(int64_t x, int64_t mod) {
  int64_t res, t;
  xGCD(mod, x % mod, t, res);
  return (res % mod + mod) % mod;
}
struct DSU {
  vector<int64_t> deg;
  vector<int64_t> par;
  int64_t sum;
  DSU() {}
  DSU(int64_t n) {
    deg.resize(n, 0);
    par.resize(n, -1);
    sum = n;
  }
  int64_t find(int64_t x) {
    if (par[x] == -1) return x;
    return par[x] = find(par[x]);
  }
  void uni(int64_t x, int64_t y) {
    x = find(x);
    y = find(y);
    if ((x != -1 || y != -1) && x == y) return;
    sum--;
    if (deg[x] < deg[y])
      par[x] = y;
    else {
      deg[x] += (deg[x] == deg[y]);
      par[y] = x;
    }
  }
};
int64_t mod = 1e9 + 7, inf = 4e18;
int64_t sum = 0;
int64_t tmp3 = 0, tmp = 0, tmp2 = 0, comb = 1;
vector<int64_t> check, st;
int64_t maxi = 0, mini = inf;
string s2, s;
vector<vector<int64_t> > g;
bool high = 0;
bool ask(int64_t r1, int64_t c1, int64_t r2, int64_t c2) {
  string ans;
  cout << "? " << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << endl;
  fflush(stdout);
  cin >> ans;
  return ans == "YES";
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int64_t n;
  cin >> n;
  vector<bool> ans(2 * n - 2);
  int64_t curr = 1, curc = 1;
  for (int64_t i = 0; i < n - 1; i++) {
    if (ask(curr, curc + 1, n, n)) {
      ans[i] = 1;
      curc += 1;
    } else {
      curr += 1;
      ans[i] = 0;
    }
  }
  curr = n, curc = n;
  for (int64_t i = 2 * n - 3; i >= n - 1; i--) {
    if (ask(1, 1, curr - 1, curc)) {
      ans[i] = 0;
      curr--;
    } else {
      ans[i] = 1;
      curc -= 1;
    }
  }
  cout << "! ";
  for (auto x : ans) cout << (x ? 'R' : 'D');
  return 0;
}
