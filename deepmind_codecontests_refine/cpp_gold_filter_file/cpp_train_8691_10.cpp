#include <bits/stdc++.h>
using namespace std;
const long long NR = 2e5 + 20, oo = 1e15, MOD = 1e9 + 7;
const long double pi = 2 * acos(0.0);
long long n, m, x, y;
struct muchie {
  long long a, b, c;
};
vector<muchie> edges;
vector<pair<long long, long long> > v[NR];
vector<pair<long long, long long> > v_t[NR];
vector<pair<long long, long long> > v2[NR];
vector<long long> d(NR, oo);
vector<long long> d_t(NR, oo);
struct cmp {
  inline bool operator()(const long long i, const long long j) {
    return d[i] > d[j];
  }
};
struct cmp_t {
  inline bool operator()(const long long i, const long long j) {
    return d_t[i] > d_t[j];
  }
};
bitset<NR> inq;
bitset<NR> inq_t;
priority_queue<long long, vector<long long>, cmp> q;
priority_queue<long long, vector<long long>, cmp_t> q_t;
static void dijkstra() {
  long long nod, cost;
  d[x] = 0;
  q.push(x);
  while (!q.empty()) {
    nod = q.top();
    q.pop();
    inq[nod] = 0;
    for (vector<pair<long long, long long> >::iterator it = v[nod].begin();
         it < v[nod].end(); ++it) {
      if (d[nod] + (*it).second < d[(*it).first]) {
        d[(*it).first] = d[nod] + (*it).second;
        if (!inq[(*it).first]) q.push((*it).first), inq[(*it).first] = 1;
      }
    }
  }
}
static void dijkstra_t() {
  long long nod, cost;
  d_t[y] = 0;
  q_t.push(y);
  while (!q_t.empty()) {
    nod = q_t.top();
    q_t.pop();
    inq_t[nod] = 0;
    for (vector<pair<long long, long long> >::iterator it = v_t[nod].begin();
         it < v_t[nod].end(); ++it) {
      if (d_t[nod] + (*it).second < d_t[(*it).first]) {
        d_t[(*it).first] = d_t[nod] + (*it).second;
        if (!inq_t[(*it).first]) q_t.push((*it).first), inq_t[(*it).first] = 1;
      }
    }
  }
}
long long low[NR], lvl[NR], viz[NR], good[NR], prt[NR], cnt;
void dfs(long long nod) {
  viz[nod] = 1;
  lvl[nod] = ++cnt;
  low[nod] = lvl[nod];
  vector<pair<long long, long long> >::iterator it;
  for (it = v2[nod].begin(); it != v2[nod].end(); ++it) {
    if (!viz[(*it).first]) {
      prt[(*it).first] = (*it).second;
      dfs((*it).first);
      low[nod] = min(low[nod], low[(*it).first]);
      if (low[(*it).first] == lvl[(*it).first]) {
        good[(*it).second] = 1;
      }
    } else {
      if (prt[nod] != (*it).second) {
        low[nod] = min(low[nod], low[(*it).first]);
      }
    }
  }
}
int main() {
  long long i, a, b, c, diff;
  muchie temp;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> x >> y;
  for (i = 1; i <= m; ++i) {
    cin >> a >> b >> c;
    temp.a = a;
    temp.b = b;
    temp.c = c;
    edges.push_back(temp);
    v[a].push_back(make_pair(b, c));
    v_t[b].push_back(make_pair(a, c));
  }
  dijkstra();
  dijkstra_t();
  for (i = 0; i < edges.size(); ++i) {
    if (d[edges[i].a] + d_t[edges[i].b] + edges[i].c == d[y]) {
      v2[edges[i].a].push_back(make_pair(edges[i].b, i + 1));
      v2[edges[i].b].push_back(make_pair(edges[i].a, i + 1));
    }
  }
  for (i = 1; i <= n; ++i) {
    if (!viz[i]) {
      dfs(i);
    }
  }
  for (i = 0; i < edges.size(); ++i) {
    diff = d[edges[i].a] + d_t[edges[i].b] + edges[i].c - d[y] + 1;
    if (good[i + 1]) {
      cout << "YES\n";
    } else {
      if (edges[i].c <= diff)
        cout << "NO\n";
      else
        cout << "CAN " << diff << '\n';
    }
  }
  return 0;
}
