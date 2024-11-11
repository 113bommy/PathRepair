#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int NMAX = 100010;
template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &item) {
  out << '(' << item.first << ", " << item.second << ')';
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  for (const auto &item : v) out << item << ' ';
  return out;
}
using type = array<int, 10>;
const type IDENTITY = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int mod;
int aa[NMAX];
int st[4 * NMAX];
type lazy[4 * NMAX];
vector<int> primes;
int a, b, x;
type val;
void euclid(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  ll xx, yy;
  euclid(b, a % b, xx, yy);
  x = yy;
  y = xx - a / b * yy;
}
type &operator+=(type &a, const type &b) {
  a[0] = (1LL * a[0] * b[0]) % mod;
  for (int i = 1; i < 10; ++i) a[i] += b[i];
}
type &operator-=(type &a, const type &b) {
  ll x, y;
  euclid(b[0], mod, x, y);
  x %= mod;
  if (x < 0) x += mod;
  a[0] = (1LL * a[0] * x) % mod;
  for (int i = 1; i < 10; ++i) a[i] -= b[i];
}
int pw(int base, int exp) {
  int res;
  for (res = 1; exp; exp >>= 1) {
    if (exp & 1) res = (1LL * res * base) % mod;
    base = (1LL * base * base) % mod;
  }
  return res;
}
int eval(const type &v) {
  int ans = v[0];
  for (int i = 0; i < primes.size(); ++i)
    ans = (1LL * ans * pw(primes[i], v[i + 1])) % mod;
  return ans;
}
type get(int x) {
  type ret = IDENTITY;
  for (int i = 0; i < primes.size(); ++i)
    while (x % primes[i] == 0) x /= primes[i], ++ret[i + 1];
  ret[0] = x;
  return ret;
}
void push(int node, int l, int r) {
  int mid = (l + r) / 2;
  int x = eval(lazy[node]);
  st[2 * node] = (1LL * st[2 * node] * x) % mod;
  lazy[2 * node] += lazy[node];
  st[2 * node + 1] = (1LL * st[2 * node + 1] * x) % mod;
  lazy[2 * node + 1] += lazy[node];
  lazy[node] = IDENTITY;
}
void build(int node, int l, int r) {
  if (l == r) {
    st[node] = aa[l] % mod;
    lazy[node] = get(aa[l]);
    return;
  }
  int mid = (l + r) / 2;
  build(2 * node, l, mid);
  build(2 * node + 1, mid + 1, r);
  lazy[node] = IDENTITY;
  st[node] = (st[2 * node] + st[2 * node + 1]) % mod;
}
void mulUpdate(int node, int l, int r) {
  if (a <= l && r <= b) {
    st[node] = (1LL * st[node] * x) % mod;
    lazy[node] += val;
    return;
  }
  push(node, l, r);
  int mid = (l + r) / 2;
  if (a <= mid) mulUpdate(2 * node, l, mid);
  if (mid + 1 <= b) mulUpdate(2 * node + 1, mid + 1, r);
  st[node] = (st[2 * node] + st[2 * node + 1]) % mod;
}
void divUpdate(int node, int l, int r) {
  if (l == r) {
    lazy[node] -= val;
    st[node] = eval(lazy[node]);
    return;
  }
  push(node, l, r);
  int mid = (l + r) / 2;
  if (a <= mid)
    divUpdate(2 * node, l, mid);
  else
    divUpdate(2 * node + 1, mid + 1, r);
  st[node] = (st[2 * node] + st[2 * node + 1]) % mod;
}
int query(int node, int l, int r) {
  if (a <= l && r <= b) return st[node];
  push(node, l, r);
  int mid = (l + r) / 2;
  int v1 = (a <= mid ? query(2 * node, l, mid) : 0);
  int v2 = (mid + 1 <= b ? query(2 * node + 1, mid + 1, r) : 0);
  return (v1 + v2) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, d, i, q, type;
  cin >> n >> mod;
  for (x = mod, d = 2; d * d <= x; ++d) {
    if (x % d == 0) {
      primes.push_back(d);
      while (x % d == 0) x /= d;
    }
  }
  if (x > 1) primes.push_back(x);
  for (i = 1; i <= n; ++i) cin >> aa[i];
  build(1, 1, n);
  for (cin >> q; q; --q) {
    cin >> type;
    if (type == 1) {
      cin >> a >> b >> x;
      val = get(x);
      mulUpdate(1, 1, n);
    } else if (type == 2) {
      cin >> a >> x;
      val = get(x);
      divUpdate(1, 1, n);
    } else {
      cin >> a >> b;
      cout << query(1, 1, n) << '\n';
    }
  }
  return 0;
}
