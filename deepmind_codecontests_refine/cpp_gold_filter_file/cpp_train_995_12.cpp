#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:512000000")
using namespace std;
void solve(bool);
void precalc();
clock_t start;
int testNumber = 1;
bool todo = true;
int main() {
  start = clock();
  int t = 1;
  cout.sync_with_stdio(0);
  cin.tie(0);
  precalc();
  cout.precision(10);
  cout << fixed;
  int testNum = 1;
  while (t--) {
    solve(true);
    ++testNumber;
  }
  return 0;
}
template <typename T>
T binpow(T q, T w, T mod) {
  if (!w) return 1 % mod;
  if (w & 1) return q * 1LL * binpow(q, w - 1, mod) % mod;
  return binpow(q * 1LL * q % mod, w / 2, mod);
}
template <typename T>
T gcd(T q, T w) {
  while (w) {
    q %= w;
    swap(q, w);
  }
  return q;
}
template <typename T>
T lcm(T q, T w) {
  return q / gcd(q, w) * w;
}
void precalc() {}
const long long C = 100500;
long long pr[2] = {234211, 23423541};
long long mods[2] = {1000000007, 1000000009};
long long powers[2][C];
class Treap {
 public:
  typedef struct _node {
    long long key;
    long long cnt;
    long long prior;
    long long val[2];
    _node* l;
    _node* r;
    _node(long long key) : key(key), l(nullptr), r(nullptr), cnt(1) {
      prior = (rand() << 16) | rand();
      val[0] = (key + 1);
      val[1] = (key + 1);
    }
    void push() {}
    void recalc() {
      cnt = 1 + Cnt(l) + Cnt(r);
      for (long long w = 0; w < 2; ++w) {
        val[w] = powers[w][Cnt(r)] * (key + 1) % mods[w];
        if (l) {
          val[w] += powers[w][Cnt(r) + 1] * l->val[w];
        }
        if (r) {
          val[w] += r->val[w];
        }
        val[w] %= mods[w];
      }
    }
    long long get_hash() { return (val[0] * 1LL << 32) | val[1]; }
    static long long Cnt(_node* v) {
      if (!v) return 0;
      return v->cnt;
    }
  } * node;
  static long long Cnt(node v) {
    if (!v) return 0;
    return v->cnt;
  }
  node root;
  size_t Size;
  node merge(node l, node r) {
    if (!l) return r;
    if (!r) return l;
    if (l->prior < r->prior) {
      l->push();
      l->r = merge(l->r, r);
      l->recalc();
      return l;
    } else {
      r->push();
      r->l = merge(l, r->l);
      r->recalc();
      return r;
    }
  }
  void split(node v, long long key, node& l, node& r) {
    l = r = nullptr;
    if (!v) return;
    v->push();
    if (v->key < key) {
      l = v;
      split(l->r, key, l->r, r);
      l->recalc();
    } else {
      r = v;
      split(r->l, key, l, r->l);
      r->recalc();
    }
  }
  void splitCnt(node v, long long key, node& l, node& r) {
    l = r = nullptr;
    if (!v) return;
    v->push();
    long long lef = Cnt(v->l) + 1;
    if (key >= lef) {
      l = v;
      splitCnt(l->r, key - lef, l->r, r);
      l->recalc();
    } else {
      r = v;
      splitCnt(r->l, key, l, r->l);
      r->recalc();
    }
  }

 public:
  Treap() {
    root = nullptr;
    Size = 0;
  }
  size_t size() const { return Size; }
  void insert(long long key) {
    node l = nullptr, r = nullptr;
    split(root, key, l, r);
    ++Size;
    root = merge(merge(l, new _node(key)), r);
  }
  void erase(long long key) {
    node l, m, r;
    split(root, key, l, m);
    splitCnt(m, 1, m, r);
    root = merge(l, r);
    --Size;
  }
  long long get_hash() {
    if (!root) {
      return 0;
    }
    return root->get_hash() ^ ((long long)Size * (1LL << 32)) ^ (long long)Size;
  }
};
vector<vector<long long>> g;
long long best_ans = 0;
long long best_v = -1;
map<long long, long long> trees;
map<long long, long long> cnt;
vector<long long> down;
vector<long long> subtree;
long long dfs1(long long v, long long p) {
  subtree[v] = 1;
  Treap children;
  for (long long to : g[v]) {
    if (to == p) {
      continue;
    }
    long long child = dfs1(to, v);
    children.insert(child);
    subtree[v] += subtree[to];
  }
  long long cur = children.get_hash() ^ subtree[v];
  if (!trees.count(cur)) {
    long long id = (long long)trees.size();
    trees[cur] = id;
  }
  cur = trees[cur];
  ++cnt[cur];
  down[v] = cur;
  return cur;
}
vector<vector<long long>> hashes;
void dec(long long cur) {
  --cnt[cur];
  if (cnt[cur] == 0) {
    cnt.erase(cur);
  }
}
void inc(long long cur) { ++cnt[cur]; }
long long n;
void dfs2(long long v, long long p, long long up) {
  long long cand = (long long)cnt.size() + 1;
  if (best_ans < cand || best_ans == cand && v < best_v) {
    best_ans = cand;
    best_v = v;
  }
  Treap cur;
  if (up != -1) {
    cur.insert(up);
  }
  for (long long to : g[v]) {
    if (to == p) {
      continue;
    }
    cur.insert(down[to]);
  }
  for (long long to : g[v]) {
    if (to == p) {
      continue;
    }
    dec(down[to]);
    cur.erase(down[to]);
    long long now = cur.get_hash() ^ (n - subtree[to]);
    long long id;
    if (!trees.count(now)) {
      id = (long long)trees.size();
      trees[now] = id;
    } else {
      id = trees[now];
    }
    inc(id);
    dfs2(to, v, id);
    cur.insert(down[to]);
    inc(down[to]);
    dec(id);
  }
}
void solve(bool read) {
  for (long long w = 0; w < 2; ++w) {
    powers[w][0] = 1;
    for (long long i = 1; i < C; ++i) {
      powers[w][i] = powers[w][i - 1] * pr[w] % mods[w];
    }
  }
  cin >> n;
  g.resize(n);
  for (long long i = 1; i < n; ++i) {
    long long a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  down.resize(n);
  subtree.resize(n);
  dfs1(0, 0);
  hashes.resize(n);
  dec(down[0]);
  dfs2(0, 0, -1);
  cout << best_v + 1 << "\n";
}
