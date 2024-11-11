#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void Read(T &x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}
template <typename T>
inline bool CheckMax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}
template <typename T>
inline bool CheckMin(T &a, const T &b) {
  return a > b ? a = b, true : false;
}
const int N = 100005;
struct Graph {
  set<pair<int, int> > all, edg, lef;
  set<int> ver, adj[N];
  int n, d[N];
  inline void AddEdge(int x, int y) {
    edg.insert(make_pair(x, y)), edg.insert(make_pair(y, x));
    adj[x].insert(y), adj[y].insert(x);
    ++d[x], ++d[y];
  }
  inline void Init() {
    for (int i = 1; i <= n; ++i) {
      ver.insert(i), all.insert(make_pair(d[i], i));
      if (d[i] == 1) {
        lef.insert(make_pair(*adj[i].begin(), i));
      }
    }
  }
  inline int Star() { return ver.size() - all.rbegin()->first - 1; }
  inline void Erase(int x) {
    int y = *adj[x].begin();
    ver.erase(x), lef.erase(make_pair(y, x)), all.erase(make_pair(1, x));
    adj[x].erase(y), adj[y].erase(x);
    all.erase(make_pair(d[y], y)), all.insert(make_pair(--d[y], y));
    if (d[y] == 1) {
      lef.insert(make_pair(*adj[y].begin(), y));
    }
  }
  inline pair<int, int> Leaves() {
    set<pair<int, int> > s;
    s.insert(*lef.begin()), s.insert(*++lef.begin());
    s.insert(*lef.rbegin()), s.insert(*++lef.rbegin());
    int big = -1;
    for (auto a : s) {
      if (d[a.first] > 2) {
        big = a.first;
        break;
      }
    }
    if (~big) {
      int x = -1, y = -1;
      for (auto a : s) {
        if (a.first == big) {
          x = a.second;
        } else {
          y = a.second;
        }
      }
      return make_pair(x, y);
    } else {
      return make_pair(lef.begin()->second, lef.rbegin()->second);
    }
  }
} G, H;
int n, ans[N], ret[N];
inline void SolveStar(Graph &G, Graph &H) {
  int u, v, w, uu, vv, ww;
  vector<int> g, h;
  u = G.all.rbegin()->second, v = *G.adj[u].begin(), w = *G.adj[u].rbegin();
  if (G.d[w] == 1) {
    swap(v, w);
  }
  ww = H.lef.begin()->second, vv = H.lef.begin()->first, uu = -1;
  for (auto x : H.ver) {
    if (H.edg.find(make_pair(x, vv)) == H.edg.end() &&
        H.edg.find(make_pair(x, ww)) == H.edg.end()) {
      uu = x;
      break;
    }
  }
  ans[u] = uu, ans[v] = vv, ans[w] = ww;
  for (auto x : G.ver) {
    if (x != u && x != v && x != w) {
      g.push_back(x);
    }
  }
  for (auto x : H.ver) {
    if (x != uu && x != vv && x != ww) {
      h.push_back(x);
    }
  }
  for (int i = 0; i < g.size(); ++i) {
    ans[g[i]] = h[i];
  }
}
inline void SolveBrute() {
  vector<int> g, h;
  int n = G.ver.size();
  for (auto x : G.ver) {
    g.push_back(x);
  }
  for (auto x : H.ver) {
    h.push_back(x);
  }
  do {
    bool flg = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (G.edg.find(make_pair(g[i], g[j])) != G.edg.end() &&
            H.edg.find(make_pair(h[i], h[j])) != H.edg.end()) {
          flg = false, i = j = n;
        }
      }
    }
    if (flg) {
      for (int i = 0; i < n; ++i) {
        ans[g[i]] = h[i];
      }
      return;
    }
  } while (next_permutation(g.begin(), g.end()));
  assert(false);
}
inline void Solve() {
  if (G.ver.size() <= 5) {
    SolveBrute();
  } else if (G.Star() == 1) {
    SolveStar(G, H);
  } else if (H.Star() == 1) {
    SolveStar(H, G);
    for (int i = 1; i <= n; ++i) {
      ret[ans[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
      ans[i] = ret[i];
    }
  } else {
    pair<int, int> a = G.Leaves(),
                   b = make_pair(*G.adj[a.first].begin(),
                                 *G.adj[a.second].begin()),
                   c = H.Leaves(),
                   d = make_pair(*H.adj[c.first].begin(),
                                 *H.adj[c.second].begin());
    G.Erase(a.first), G.Erase(a.second), H.Erase(c.first), H.Erase(c.second),
        Solve();
    if (ans[b.first] != d.first && ans[b.second] != d.second) {
      ans[a.first] = c.first, ans[a.second] = c.second;
    } else {
      ans[a.first] = c.second, ans[a.second] = c.first;
    }
  }
}
int main() {
  Read(n), G.n = H.n = n;
  for (int i = 1, x, y; i < n; ++i) {
    Read(x), Read(y), G.AddEdge(x, y);
  }
  for (int i = 1, x, y; i < n; ++i) {
    Read(x), Read(y), H.AddEdge(x - n, y - n);
  }
  G.Init(), H.Init();
  if (!G.Star() || !H.Star()) {
    puts("No");
    return 0;
  }
  puts("Yes");
  Solve();
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", ans[i] + n, i == n ? '\n' : ' ');
  }
  return 0;
}
