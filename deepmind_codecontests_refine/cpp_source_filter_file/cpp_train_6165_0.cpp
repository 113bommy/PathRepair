#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
struct IndependentSet {
  int n;
  vector<bool> alive;
  void init() {
    n = 0;
    alive.clear();
  }
  void additem() {
    ++n;
    alive.push_back(false);
  }
  void update(vector<int> path) {
    for (int i = (0); i < (((int)(path).size())); ++i)
      alive[path[i]] = !alive[path[i]];
  }
};
struct Oracle {
  virtual bool canAdd(int x) = 0;
  virtual vector<int> getReplacements(int x) = 0;
  virtual vector<int> getConflicts(int x) = 0;
  virtual void remove(int x) = 0;
  virtual void add(int x) = 0;
  void update(vector<int> path) {
    assert(((int)(path).size()) % 2 == 1);
    for (int i = 1; i < ((int)(path).size()); i += 2) remove(path[i]);
    for (int i = 0; i < ((int)(path).size()); i += 2) add(path[i]);
  }
};
struct GraphicOracle : Oracle {
  int n;
  vector<pair<int, int>> edges;
  vector<vector<int>> options;
  vector<vector<int>> adj;
  void init(int _n) {
    n = _n;
    edges.clear();
    options = adj = vector<vector<int>>(n);
  }
  void additem(int a, int b) {
    options[a].push_back(((int)(edges).size()));
    options[b].push_back(((int)(edges).size()));
    edges.push_back(make_pair(a, b));
  }
  vector<int> bfs(int s, int skip = -1) {
    vector<int> ret(n, -1);
    queue<int> q;
    ret[s] = -2, q.push(s);
    while (!q.empty()) {
      int at = q.front();
      q.pop();
      for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
        int x = adj[at][i];
        if (x == skip) continue;
        int to = edges[x].first ^ edges[x].second ^ at;
        if (ret[to] == -1) ret[to] = x, q.push(to);
      }
    }
    return ret;
  }
  virtual bool canAdd(int x) {
    return bfs(edges[x].first)[edges[x].second] == -1;
  }
  virtual vector<int> getReplacements(int x) {
    vector<int> via1 = bfs(edges[x].first, x);
    vector<int> via2 = bfs(edges[x].second, x);
    vector<int> ret;
    for (int at = (0); at < (n); ++at)
      if (via1[at] != -1)
        for (int i = (0); i < (((int)(options[at]).size())); ++i) {
          int y = options[at][i];
          int to = edges[y].first ^ edges[y].second ^ at;
          if (y != x && via2[to] != -1) ret.push_back(y);
        }
    return ret;
  }
  virtual vector<int> getConflicts(int x) {
    vector<int> via = bfs(edges[x].first);
    vector<int> ret;
    int at = edges[x].second;
    while (true) {
      int x = via[at];
      if (x < 0) break;
      ret.push_back(x);
      at = edges[x].first ^ edges[x].second ^ at;
    }
    return ret;
  }
  virtual void remove(int x) {
    vector<int> &lst1 = adj[edges[x].first];
    lst1.erase(std::remove(lst1.begin(), lst1.end(), x), lst1.end());
    vector<int> &lst2 = adj[edges[x].second];
    lst2.erase(std::remove(lst2.begin(), lst2.end(), x), lst2.end());
  }
  virtual void add(int x) {
    adj[edges[x].first].push_back(x);
    adj[edges[x].second].push_back(x);
  }
};
struct PartitionOracle : Oracle {
  int npart;
  vector<bool> alive;
  vector<int> part;
  vector<vector<int>> options;
  vector<vector<int>> contents;
  vector<int> limit;
  void init(int _npart, int _limit) {
    npart = _npart;
    alive.clear();
    part.clear();
    options = contents = vector<vector<int>>(npart);
    limit = vector<int>(npart, _limit);
  }
  void additem(int p) {
    alive.push_back(false);
    if (p != -1) options[p].push_back(((int)(part).size()));
    part.push_back(p);
  }
  virtual bool canAdd(int x) {
    return part[x] == -1 || ((int)(contents[part[x]]).size()) < limit[part[x]];
  }
  virtual vector<int> getReplacements(int x) {
    vector<int> ret;
    if (part[x] != -1)
      for (int i = (0); i < (((int)(options[part[x]]).size())); ++i) {
        int y = options[part[x]][i];
        if (!alive[y]) ret.push_back(y);
      }
    return ret;
  }
  virtual vector<int> getConflicts(int x) {
    assert(part[x] != -1 &&
           ((int)(contents[part[x]]).size()) == limit[part[x]]);
    return contents[part[x]];
  }
  virtual void remove(int x) {
    alive[x] = false;
    if (part[x] != -1) {
      vector<int> &lst = contents[part[x]];
      lst.erase(std::remove(lst.begin(), lst.end(), x), lst.end());
    }
  }
  virtual void add(int x) {
    alive[x] = true;
    if (part[x] != -1) contents[part[x]].push_back(x);
  }
};
void intersect(IndependentSet &ground, Oracle &a, Oracle &b) {
  int n = ground.n;
  while (true) {
    vector<int> prv(n, -1);
    queue<int> q;
    for (int x = (0); x < (n); ++x)
      if (!ground.alive[x] && a.canAdd(x)) prv[x] = -2, q.push(x);
    int end = -1;
    while (!q.empty()) {
      int at = q.front();
      q.pop();
      if (!ground.alive[at]) {
        if (b.canAdd(at)) {
          end = at;
          break;
        }
        vector<int> opt = b.getConflicts(at);
        for (int i = (0); i < (((int)(opt).size())); ++i) {
          int to = opt[i];
          if (prv[to] == -1) prv[to] = at, q.push(to);
        }
      } else {
        vector<int> opt = a.getReplacements(at);
        for (int i = (0); i < (((int)(opt).size())); ++i) {
          int to = opt[i];
          if (prv[to] == -1) prv[to] = at, q.push(to);
        }
      }
    }
    if (end == -1) break;
    vector<int> path;
    for (int x = end; x != -2; x = prv[x]) path.push_back(x);
    reverse(path.begin(), path.end());
    ground.update(path), a.update(path), b.update(path);
  }
}
const int MAXH = 20;
const int MAXW = 20;
const int DX[] = {0, +1, 0, -1}, DY[] = {+1, 0, -1, 0};
int h, w;
char g[MAXH][MAXW + 1];
char ans[2 * MAXH - 1][2 * MAXW - 1 + 1];
int cellid[MAXH][MAXW], ncellid;
int blackid[MAXH][MAXW], nblackid;
vector<pair<int, int>> invcellid;
int ufpar[MAXH * MAXW], ufsz[MAXH * MAXW];
int uffind(int x) {
  if (ufpar[x] == x) return x;
  return ufpar[x] = uffind(ufpar[x]);
}
bool ufunite(int x, int y) {
  x = uffind(x), y = uffind(y);
  if (x == y) return false;
  if (ufsz[x] < ufsz[y]) swap(x, y);
  ufpar[y] = x, ufsz[x] += ufsz[y];
  return true;
}
IndependentSet ground;
GraphicOracle a;
PartitionOracle b;
bool solve() {
  for (int x = (0); x < (h); ++x)
    for (int y = (0); y < (w); ++y) cellid[x][y] = blackid[x][y] = -1;
  invcellid.clear();
  ncellid = 0;
  for (int x = (0); x < (h); ++x)
    for (int y = (0); y < (w); ++y)
      if (g[x][y] != 'X')
        cellid[x][y] = ncellid++, invcellid.push_back(make_pair(x, y));
  nblackid = 0;
  for (int x = (0); x < (h); ++x)
    for (int y = (0); y < (w); ++y)
      if (g[x][y] != 'X' && (x + y) % 2 == 0) blackid[x][y] = nblackid++;
  ground.init();
  a.init(ncellid);
  b.init(nblackid, 2);
  b.limit[blackid[0][0]] = 0;
  for (int x = (0); x < (h); ++x)
    for (int y = (0); y < (w); ++y)
      for (int k = (0); k < (2); ++k) {
        int nx = x + DX[k], ny = y + DY[k];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (g[x][y] == 'X' || g[nx][ny] == 'X') continue;
        ground.additem();
        a.additem(cellid[x][y], cellid[nx][ny]);
        if (blackid[x][y] != -1)
          b.additem(blackid[x][y]);
        else if (blackid[nx][ny] != -1)
          b.additem(blackid[nx][ny]);
        else
          b.additem(-1);
      }
  intersect(ground, a, b);
  int have = 0;
  for (int i = (0); i < (ground.n); ++i)
    if (ground.alive[i]) ++have;
  int want = 2 * (nblackid - 1);
  if (have < want) return false;
  for (int x = (0); x < (2 * h - 1); ++x) {
    for (int y = (0); y < (2 * w - 1); ++y) ans[x][y] = ' ';
    ans[x][2 * w] = '\0';
  }
  for (int x = (0); x < (h); ++x)
    for (int y = (0); y < (w); ++y) ans[2 * x][2 * y] = g[x][y];
  for (int i = (0); i < (ncellid); ++i) ufpar[i] = i, ufsz[i] = 1;
  for (int it = (0); it < (2); ++it) {
    for (int i = (0); i < (ground.n); ++i) {
      int u = a.edges[i].first, v = a.edges[i].second;
      if (it == 0 && !ground.alive[i]) continue;
      if (it == 1 && uffind(u) == uffind(v)) continue;
      assert(ufunite(u, v));
      int x1 = invcellid[u].first, y1 = invcellid[u].second;
      int x2 = invcellid[v].first, y2 = invcellid[v].second;
      if (x1 == x2) {
        assert(y2 == y1 + 1);
        ans[2 * x1][2 * y1 + 1] = 'O';
      } else {
        assert(x2 == x1 + 1 && y1 == y2);
        ans[2 * x1 + 1][2 * y1] = 'O';
      }
    }
  }
  return true;
}
void run() {
  scanf("%d%d", &h, &w);
  for (int x = (0); x < (h); ++x) scanf("%s", g[x]);
  if (!solve()) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  for (int x = (0); x < (2 * h - 1); ++x) printf("%s\n", ans[x]);
}
int main() {
  int ncase;
  scanf("%d", &ncase);
  for (int i = (1); i <= (ncase); ++i) run();
  return 0;
}
