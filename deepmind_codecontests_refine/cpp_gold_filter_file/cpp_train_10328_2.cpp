#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <int MOD_>
struct modnum {
  static constexpr int MOD = MOD_;

 private:
  using ll = long long;
  int v;
  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
  }

 public:
  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) {
    if (v < 0) v += MOD;
  }
  explicit operator int() const { return v; }
  friend std::ostream& operator<<(std::ostream& out, const modnum& n) {
    return out << int(n);
  }
  friend std::istream& operator>>(std::istream& in, modnum& n) {
    ll v_;
    in >> v_;
    n = modnum(v_);
    return in;
  }
  friend bool operator==(const modnum& a, const modnum& b) {
    return a.v == b.v;
  }
  friend bool operator!=(const modnum& a, const modnum& b) {
    return a.v != b.v;
  }
  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD - v : 0;
    return res;
  }
  modnum operator-() const { return neg(); }
  modnum operator+() const { return modnum(*this); }
  modnum& operator++() {
    v++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator--() {
    if (v == 0) v = MOD;
    v--;
    return *this;
  }
  modnum& operator+=(const modnum& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum& operator-=(const modnum& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum& operator*=(const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator/=(const modnum& o) { return *this *= o.inv(); }
  friend modnum operator++(modnum& a, int) {
    modnum r = a;
    ++a;
    return r;
  }
  friend modnum operator--(modnum& a, int) {
    modnum r = a;
    --a;
    return r;
  }
  friend modnum operator+(const modnum& a, const modnum& b) {
    return modnum(a) += b;
  }
  friend modnum operator-(const modnum& a, const modnum& b) {
    return modnum(a) -= b;
  }
  friend modnum operator*(const modnum& a, const modnum& b) {
    return modnum(a) *= b;
  }
  friend modnum operator/(const modnum& a, const modnum& b) {
    return modnum(a) /= b;
  }
};
using num = modnum<998244353>;
const int MAXNODES = 4e4;
struct node_t {
  node_t* ch[2];
  bool mark;
} nodes[MAXNODES];
int NNODES = 0;
void update(ll m, node_t*& n, ll l, ll r) {
  if (r <= 0 || m <= l) return;
  if (!n) {
    n = &nodes[NNODES++];
  }
  assert(n);
  if (l <= 0 && m <= r) {
    n->mark = true;
    return;
  }
  update(m / 2, n->ch[0], l, r);
  update(m / 2, n->ch[1], l - m / 2, r - m / 2);
}
num INV2 = num(2).inv();
num go(ll m, ll v, vector<array<node_t*, 2>> cnds) {
  if (cnds.empty()) {
    return 0;
  }
  for (auto cnd : cnds) {
    if (cnd[0]->mark || cnd[1]->mark) {
      return num(v + v + m - 1) * num(m) * INV2;
    }
  }
  num ans = 0;
  for (int a = 0; a < 2; a++) {
    vector<array<node_t*, 2>> ncnds;
    for (int b = 0; b < 2; b++) {
      for (auto cnd : cnds) {
        if (cnd[0]->ch[b] && cnd[1]->ch[a ^ b]) {
          ncnds.push_back({cnd[0]->ch[b], cnd[1]->ch[a ^ b]});
        }
      }
    }
    ans += go(m / 2, v + a * (m / 2), ncnds);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  node_t* roots[2] = {};
  for (int z = 0; z < 2; z++) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
      ll l, r;
      cin >> l >> r;
      r++;
      update(1ll << 60, roots[z], l, r);
    }
  }
  cout << go(1ll << 60, 0, {{roots[0], roots[1]}});
  return 0;
}
