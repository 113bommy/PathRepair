#include <bits/stdc++.h>
inline int pw(int base, int p, int mod) {
  static int res;
  for (res = 1; p;
       p >>= 1, (base = static_cast<long long>(base) * (base) % mod))
    if (p & 1) (res = static_cast<long long>(res) * (base) % mod);
  return res;
}
int n, m, seed, vmax;
int rnd() {
  static const int mod = 1e9 + 7;
  static int t;
  t = seed;
  seed = (7ll * seed + 13) % mod;
  return t;
}
namespace ODT {
struct node {
  int l, r;
  mutable long long v;
  inline bool operator<(const node &rhs) const { return l < rhs.l; }
};
std::set<node> s;
std::set<node>::iterator split(int pos) {
  std::set<node>::iterator it = s.lower_bound((node){pos, 0, 0});
  if (it != s.end() && it->l == pos) return it;
  --it;
  const int l = it->l, r = it->r;
  const long long v = it->v;
  s.erase(it), s.insert((node){l, pos - 1, v});
  return s.insert((node){pos, r, v}).first;
}
void assign(int l, int r, int v) {
  std::set<node>::iterator R = split(r + 1), L = split(l);
  s.erase(L, R), s.insert((node){l, r, v});
}
void add(int l, int r, int v) {
  std::set<node>::iterator R = split(r + 1), L = split(l);
  for (std::set<node>::iterator it = L; it != R; ++it) it->v += v;
}
long long rnk(int l, int r, int k) {
  static std::vector<std::pair<long long, int> > v;
  v.clear();
  std::set<node>::iterator R = split(r + 1), L = split(l);
  for (std::set<node>::iterator it = L; it != R; ++it)
    v.push_back(std::make_pair(it->v, it->r - it->l + 1));
  std::sort(v.begin(), v.end());
  for (std::pair<long long, int> i : v) {
    k -= i.second;
    if (k <= 0) return i.first;
  }
}
int query(int l, int r, int x, int mod) {
  std::set<node>::iterator R = split(r + 1), L = split(l);
  int ans = 0;
  for (std::set<node>::iterator it = L; it != R; ++it)
    ans = (ans + (static_cast<long long>(pw(it->v % mod, x, mod)) *
                  (it->r - it->l + 1) % mod)) %
          mod;
  return ans;
}
}  // namespace ODT
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
  std::cin >> n >> m >> seed >> vmax;
  for (int i = 1, x; i <= n; ++i) {
    x = (rnd() % vmax) + 1;
    ODT::s.insert((ODT::node){i, i, x});
  }
  while (m-- > 0) {
    static int op, l, r, x, y;
    op = (rnd() % 4) + 1;
    l = (rnd() % n) + 1;
    r = (rnd() % n) + 1;
    if (l > r) std::swap(l, r);
    if (op == 3)
      x = rnd() % (r - l + 1) + 1;
    else
      x = rnd() % vmax + 1;
    if (op == 4) y = rnd() % vmax + 1;
    switch (op) {
      case 1:
        ODT::add(l, r, x);
        break;
      case 2:
        ODT::assign(l, r, x);
        break;
      case 3:
        std::cout << ODT::rnk(l, r, x) << '\n';
        break;
      case 4:
        std::cout << ODT::query(l, r, x, y) << '\n';
    }
  }
  return 0;
}
