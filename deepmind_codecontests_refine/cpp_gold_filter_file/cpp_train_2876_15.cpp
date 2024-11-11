#include <bits/stdc++.h>
using namespace std;
constexpr int inf32 = 0x3f3f3f3f;
constexpr long long inf64 = 0x3f3f3f3f3f3f3f3f;
struct ufs {
  vector<int> fa;
  ufs(int n) : fa(n) { iota((fa).begin(), (fa).end(), 0); }
  int &operator[](const int i) { return fa[i]; }
  int operator()(const int u) {
    if (u == fa[u]) return u;
    return fa[u] = (*this)(fa[u]);
  }
};
constexpr int mod = 1000000007;
struct mint {
  int first;
  mint(int first = 0) : first(first) {}
  friend mint operator+(const mint a, const mint &b) {
    int first = a.first + b.first;
    return mint(first >= mod ? first - mod : first);
  }
  friend mint operator-(const mint a, const mint &b) {
    int first = a.first - b.first;
    return mint(first < 0 ? first + mod : first);
  }
  friend mint operator*(const mint a, const mint &b) {
    return mint(1ll * a.first * b.first % mod);
  }
};
mint mypow(mint a, int first = mod - 2, mint res = 1) {
  for (; first; first >>= 1, a = a * a)
    if (first & 1) res = res * a;
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, nq;
  cin >> n >> nq;
  vector<int> a(n);
  for (int i = 0; i < (n); ++i) cin >> a[i];
  vector<mint> p2(n + 1), ip2(n + 1), ps(n + 1);
  p2[0] = 1, ps[0] = 0;
  for (int i = 0; i < (n); ++i) p2[i + 1] = p2[i] + p2[i];
  ip2[n] = mypow(p2[n]);
  for (int i = (n)-1; i >= 0; --i) ip2[i] = ip2[i + 1] + ip2[i + 1];
  for (int i = 0; i < (n); ++i) ps[i + 1] = ps[i] + p2[i] * (a[i] + mod);
  vector<int> si(n, 1), val(n);
  ufs te(n);
  vector<vector<pair<int, int>>> q(n);
  vector<mint> ns(nq);
  for (int i = 0; i < (nq); ++i) {
    int l, r;
    cin >> l >> r, --l, --r;
    q[r].emplace_back(l, i);
  }
  vector<mint> sm(n + 1);
  constexpr int W = 2e9 + 1;
  auto mymerge = [&](int u, int v) {
    if ((si[u] > 30 && val[v] > 0) || (0ll + val[v] << si[u]) + val[u] >= W)
      val[u] = W;
    else
      val[u] += 0ll + val[v] << si[u];
    val[v] = 0, si[u] += si[v], si[v] = 0, te[v] = u;
  };
  for (int i = 0; i < (n); ++i) {
    val[te(i)] = a[i];
    while (te(i) && val[te(i)] >= 0) mymerge(te(te(i) - 1), te(i));
    sm[i + 1] = sm[te(i)] + (ps[i + 1] - ps[te(i)]) * ip2[te(i)] * 2;
    for (const pair<int, int> &u : q[i]) {
      int l = te(u.first), r = min(l + si[l], i + 1);
      ns[u.second] = sm[i + 1] - sm[r] + (ps[r] - ps[u.first]) * ip2[u.first];
    }
  }
  for (int i = 0; i < (nq); ++i) cout << ns[i].first << '\n';
  return 0;
}
