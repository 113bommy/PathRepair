#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;
struct Edge {
  int src, dst;
  int weight;
  Edge(int src, int dst, int weight) : src(src), dst(dst), weight(weight) {}
};
bool operator<(const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight
         : e.src != f.src     ? e.src < f.src
                              : e.dst < f.dst;
}
void visit(const vector<vector<Edge> > &g, int v, vector<vector<int> > &scc,
           stack<int> &S, vector<bool> &inS, vector<int> &low, vector<int> &num,
           int &time) {
  low[v] = num[v] = ++time;
  S.push(v);
  inS[v] = true;
  for (__typeof((g[v]).begin()) e = (g[v]).begin(); e != (g[v]).end(); e++) {
    int w = e->dst;
    if (num[w] == 0) {
      visit(g, w, scc, S, inS, low, num, time);
      low[v] = min(low[v], low[w]);
    } else if (inS[w])
      low[v] = min(low[v], num[w]);
  }
  if (low[v] == num[v]) {
    scc.push_back(vector<int>());
    while (1) {
      int w = S.top();
      S.pop();
      inS[w] = false;
      scc.back().push_back(w);
      if (v == w) break;
    }
  }
}
void stronglyConnectedComponents(const vector<vector<Edge> > &g,
                                 vector<vector<int> > &scc) {
  const int n = g.size();
  vector<int> num(n), low(n);
  stack<int> S;
  vector<bool> inS(n);
  int time = 0;
  for (int u = 0; u < (int)n; u++)
    if (num[u] == 0) visit(g, u, scc, S, inS, low, num, time);
}
const int MX = 600000;
char buf[MX];
vector<int> A, B, C;
vector<int> rs, lens;
int n, m;
unordered_map<string, int> id;
vector<vector<int> > e;
vector<vector<int> > scc;
bool memo[2 * MX];
pair<int, int> dp[2 * MX];
inline pair<int, int> rec(int c) {
  if (memo[c]) return dp[c];
  memo[c] = 1;
  pair<int, int> &res = dp[c];
  res = make_pair(inf, inf);
  for (__typeof((scc[c]).begin()) i = (scc[c]).begin(); i != (scc[c]).end();
       i++)
    res = min(res, make_pair(rs[*i], lens[*i]));
  for (int i = 0; i < (int)e[c].size(); i++) res = min(res, rec(e[c][i]));
  return res;
}
int main() {
  scanf("%d", &n);
  int pos = 0;
  for (int i = 0; i < (int)n; i++) {
    scanf("%s", buf);
    for (int j = 0; buf[j]; j++) buf[j] = tolower(buf[j]);
    if (!id.count(buf)) {
      int r = 0;
      lens.push_back(strlen(buf));
      for (int j = 0; j < (int)lens.back(); j++)
        if (buf[j] == 'r' || buf[j] == 'R') r++;
      rs.push_back(r);
      id[buf] = pos++;
    }
    A.push_back(id[buf]);
  }
  scanf("%d", &m);
  for (int i = 0; i < (int)m; i++) {
    scanf("%s", buf);
    for (int j = 0; buf[j]; j++) buf[j] = tolower(buf[j]);
    if (!id.count(buf)) {
      int r = 0;
      lens.push_back(strlen(buf));
      for (int j = 0; j < (int)lens.back(); j++)
        if (buf[j] == 'r' || buf[j] == 'R') r++;
      rs.push_back(r);
      id[buf] = pos++;
    }
    B.push_back(id[buf]);
    scanf("%s", buf);
    for (int j = 0; buf[j]; j++) buf[j] = tolower(buf[j]);
    if (!id.count(buf)) {
      int r = 0;
      lens.push_back(strlen(buf));
      for (int j = 0; j < (int)lens.back(); j++)
        if (buf[j] == 'r' || buf[j] == 'R') r++;
      rs.push_back(r);
      id[buf] = pos++;
    }
    C.push_back(id[buf]);
  }
  vector<int> to(pos, -1);
  vector<vector<Edge> > g(pos);
  for (int i = 0; i < (int)m; i++) g[B[i]].push_back(Edge(B[i], C[i], 0));
  stronglyConnectedComponents(g, scc);
  for (int i = 0; i < (int)scc.size(); i++)
    for (int j = 0; j < (int)scc[i].size(); j++) to[scc[i][j]] = i;
  e.resize(scc.size());
  for (int i = 0; i < (int)m; i++) {
    int a = to[B[i]], b = to[C[i]];
    if (a != b) e[a].push_back(b);
  }
  int ansr = 0, ansl = 0;
  for (int i = 0; i < (int)n; i++) {
    pair<int, int> p = rec(to[A[i]]);
    ansr += p.first;
    ansl += p.second;
  }
  cout << ansr << " " << ansl << endl;
  return 0;
}
