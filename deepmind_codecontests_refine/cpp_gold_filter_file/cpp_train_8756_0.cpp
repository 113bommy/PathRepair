#include <bits/stdc++.h>
using namespace std;
const int NMAX = 200010;
int n;
namespace Arb {
int rmq[20][2 * NMAX + 10];
vector<int> adia[NMAX + 10];
int h[NMAX + 10];
int f_ap[NMAX + 10], l_ap[NMAX + 10], cnt;
int lgr[2 * NMAX + 10];
void dfs(int nod) {
  f_ap[nod] = l_ap[nod] = ++cnt;
  rmq[0][f_ap[nod]] = nod;
  for (auto i : adia[nod]) {
    h[i] = 1 + h[nod];
    dfs(i);
    l_ap[nod] = ++cnt;
    rmq[0][cnt] = nod;
  }
}
void build_rmq() {
  for (int i = 2; i <= cnt; i++) lgr[i] = 1 + lgr[i / 2];
  for (int i = 1; i < 20; i++)
    for (int j = 1; j + (1 << i) - 1 <= cnt; j++)
      rmq[i][j] = (h[rmq[i - 1][j]] < h[rmq[i - 1][j + (1 << (i - 1))]]
                       ? rmq[i - 1][j]
                       : rmq[i - 1][j + (1 << (i - 1))]);
}
int lca(int a, int b) {
  a = f_ap[a], b = f_ap[b];
  if (a > b) swap(a, b);
  int l = lgr[b - a + 1];
  a = rmq[l][a], b = rmq[l][b - (1 << l) + 1];
  return (h[a] < h[b] ? a : b);
}
int is_stramos(int a, int b) {
  if (f_ap[a] <= f_ap[b] && l_ap[a] >= l_ap[b]) return b;
  if (f_ap[b] <= f_ap[a] && l_ap[b] >= l_ap[a]) return a;
  return 0;
}
}  // namespace Arb
int poz[NMAX + 10];
int perm[NMAX + 10];
namespace Path {
struct Lant {
  bool ok;
  int lca, a, b;
} fals({0, 0, 0, 0});
Lant operator+(Lant a, Lant b) {
  if (a.a == a.lca) swap(a.a, a.b);
  if (b.a == b.lca) swap(b.a, b.b);
  if (a.b == a.lca) swap(a, b);
  if (!a.ok || !b.ok) return fals;
  if (a.b == a.lca && b.b == b.lca) {
    if (int x = Arb::is_stramos(a.a, b.a)) {
      int lca = Arb::lca(a.lca, b.lca);
      return {1, lca, x, lca};
    }
    int lca = Arb::lca(a.a, b.a);
    if (lca != Arb::lca(a.lca, b.lca)) return fals;
    return {1, lca, a.a, b.a};
  }
  if (b.b == b.lca) {
    int x = Arb::is_stramos(a.a, b.a);
    int y = Arb::is_stramos(a.b, b.a);
    int lca = Arb::lca(a.lca, b.lca);
    if (lca == a.lca && x) return {1, a.lca, x, a.b};
    if (lca == a.lca && y) return {1, a.lca, a.a, y};
    return fals;
  }
  for (int c = 0; c <= 1; c++) {
    swap(a.a, a.b);
    int x = Arb::is_stramos(a.a, b.a);
    int y = Arb::is_stramos(a.b, b.b);
    if (x && y && Arb::lca(b.a, b.b) == a.lca) return {1, a.lca, x, y};
  }
  return fals;
}
Lant aint[4 * NMAX + 10], ans;
int val, until;
void update(int nod, int st, int dr) {
  if (st > val || dr < val) return;
  if (st == dr) {
    aint[nod] = {1, poz[val], poz[val], poz[val]};
    return;
  }
  update(2 * nod, st, (st + dr) / 2);
  update(2 * nod + 1, (st + dr) / 2 + 1, dr);
  aint[nod] = aint[2 * nod] + aint[2 * nod + 1];
}
bool query(int nod, int st, int dr) {
  auto x = ans + aint[nod];
  if (x.ok) {
    until = dr;
    ans = x;
    return true;
  }
  if (st != dr && query(2 * nod, st, (st + dr) / 2))
    query(2 * nod + 1, (st + dr) / 2 + 1, dr);
  return false;
}
}  // namespace Path
int query() {
  Path::ans = {1, poz[0], poz[0], poz[0]};
  Path::until = 0;
  Path::query(1, 0, n);
  return Path::until + 1;
}
void update(int a, int b) {
  swap(perm[a], perm[b]);
  poz[perm[a]] = a;
  poz[perm[b]] = b;
  Path::val = perm[a];
  Path::update(1, 0, n);
  Path::val = perm[b];
  Path::update(1, 0, n);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> perm[i];
    poz[perm[i]] = i;
  }
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    Arb::adia[x].push_back(i);
  }
  Arb::dfs(1);
  Arb::build_rmq();
  for (int i = 0; i < n; i++) {
    Path::val = i;
    Path::update(1, 0, n);
  }
  int nrop, t, a, b;
  cin >> nrop;
  while (nrop--) {
    cin >> t;
    if (t == 2)
      cout << query() << '\n';
    else {
      cin >> a >> b;
      update(a, b);
    }
  }
  return 0;
}
