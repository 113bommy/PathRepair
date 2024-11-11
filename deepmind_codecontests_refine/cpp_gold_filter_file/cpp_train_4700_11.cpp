#include <bits/stdc++.h>
using namespace std;
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, a...);
}
mt19937 r(chrono::steady_clock::now().time_since_epoch().count());
long long rand_range(long long a, long long b) {
  assert(a <= b);
  return a + r() % (b - a + 1);
}
const long long K = 1000;
const long long KK = K * K;
const long long MIL = KK * K;
const long long INF = MIL * MIL;
const long long MOD = MIL + 7;
const long long N = 1e6 + 10;
vector<long long> G[N];
bool vis[N];
long long tim = 0;
pair<long long, long long> czas[N];
void dfs(long long x) {
  czas[x].first = tim++;
  vis[x] = true;
  for (long long i : G[x])
    if (!vis[i]) dfs(i);
  czas[x].second = tim - 1;
}
struct Node {
  Node() : Node(0){};
  Node(long long v) {
    val[0] = v;
    val[1] = 0;
  }
  Node(Node a, Node b) {
    val[0] = max(a.val[0], b.val[0]);
    val[1] = 0;
  }
  void take(Node node, long long len) {
    val[0] += node.val[1];
    val[1] += node.val[1];
  }
  void reset() { val[1] = 0; }
  void add(long long v, long long len) {
    val[0] += v;
    val[1] += v;
  }
  long long val[2];
};
template <typename Nod, typename Vobj>
struct RangeRangeTree {
  long long base;
  vector<Nod> drz;
  vector<bool> brud;
  RangeRangeTree(Vobj &o) {
    base = 1;
    while (base < (long long)((o).size())) base *= 2;
    drz.resize(2 * base);
    brud.resize(2 * base);
    for (long long i = ((0)); i <= (((long long)((o).size())) - 1); i++)
      drz[base + i] = Nod(o[i]);
    for (long long i = (base - 1); i >= (1); i--)
      drz[i] = Nod(drz[2 * i], drz[2 * i + 1]);
  }
  void czysc(long long x, long long len) {
    drz[2 * x].take(drz[x], len);
    drz[2 * x + 1].take(drz[x], len);
    drz[x].reset();
    brud[2 * x] = brud[2 * x + 1] = 1;
    brud[x] = 0;
  }
  void update(long long l, long long r, long long v, long long p, long long k,
              long long x) {
    if (r < p || l > k) return;
    if (l <= p && k <= r) {
      drz[x].add(v, k - p + 1);
      brud[x] = 1;
      return;
    }
    if (brud[x]) czysc(x, (k - p + 1) / 2);
    long long sr = (p + k) / 2;
    update(l, r, v, p, sr, 2 * x);
    update(l, r, v, sr + 1, k, 2 * x + 1);
    drz[x] = Nod(drz[2 * x], drz[2 * x + 1]);
  }
  void update(long long l, long long r, long long v) {
    update(l, r, v, 0, base - 1, 1);
  }
  Nod query(long long l, long long r, long long p, long long k, long long x) {
    if (r < p || l > k) return Node();
    if (l <= p && k <= r) {
      Nod pom = drz[x];
      return drz[x];
    }
    if (brud[x]) czysc(x, (k - p + 1) / 2);
    long long sr = (p + k) / 2;
    return Nod(query(l, r, p, sr, 2 * x), query(l, r, sr + 1, k, 2 * x + 1));
  }
  Nod query(long long l, long long r) { return query(l, r, 0, base - 1, 1); }
};
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n + 1);
  for (long long i = ((0)); i <= ((n)-1); i++) cin >> a[i];
  a[n] = MIL;
  vector<pair<long long, long long> > stos;
  stos.emplace_back(MIL, n);
  for (long long i = (n - 1); i >= (0); i--) {
    while (stos.back().first <= a[i]) stos.pop_back();
    G[i].emplace_back(stos.back().second);
    G[stos.back().second].emplace_back(i);
    stos.emplace_back(a[i], i);
  }
  dfs(n);
  vector<long long> vpom(n + 1, 0);
  struct RangeRangeTree<Node, vector<long long> > drz(vpom);
  for (long long i = ((0)); i <= ((k - 1) - 1); i++)
    drz.update(czas[i].first, czas[i].second, 1);
  for (long long i = ((k - 1)); i <= ((n)-1); i++) {
    drz.update(czas[i].first, czas[i].second, 1);
    cout << drz.drz[1].val[0] << " ";
    drz.update(czas[i - k + 1].first, czas[i - k + 1].second, -1);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cout << setprecision(9) << fixed;
  cerr << setprecision(6) << fixed;
  long long test = 1;
  while (test--) {
    solve();
  }
}
