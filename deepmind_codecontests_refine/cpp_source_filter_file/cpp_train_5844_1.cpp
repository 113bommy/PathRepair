#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int STALPH = 26;
struct STNode {
  char *s;
  int len;
  int childs[STALPH];
  int suffix;
  STNode(char *s, int len) : s(s), len(len) {
    memset(childs, -1, sizeof(childs));
    suffix = -1;
  }
};
struct SuffixTree {
  int root;
  vector<STNode> nodes;
  int addnode(char *s, int len) {
    nodes.push_back(STNode(s, len));
    return ((int)(nodes).size()) - 1;
  }
  vector<int> build(char *s) {
    nodes.clear();
    root = addnode(NULL, 0);
    int n = strlen(s), atnode = root, atedge = 0, atlen = 0, pint = -1,
        pleaf = -1;
    for (int i = (0); i <= (n); ++i) {
      while (true) {
        int tonode = atedge == n ? -1 : nodes[atnode].childs[s[atedge] - 'a'];
        if (tonode != -1 && atlen >= nodes[tonode].len) {
          atedge += nodes[tonode].len;
          atlen -= nodes[tonode].len;
          atnode = tonode;
          continue;
        }
        if (tonode == -1) {
          if (i != n) {
            int leaf = addnode(s + i, n - i);
            nodes[atnode].childs[nodes[leaf].s[0] - 'a'] = leaf;
            if (pleaf != -1) nodes[pleaf].suffix = leaf;
            pleaf = leaf;
          } else {
            if (pleaf != -1) nodes[pleaf].suffix = atnode;
            pleaf = -1;
          }
          if (pint != -1) nodes[pint].suffix = atnode;
          pint = -1;
        } else if (i == n || nodes[tonode].s[atlen] != s[i]) {
          int branch = addnode(nodes[tonode].s, atlen);
          nodes[tonode].s += atlen, nodes[tonode].len -= atlen;
          nodes[atnode].childs[nodes[branch].s[0] - 'a'] = branch;
          nodes[branch].childs[nodes[tonode].s[0] - 'a'] = tonode;
          if (i != n) {
            int leaf = addnode(s + i, n - i);
            nodes[branch].childs[nodes[leaf].s[0] - 'a'] = leaf;
            if (pleaf != -1) nodes[pleaf].suffix = leaf;
            pleaf = leaf;
          } else {
            if (pleaf != -1) nodes[pleaf].suffix = branch;
            pleaf = -1;
          }
          if (pint != -1) nodes[pint].suffix = branch;
          pint = branch;
        } else {
          if (pint != -1) assert(atlen == 0), nodes[pint].suffix = atnode;
          pint = -1;
          ++atlen;
          break;
        }
        if (atnode == root) {
          atedge++;
          if (atlen == 0) {
            assert(pint == -1);
            break;
          } else
            --atlen;
        } else {
          atnode = nodes[atnode].suffix;
        }
      }
    }
    vector<int> ret(n + 1, -1);
    for (int at = 1, len = n; at != -1; at = nodes[at].suffix, --len)
      ret[len] = at;
    return ret;
  }
  void print(int at, int depth = 0) {
    for (int i = (0); i < (depth); ++i) printf("  ");
    if (nodes[at].s == NULL)
      printf("<root>");
    else
      printf("'%.*s'", nodes[at].len, nodes[at].s);
    printf(": id=%d", at);
    if (nodes[at].suffix != -1) printf(" suffix=%d", nodes[at].suffix);
    puts("");
    for (int i = (0); i < (STALPH); ++i)
      if (nodes[at].childs[i] != -1) print(nodes[at].childs[i], depth + 1);
  }
};
struct TNode {
  vector<int> ch;
  int parlen;
  int sz, heavy, par, pathid, pathidx, rootlen;
};
struct Tree {
  int root;
  vector<TNode> nodes;
};
struct HLPath {
  vector<int> nodes;
};
struct HeavyLight {
  Tree *t;
  vector<int> prelst;
  vector<HLPath> paths;
  void dfspre(int at) {
    prelst.push_back(at);
    for (int i = (0); i < (((int)(t->nodes[at].ch).size())); ++i)
      dfspre(t->nodes[at].ch[i]);
  }
  void build(Tree *_t) {
    t = _t;
    prelst.clear();
    dfspre(t->root);
    for (int i = ((int)(prelst).size()) - 1; i >= 0; --i) {
      int at = prelst[i];
      t->nodes[at].sz = 1, t->nodes[at].heavy = -1, t->nodes[at].par = -1;
      for (int j = (0); j < (((int)(t->nodes[at].ch).size())); ++j) {
        int to = t->nodes[at].ch[j];
        t->nodes[to].par = at;
        t->nodes[at].sz += t->nodes[to].sz;
        if (t->nodes[at].heavy == -1 ||
            t->nodes[to].sz > t->nodes[t->nodes[at].heavy].sz)
          t->nodes[at].heavy = to;
      }
    }
    paths.clear();
    for (int i = (0); i < (((int)(prelst).size())); ++i) {
      int at = prelst[i];
      t->nodes[at].rootlen =
          t->nodes[at].par == -1
              ? 0
              : t->nodes[t->nodes[at].par].rootlen + t->nodes[at].parlen;
      if (t->nodes[at].par != -1 && t->nodes[t->nodes[at].par].heavy == at)
        continue;
      HLPath path;
      for (int x = at; x != -1; x = t->nodes[x].heavy)
        t->nodes[x].pathid = ((int)(paths).size()),
        t->nodes[x].pathidx = ((int)(path.nodes).size()),
        path.nodes.push_back(x);
      paths.push_back(path);
    }
  }
  vector<pair<int, int>> decomposepathtoroot(int at) {
    vector<pair<int, int>> ret;
    while (at != -1) {
      ret.push_back(make_pair(t->nodes[at].pathid, t->nodes[at].pathidx));
      at = t->nodes[paths[t->nodes[at].pathid].nodes[0]].par;
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
  void print() {
    for (int i = (0); i < (((int)(paths).size())); ++i) {
      printf("path%d:", i);
      for (int j = (0); j < (((int)(paths[i].nodes).size())); ++j)
        printf(" %d", paths[i].nodes[j]);
      puts("");
    }
  }
};
const int MAXLEN = 200000;
const int MAXQ = 200000;
char s[MAXLEN + 1];
int slen;
int nq;
int ql[MAXQ], qr[MAXQ];
long long qans[MAXQ];
SuffixTree sufftree;
vector<int> suffixids;
Tree t;
HeavyLight heavylight;
struct BIT {
  int n;
  pair<int, long long> all;
  vector<pair<int, long long>> bit;
  BIT(int _n) {
    n = _n;
    all = make_pair(0, 0LL);
    bit = vector<pair<int, long long>>(n + 1, make_pair(0, 0LL));
  }
  void mod(int idx, int a, long long b) {
    all.first += a;
    all.second += b;
    ++idx;
    while (idx <= n) {
      bit[idx].first += a;
      bit[idx].second += b;
      idx += idx & -idx;
    }
  }
  pair<int, long long> get(int idx) {
    pair<int, long long> ret = make_pair(0, 0LL);
    ++idx;
    while (idx > 0) {
      ret.first += bit[idx].first;
      ret.second += bit[idx].second;
      idx -= idx & -idx;
    }
    return ret;
  }
};
struct P {
  int id, pathidx, len;
  P(int id, int pathidx, int len) : id(id), pathidx(pathidx), len(len) {}
};
struct Q {
  int id, pathidx, len;
  Q(int id, int pathidx, int len) : id(id), pathidx(pathidx), len(len) {}
};
struct E {
  int kind, id, pathidx, key, val;
  E(int kind, int id, int pathidx, int key, int val)
      : kind(kind), id(id), pathidx(pathidx), key(key), val(val) {}
};
bool operator<(const E &a, const E &b) {
  if (a.key != b.key) return a.key < b.key;
  return a.kind < b.kind;
}
void solve() {
  suffixids = sufftree.build(s);
  t.nodes.clear();
  t.root = sufftree.root;
  for (int i = (0); i < (((int)(sufftree.nodes).size())); ++i) {
    TNode tnode;
    tnode.parlen = sufftree.nodes[i].len;
    for (int j = (0); j < (STALPH); ++j)
      if (sufftree.nodes[i].childs[j] != -1)
        tnode.ch.push_back(sufftree.nodes[i].childs[j]);
    t.nodes.push_back(tnode);
  }
  heavylight.build(&t);
  vector<vector<int>> qlst(((int)(t.nodes).size()));
  for (int i = (0); i < (nq); ++i) qlst[suffixids[slen - ql[i]]].push_back(i);
  vector<vector<int>> plst(((int)(t.nodes).size()));
  for (int i = (0); i < (slen); ++i) plst[suffixids[slen - i]].push_back(i);
  queue<int> q;
  for (int pathid = (0); pathid < (((int)(heavylight.paths).size()));
       ++pathid) {
    int firstnode = heavylight.paths[pathid].nodes[0],
        h = t.nodes[firstnode].rootlen - t.nodes[firstnode].parlen,
        pathlen = ((int)(heavylight.paths[pathid].nodes).size());
    vector<int> dep(pathlen);
    for (int i = (0); i < (pathlen); ++i)
      dep[i] = t.nodes[heavylight.paths[pathid].nodes[i]].rootlen;
    vector<P> curp;
    vector<Q> curq;
    for (int pathidx = (0); pathidx < (pathlen); ++pathidx) {
      q.push(heavylight.paths[pathid].nodes[pathidx]);
      while (!q.empty()) {
        int at = q.front();
        q.pop();
        for (int i = (0); i < (((int)(qlst[at]).size())); ++i) {
          int id = qlst[at][i];
          if (h >= qr[id] - ql[id] + 1) continue;
          int lo = 0, hi = pathidx + 1;
          while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (dep[mi - 1] >= qr[id] + ql[id])
              hi = mi;
            else
              lo = mi;
          }
          curq.push_back(Q(id, lo, min(qr[id] - ql[id] + 1, dep[lo])));
        }
        for (int i = (0); i < (((int)(plst[at]).size())); ++i)
          curp.push_back(P(plst[at][i], pathidx, dep[pathidx]));
        for (int i = (0); i < (((int)(t.nodes[at].ch).size())); ++i) {
          int to = t.nodes[at].ch[i];
          if (pathidx + 1 >= pathlen ||
              to != heavylight.paths[pathid].nodes[pathidx + 1])
            q.push(to);
        }
      }
    }
    {
      vector<E> e;
      for (int i = (0); i < (((int)(curp).size())); ++i) {
        int id = curp[i].id, pathidx = curp[i].pathidx, len = curp[i].len;
        e.push_back(E(0, id, pathidx, id + h, -(id + h)));
      }
      for (int i = (0); i < (((int)(curq).size())); ++i) {
        int id = curq[i].id, pathidx = curq[i].pathidx, len = curq[i].len;
        e.push_back(E(1, id, pathidx, qr[id] + 1, +(qr[id] + 1)));
      }
      sort(e.begin(), e.end());
      BIT bit(pathlen);
      for (int i = (0); i < (((int)(e).size())); ++i) {
        if (e[i].kind == 0) {
          bit.mod(e[i].pathidx, +1, e[i].val);
          continue;
        }
        pair<int, long long> pref = bit.get(e[i].pathidx - 1), all = bit.all;
        qans[e[i].id] += (long long)e[i].val * all.first + all.second;
      }
    }
    {
      vector<E> e;
      for (int i = (0); i < (((int)(curp).size())); ++i) {
        int id = curp[i].id, pathidx = curp[i].pathidx, len = curp[i].len;
        e.push_back(E(0, id, pathidx, id + len, +(id + len)));
      }
      for (int i = (0); i < (((int)(curq).size())); ++i) {
        int id = curq[i].id, pathidx = curq[i].pathidx, len = curq[i].len;
        e.push_back(E(1, id, pathidx, qr[id] + 1, -(qr[id] + 1)));
      }
      sort(e.begin(), e.end());
      BIT bit(pathlen);
      for (int i = (0); i < (((int)(e).size())); ++i) {
        if (e[i].kind == 0) {
          bit.mod(e[i].pathidx, +1, e[i].val);
          continue;
        }
        pair<int, long long> pref = bit.get(e[i].pathidx - 1), all = bit.all;
        qans[e[i].id] += (long long)e[i].val * pref.first + pref.second;
      }
    }
    {
      vector<E> e;
      for (int i = (0); i < (((int)(curp).size())); ++i) {
        int id = curp[i].id, pathidx = curp[i].pathidx, len = curp[i].len;
        e.push_back(E(0, id, pathidx, id, +(id)));
      }
      for (int i = (0); i < (((int)(curq).size())); ++i) {
        int id = curq[i].id, pathidx = curq[i].pathidx, len = curq[i].len;
        e.push_back(E(1, id, pathidx, qr[id] + 1 - len, -(qr[id] + 1 - len)));
      }
      sort(e.begin(), e.end());
      BIT bit(pathlen);
      for (int i = (0); i < (((int)(e).size())); ++i) {
        if (e[i].kind == 0) {
          bit.mod(e[i].pathidx, +1, e[i].val);
          continue;
        }
        pair<int, long long> pref = bit.get(e[i].pathidx - 1), all = bit.all;
        qans[e[i].id] += (long long)e[i].val * (all.first - pref.first) +
                         (all.second - pref.second);
      }
    }
    {
      vector<E> e;
      for (int i = (0); i < (((int)(curp).size())); ++i) {
        int id = curp[i].id, pathidx = curp[i].pathidx, len = curp[i].len;
        e.push_back(E(0, id, pathidx, id, +(len)));
      }
      for (int i = (0); i < (((int)(curq).size())); ++i) {
        int id = curq[i].id, pathidx = curq[i].pathidx, len = curq[i].len;
        e.push_back(E(1, id, pathidx, ql[id] - 1, -(len)));
      }
      sort(e.begin(), e.end());
      BIT bit(pathlen);
      for (int i = (0); i < (((int)(e).size())); ++i) {
        if (e[i].kind == 0) {
          bit.mod(e[i].pathidx, +1, e[i].val);
          continue;
        }
        pair<int, long long> pref = bit.get(e[i].pathidx - 1), all = bit.all;
        qans[e[i].id] -= (long long)e[i].val * pref.first + pref.second +
                         (long long)(-e[i].val - h) * all.first;
      }
    }
  }
}
void run() {
  scanf("%s", s);
  slen = strlen(s);
  scanf("%d", &nq);
  for (int i = (0); i < (nq); ++i)
    scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
  solve();
  for (int i = (0); i < (nq); ++i) printf("%lld\n", qans[i]);
}
void stress() {
  std::mt19937 rng(
      (int)std::chrono::steady_clock::now().time_since_epoch().count());
  for (int rep = (0); rep < (10); ++rep) {
    slen = MAXLEN;
    for (int i = (0); i < (slen); ++i) s[i] = 'a' + rng() % 2;
    s[slen] = '\0';
    nq = MAXQ;
    for (int i = (0); i < (nq); ++i) {
      ql[i] = rng() % slen, qr[i] = rng() % slen;
      if (ql[i] > qr[i]) swap(ql[i], qr[i]);
    }
    solve();
    printf(".");
  }
}
int main() {
  run();
  return 0;
}
