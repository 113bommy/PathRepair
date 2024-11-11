#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000 + 10;
const int MAX_K = 30 + 1;
struct Pair {
  int a, b, dist;
  bool operator<(const Pair& o) const { return dist < o.dist; }
};
int x[MAX_N], y[MAX_N], n, k;
int dist[MAX_N][MAX_N];
Pair ps[MAX_N * MAX_N];
int nPs;
bool used[MAX_N];
const double EPS = 1e-8;
inline int sign(double a) { return a < -EPS ? -1 : a > EPS; }
struct Point {
  long long x, y;
  Point() {}
};
Point pt[MAX_N];
int leftId[MAX_N], rightId[MAX_N];
vector<int> edge[MAX_N];
int pR[MAX_N];
int mark[MAX_N], cur = 0;
bool dfs(int u) {
  if (mark[u] == cur) return false;
  mark[u] = cur;
  for (vector<int>::iterator e = edge[u].begin(); e != edge[u].end(); ++e) {
    if (pR[*e] == -1 || dfs(pR[*e])) return pR[*e] = u, true;
  }
  return false;
}
bool check(int who) {
  int a = ps[who].a, b = ps[who].b, d = ps[who].dist;
  int bad = 0;
  int nL = 0, nR = 0;
  memset(leftId, -1, sizeof leftId);
  memset(rightId, -1, sizeof rightId);
  for (int i = 0; i < n; ++i)
    if (i != a && i != b) {
      if (dist[i][a] <= d && dist[i][b] <= d) {
        if (((pt[b].x - pt[a].x) * (pt[i].y - pt[a].y) -
             (pt[i].x - pt[a].x) * (pt[b].y - pt[a].y)) > 0)
          leftId[i] = nL++;
        else
          rightId[i] = nR++;
      } else {
        ++bad;
      }
    }
  if (bad > k) return false;
  memset(pR, -1, sizeof pR);
  for (int i = 0; i < nL; ++i) {
    edge[i].clear();
  }
  for (int i = who + 1; i < nPs; ++i) {
    if (ps[i].dist > d) {
      int a = ps[i].a, b = ps[i].b;
      if (leftId[a] == -1) swap(a, b);
      if (leftId[a] == -1) continue;
      if (rightId[b] == -1) continue;
      edge[leftId[a]].push_back(rightId[b]);
    }
  }
  int cnt = 0;
  for (int i = 0; i < nL; ++i) {
    ++cur;
    if (dfs(i)) ++cnt;
    if (cnt > k - bad) {
      return false;
    }
  }
  return true;
}
const int INF = INT_MAX / 4;
template <class Flow>
struct Maxflow {
  struct Edge {
    int t;
    Flow c;
    Edge *n, *r;
    Edge(int _t, Flow _c, Edge* _n) : t(_t), c(_c), n(_n) {}
  };
  vector<Edge*> E;
  int addV() {
    E.push_back((Edge*)0);
    return E.size() - 1;
  }
  void clear() { E.clear(); }
  Edge* makeEdge(int s, int t, Flow c) { return E[s] = new Edge(t, c, E[s]); }
  Edge* addEdge(int s, int t, Flow c) {
    Edge *e1 = makeEdge(s, t, c), *e2 = makeEdge(t, s, 0);
    e1->r = e2, e2->r = e1;
    return e1;
  }
  int calcMaxFlow(int vs, int vt) {
    int nV = E.size();
    Flow totalFlow = 0;
    Flow MAX_FLOW = INF;
    vector<Flow> am(nV, 0);
    vector<int> h(nV, 0), cnt(nV + 1, 0);
    vector<Edge*> prev(nV, (Edge*)0), cur(nV, (Edge*)0);
    cnt[0] = nV;
    int u = vs;
    Edge* e;
    am[u] = MAX_FLOW;
    while (h[vs] < nV) {
      for (e = cur[u]; e; e = e->n)
        if (e->c > 0 && h[u] == h[e->t] + 1) break;
      if (e) {
        int v = e->t;
        cur[u] = prev[v] = e;
        am[v] = min(am[u], e->c);
        u = v;
        if (u == vt) {
          Flow by = am[u];
          while (u != vs) {
            prev[u]->c -= by;
            prev[u]->r->c += by;
            u = prev[u]->r->t;
          }
          totalFlow += by;
          am[u] = MAX_FLOW;
        }
      } else {
        if (!--cnt[h[u]]) break;
        h[u] = nV;
        for (e = E[u]; e; e = e->n)
          if (e->c > 0 && h[e->t] + 1 < h[u]) {
            h[u] = h[e->t] + 1;
            cur[u] = e;
          }
        ++cnt[h[u]];
        if (u != vs) u = prev[u]->r->t;
      }
    }
    return totalFlow;
  }
  vector<bool> reach;
  void dfs(int u) {
    if (reach[u]) return;
    reach[u] = true;
    for (Edge* e = E[u]; e; e = e->n)
      if (e->c > 0) dfs(e->t);
  }
  void genCut(int src) {
    reach = vector<bool>(E.size());
    dfs(src);
  }
  ~Maxflow() {
    for (int i = 0; i < E.size(); ++i) {
      for (Edge* e = E[i]; e;) {
        Edge* ne = e->n;
        delete e;
        e = ne;
      }
    }
  }
  bool isCut(int s, Edge* e) { return reach[s] && !reach[e->t]; }
};
Maxflow<int> sap;
Maxflow<int>::Edge *LE[MAX_N], *RE[MAX_N];
int ls[MAX_N], rs[MAX_N];
bool deled[MAX_N];
void build(int who) {
  int a = ps[who].a, b = ps[who].b, d = ps[who].dist;
  int cnt = 0;
  int nL = 0, nR = 0;
  memset(leftId, -1, sizeof leftId);
  memset(rightId, -1, sizeof rightId);
  memset(deled, false, sizeof deled);
  int del[MAX_N];
  for (int i = 0; i < n; ++i)
    if (i != a && i != b) {
      if (dist[i][a] <= d && dist[i][b] <= d) {
        if (((pt[b].x - pt[a].x) * (pt[i].y - pt[a].y) -
             (pt[i].x - pt[a].x) * (pt[b].y - pt[a].y)) > 0) {
          leftId[i] = nL;
          ls[nL++] = i;
        } else {
          rightId[i] = nR;
          rs[nR++] = i;
        }
      } else {
        del[cnt++] = i;
        deled[i] = true;
      }
    }
  memset(pR, -1, sizeof pR);
  for (int i = 0; i < nL; ++i) {
    edge[i].clear();
  }
  sap.clear();
  for (int i = 0; i < nL; ++i) {
    sap.addV();
  }
  for (int i = 0; i < nR; ++i) {
    sap.addV();
  }
  int S = sap.addV(), T = sap.addV();
  for (int i = 0; i < nL; ++i) {
    LE[i] = sap.addEdge(S, i, 1);
  }
  for (int i = 0; i < nR; ++i) {
    RE[i] = sap.addEdge(i + nL, T, 1);
  }
  for (int i = who + 1; i < nPs; ++i) {
    if (ps[i].dist > d) {
      int a = ps[i].a, b = ps[i].b;
      if (leftId[a] == -1) swap(a, b);
      if (leftId[a] == -1) continue;
      if (rightId[b] == -1) continue;
      int l = leftId[a], r = rightId[b];
      sap.addEdge(l, r + nL, INT_MAX);
    }
  }
  sap.calcMaxFlow(S, T);
  sap.genCut(S);
  for (int i = 0; i < nL; ++i) {
    if (sap.isCut(i, LE[i])) {
      deled[ls[i]] = true;
      del[cnt++] = ls[i];
    }
  }
  for (int i = 0; i < nR; ++i) {
    if (sap.isCut(i + nL, RE[i])) {
      deled[rs[i]] = true;
      del[cnt++] = rs[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (!deled[i] && cnt < k) {
      deled[i] = true;
      del[cnt++] = i;
    }
  }
  for (int i = 0; i < cnt; ++i) {
    printf("%d ", del[i] + 1);
  }
  puts("");
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", x + i, y + i);
    pt[i].x = x[i];
    pt[i].y = y[i];
  }
  if (n - k == 1) {
    for (int i = 1; i < n; ++i) {
      cout << i << " ";
    }
    cout << endl;
    return 0;
  }
  nPs = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int dx = x[i] - x[j], dy = y[i] - y[j];
      dist[i][j] = dx * dx + dy * dy;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      ps[nPs++] = (Pair){i, j, dist[i][j]};
    }
  }
  sort(ps, ps + nPs);
  int st = nPs;
  for (int i = 0; i < k; ++i) {
    st -= n - 1 - i;
  }
  --st;
  if (st < 0) st = 0;
  for (int i = 0; i < nPs; i++) {
    if (check(i)) {
      build(i);
      return 0;
    }
  }
  return 0;
}
