#include <bits/stdc++.h>
using namespace std;
int n, paths;
unsigned long long a, b, c;
vector<int> Paths[200005];
vector<pair<int, int>> G[200005];
int Heavy[200005], In[200005], PathP[200005], ParentE[200005], Which[200005],
    D[200005], Pos[200005];
unsigned long long Cost[200005];
void dfs(int node) {
  Heavy[node] = 1;
  int best = 0, choose = -1;
  for (auto e : G[node]) {
    int vec = e.first;
    if (!Heavy[vec]) {
      D[vec] = D[node] + 1;
      ParentE[vec] = e.second;
      Which[e.second] = vec;
      dfs(vec);
      Heavy[node] += Heavy[vec];
      PathP[In[vec]] = node;
      if (best < Heavy[vec]) {
        best = Heavy[vec];
        choose = In[vec];
      }
    }
  }
  if (choose == -1) choose = ++paths;
  In[node] = choose;
  Paths[In[node]].push_back(node);
}
const unsigned long long MAXX = 2e18;
unsigned long long inm(unsigned long long a, unsigned long long b) {
  if (a == 0 || b == 0) return 0;
  unsigned long long r = a * b;
  if (r / a == b) return r;
  return MAXX;
}
struct ArbInt {
  vector<unsigned long long> T;
  int n;
  void _init(int node, int b, int e, int i) {
    if (b == e) {
      int where = Paths[i][b];
      T[node] = Cost[ParentE[where]];
    } else {
      int m = b + e >> 1;
      _init(node * 2, b, m, i);
      _init(node * 2 + 1, m + 1, e, i);
      T[node] = inm(T[node * 2], T[node * 2 + 1]);
    }
  }
  void init(int sz, int i) {
    T.resize(sz * 4);
    n = sz;
    _init(1, 1, n, i);
  }
  void _upd(int node, int b, int e, int pos, unsigned long long val) {
    if (b == e) {
      T[node] = val;
    } else {
      int m = b + e >> 1;
      if (m >= pos)
        _upd(node * 2, b, m, pos, val);
      else
        _upd(node * 2 + 1, m + 1, e, pos, val);
      T[node] = inm(T[node * 2], T[node * 2 + 1]);
    }
  }
  void update(int pos, unsigned long long val) { _upd(1, 1, n, pos, val); }
  unsigned long long _qry(int node, int b, int e, int l, int r) {
    if (b > r || e < l) return 1LL;
    if (b >= l && e <= r) return T[node];
    int m = b + e >> 1;
    return inm(_qry(node * 2, b, m, l, r), _qry(node * 2 + 1, m + 1, e, l, r));
  }
  unsigned long long query(int l, int r) { return _qry(1, 1, n, l, r); }
};
ArbInt AI[200005];
void update(int node, unsigned long long val) {
  int where = In[node];
  AI[where].update(Pos[node], val);
}
unsigned long long query(int a, int b, unsigned long long x) {
  while (In[a] != In[b]) {
    if (D[PathP[In[a]]] > D[PathP[In[b]]]) {
      x /= AI[In[a]].query(1, Pos[a]);
      a = PathP[In[a]];
    } else {
      x /= AI[In[b]].query(1, Pos[b]);
      b = PathP[In[b]];
    }
    if (x == 0LL) return 0LL;
  }
  if (a != b) {
    if (Pos[a] > Pos[b]) swap(a, b);
    x /= AI[In[a]].query(Pos[a] + 1, Pos[b]);
  }
  return x;
}
unsigned long long Read() {
  char c;
  unsigned long long a = 0;
  for (c = getchar(); !isdigit(c); c = getchar())
    ;
  for (; isdigit(c); c = getchar()) a = (a << 1LL) + (a << 3LL) + c - '0';
  return a;
}
void w(unsigned long long a) {
  if (a != 0) {
    w(a / 10);
    putchar(a % 10 + '0');
  }
}
void Write(unsigned long long a) {
  if (a == 0) {
    putchar('0');
  } else {
    w(a);
  }
  putchar('\n');
}
int main() {
  int n, m;
  n = Read();
  m = Read();
  for (int i = 1; i < n; i++) {
    a = Read();
    b = Read();
    c = Read();
    G[a].push_back({b, i});
    G[b].push_back({a, i});
    Cost[i] = c;
  }
  D[0] = -1;
  srand(time(0));
  int root = rand() % n + 1;
  dfs(root);
  PathP[In[root]] = 0;
  Cost[0] = 1;
  for (int i = 1; i <= paths; i++) {
    auto &curp = Paths[i];
    curp.push_back(0);
    reverse(curp.begin(), curp.end());
    for (int i = 1; i < curp.size(); i++) {
      Pos[curp[i]] = i;
    }
    AI[i].init(curp.size() - 1, i);
  }
  unsigned long long t;
  while (m--) {
    t = Read();
    a = Read();
    b = Read();
    if (t == 1) {
      c = Read();
      Write(query(a, b, c));
    } else {
      update(Which[a], b);
    }
  }
  return 0;
}
