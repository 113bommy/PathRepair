#include <bits/stdc++.h>
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};
using namespace std;
class pa3 {
 public:
  int x;
  int y, z;
  pa3(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
  bool operator<(const pa3 &p) const {
    if (x != p.x) return x < p.x;
    if (y != p.y) return y < p.y;
    return z < p.z;
  }
  bool operator>(const pa3 &p) const {
    if (x != p.x) return x > p.x;
    if (y != p.y) return y > p.y;
    return z > p.z;
  }
  bool operator==(const pa3 &p) const {
    return x == p.x && y == p.y && z == p.z;
  }
  bool operator!=(const pa3 &p) const {
    return !(x == p.x && y == p.y && z == p.z);
  }
};
class pa4 {
 public:
  int x;
  int y, z, w;
  pa4(int x = 0, int y = 0, int z = 0, int w = 0) : x(x), y(y), z(z), w(w) {}
  bool operator<(const pa4 &p) const {
    if (x != p.x) return x < p.x;
    if (y != p.y) return y < p.y;
    if (z != p.z) return z < p.z;
    return w < p.w;
  }
  bool operator>(const pa4 &p) const {
    if (x != p.x) return x > p.x;
    if (y != p.y) return y > p.y;
    if (z != p.z) return z > p.z;
    return w > p.w;
  }
  bool operator==(const pa4 &p) const {
    return x == p.x && y == p.y && z == p.z && w == p.w;
  }
};
class pa2 {
 public:
  int x, y;
  pa2(int x = 0, int y = 0) : x(x), y(y) {}
  pa2 operator+(pa2 p) { return pa2(x + p.x, y + p.y); }
  pa2 operator-(pa2 p) { return pa2(x - p.x, y - p.y); }
  bool operator<(const pa2 &p) const { return y != p.y ? y < p.y : x < p.x; }
  bool operator>(const pa2 &p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const pa2 &p) const {
    return abs(x - p.x) == 0 && abs(y - p.y) == 0;
  }
  bool operator!=(const pa2 &p) const {
    return !(abs(x - p.x) == 0 && abs(y - p.y) == 0);
  }
};
string itos(int i) {
  ostringstream s;
  s << i;
  return s.str();
}
int gcd(int v, int b) {
  if (v > b) return gcd(b, v);
  if (v == b) return b;
  if (b % v == 0) return v;
  return gcd(v, b % v);
}
double distans(double x1, double y1, double x2, double y2) {
  double rr = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  return sqrt(rr);
}
int mod;
int extgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int d = extgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
pair<int, int> operator+(const pair<int, int> &l, const pair<int, int> &r) {
  return {l.first + r.first, l.second + r.second};
}
int pr[1200010];
int inv[1200010];
int beki(int wa, int rr, int warukazu) {
  if (rr == 0) return 1 % warukazu;
  if (rr == 1) return wa % warukazu;
  wa %= warukazu;
  if (rr % 2 == 1)
    return ((long long)beki(wa, rr - 1, warukazu) * (long long)wa) % warukazu;
  long long zx = beki(wa, rr / 2, warukazu);
  return (zx * zx) % warukazu;
}
double bekid(double w, int r) {
  if (r == 0) return 1.0;
  if (r == 1) return w;
  if (r % 2) return bekid(w, r - 1) * w;
  double f = bekid(w, r / 2);
  return f * f;
}
int comb(int nn, int rr) {
  int r = pr[nn] * inv[rr];
  r %= mod;
  r *= inv[nn - rr];
  r %= mod;
  return r;
}
void gya(int ert) {
  pr[0] = 1;
  for (int i = 1; i <= ert; i++) {
    pr[i] = (pr[i - 1] * i) % mod;
  }
  for (int i = 0; i <= ert; i++) inv[i] = beki(pr[i], mod - 2, mod);
}
using A = array<int, 20>;
int ue[1 << 20] = {};
A zero;
A mer(A a, A b) {
  array<int, 40> c;
  for (int i = 0; i < 20; i++) c[i] = a[i];
  for (int i = 0; i < 20; i++) c[i + 20] = b[i];
  for (int i = 20; i >= 0; i--) {
    int ima = -1;
    for (int j = 0; j < 40; j++) {
      if (c[j] >= (1 << (i + 1))) continue;
      if ((c[j] & (1 << i)) == 0) continue;
      if (ima < 0)
        ima = c[j];
      else
        c[j] ^= ima;
    }
  }
  sort(c.begin(), c.end(), greater<int>());
  A d = zero;
  for (int i = 0; i < 20; i++)
    if (c[i]) {
      d[ue[c[i]]] = c[i];
    }
  return d;
}
int solve2(A a) {
  int ans = 0;
  for (int i = 19; i >= 0; i--) {
    ans = max(ans, ans ^ a[i]);
  }
  return ans;
}
int f[500020];
int ans[500020];
pair<int, int> que[500020];
A ar[500020];
A tasu(A a, int r, bool bo = 0) {
  if (r == 0) return a;
  int d = ue[r];
  for (int i = d; i >= 0; i--)
    if (r & (1 << i)) {
      if (a[i] == 0) {
        a[i] = r;
        return a;
      }
      r = r ^ a[i];
    }
  for (int i = 0; i < 20; i++)
    if (a[i]) {
      if (a[i] & (1 << i)) continue;
      exit(1);
    }
  return a;
}
void shori(int l, int r, int m) {
  ar[m] = tasu(zero, f[m]);
  ar[m - 1] = tasu(zero, f[m - 1]);
  for (int i = m + 1; i < r; i++) {
    ar[i] = tasu(ar[i - 1], f[i]);
  }
  for (int i = m - 2; i >= l; i--) {
    ar[i] = tasu(ar[i + 1], f[i]);
  }
}
void solve(int l, int r, vector<int> ve) {
  if (ve.size() == 0) return;
  if (l + 1 == r) {
    for (auto v : ve) {
      ans[v] = f[l];
    }
    return;
  }
  int m = (l + r) / 2;
  shori(l, r, m);
  vector<int> v1, v2;
  for (auto v : ve) {
    if (que[v].second <= m)
      v1.push_back(v);
    else if (que[v].first >= m)
      v2.push_back(v);
    else {
      A z = mer(ar[que[v].first], ar[que[v].second - 1]);
      ans[v] = solve2(z);
    }
  }
  solve(l, m, v1);
  solve(m, r, v2);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  for (int i = 1; i < 21; i++) {
    for (int j = (1 << (i - 1)); j < (1 << i); j++) ue[j] = i - 1;
  }
  for (int i = 0; i < 20; i++) zero[i] = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> f[i];
  }
  vector<int> ve;
  int q;
  cin >> q;
  for (int rt = 0; rt < q; rt++) {
    int l, r;
    cin >> l >> r;
    l--;
    que[rt] = make_pair(l, r);
    int d = r - l;
    if (d == 1) {
      ans[rt] = f[l];
    } else {
      ve.push_back(rt);
    }
  }
  solve(0, n, ve);
  for (int i = 0; i < q; i++) cout << ans[i] << "\n";
  return 0;
}
