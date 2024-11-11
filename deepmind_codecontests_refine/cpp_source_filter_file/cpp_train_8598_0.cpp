#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxheap = priority_queue<T>;
template <typename T>
using dpair = pair<T, T>;
template <class T1, class T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  return is >> p.first >> p.second;
}
template <class T1, class T2>
void operator+=(vector<T1> &v, const T2 &obj) {
  v.push_back(obj);
}
template <class T1>
void operator+=(vector<T1> &v, const T1 &obj) {
  v.push_back(obj);
}
long long get_millis() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch())
      .count();
}
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3fll;
const long long mod = 1e9 + 7;
class xrange {
 public:
  xrange(int end) : _start(0), _end(end), _step(1) {}
  xrange(int start, int end) : _start(start), _end(end), _step(1) {}
  xrange(int start, int end, int step)
      : _start(start), _end(end), _step(step) {}
  class iterator {
   public:
    iterator(int v, xrange &par) : val(v), parent(par){};
    int operator*() const { return val; }
    int operator++() { return (val += parent._step); }
    bool operator==(const xrange::iterator &iter) const {
      if (&parent != &iter.parent) {
        return false;
      }
      if (val == iter.val) {
        return true;
      }
      if (parent._step > 0) {
        return val >= parent._end && iter.val >= parent._end;
      } else {
        return val <= parent._end && iter.val <= parent._end;
      }
    }
    bool operator!=(const xrange::iterator &iter) const {
      return !(this->operator==(iter));
    }

   private:
    int val;
    xrange &parent;
  };
  xrange::iterator begin() { return {_start, *this}; }
  xrange::iterator end() { return {_end, *this}; }

 protected:
  int _start, _end, _step;

 private:
};
struct irange : xrange {
  irange(int l, int r) : xrange(l, r + 1) {}
  irange(int n) : xrange(1, n + 1) {}
};
const int MAXN = 1e6 + 5;
int N, Q;
vector<int> adj[MAXN];
int above[MAXN];
int dep[MAXN];
int maxdep[MAXN];
int hvson[MAXN];
int top[MAXN];
void dfs1(int pos) {
  hvson[pos] = -1;
  maxdep[pos] = dep[pos];
  for (int i : adj[pos]) {
    if (i != above[pos]) {
      above[i] = pos;
      dep[i] = dep[pos] + 1;
      dfs1(i);
      if (hvson[pos] == -1 || maxdep[i] > maxdep[hvson[pos]]) {
        hvson[pos] = i;
      }
      maxdep[pos] = max(maxdep[pos], maxdep[i]);
    }
  }
}
int cntid = 1;
int id[MAXN];
void dfs2(int pos, int tp) {
  top[pos] = tp;
  id[pos] = cntid++;
  if (hvson[pos] != -1) {
    dfs2(hvson[pos], tp);
  }
  for (int i : adj[pos]) {
    if (i != above[pos] && i != hvson[pos]) {
      dfs2(i, i);
    }
  }
}
int sparse[MAXN][20];
int query(int l, int r) {
  int logDist = log2(r - l + 1) - 1;
  return min(sparse[l][logDist], sparse[r - (1 << logDist) + 1][logDist]);
}
int tree = 1e9;
int black;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  dep[0] = -1;
  cin >> N >> Q;
  for (int a = 1; a < N; a++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  Q--;
  cin >> black;
  cin >> black;
  black = black % N + 1;
  dfs1(black);
  dfs2(black, black);
  for (int a = 1; a <= N; a++) {
    sparse[id[a]][0] = a;
  }
  for (int lvl = 1; lvl < 20; lvl++) {
    int jump = 1 << (lvl - 1);
    for (int a = 1; a <= N; a++) {
      sparse[a][lvl] = sparse[a][lvl - 1];
      if (a + jump <= N) {
        sparse[a][lvl] = min(sparse[a][lvl], sparse[a + jump][lvl - 1]);
      }
    }
  }
  tree = min(tree, query(id[black], id[black]));
  int last = 0;
  while (Q--) {
    int tp, x;
    cin >> tp >> x;
    x = (x + last) % N + 1;
    if (tp == 1) {
      int u = black, v = x;
      while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) {
          swap(u, v);
        }
        tree = min(tree, query(id[top[u]], id[u]));
        u = above[top[u]];
      }
      tree = min(tree, query(min(id[u], id[v]), max(id[u], id[v])));
    } else {
      last = tree;
      int u = black, v = x;
      while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) {
          swap(u, v);
        }
        last = min(last, query(id[top[u]], id[u]));
        u = above[top[u]];
      }
      last = min(last, query(min(id[u], id[v]), max(id[u], id[v])));
      cout << last << "\n";
    }
  }
}
