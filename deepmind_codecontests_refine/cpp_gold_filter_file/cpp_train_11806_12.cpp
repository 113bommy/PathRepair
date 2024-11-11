#include <bits/stdc++.h>
using namespace std;
bool SR(int &_x) { return scanf("%d", &_x) == 1; }
bool SR(long long &_x) { return scanf("%lld", &_x) == 1; }
bool SR(double &_x) { return scanf("%lf", &_x) == 1; }
bool SR(char *_s) { return scanf("%s", _s) == 1; }
bool RI() { return true; }
template <typename I, typename... T>
bool RI(I &_x, T &..._tail) {
  return SR(_x) && RI(_tail...);
}
void SP(const int _x) { printf("%d", _x); }
void SP(const long long _x) { printf("%lld", _x); }
void SP(const double _x) { printf("%.16lf", _x); }
void SP(const char *s) { printf("%s", s); }
void PL() { puts(""); }
template <typename I, typename... T>
void PL(const I _x, const T... _tail) {
  SP(_x);
  if (sizeof...(_tail)) putchar(' ');
  PL(_tail...);
}
template <typename TF, typename TC, bool maxcost, size_t maxn>
struct Flow {
  struct Edge {
    int u, v;
    TF f;
    TC c;
    Edge(int _u, int _v, TF _f, TC _c) : u(_u), v(_v), f(_f), c(_c) {}
  };
  int n;
  vector<Edge> edge;
  vector<int> id[maxn];
  void init(int _n) {
    n = _n;
    edge.clear();
    for (int i = 0; i < int(n); i++) id[i].clear();
  }
  void add(int u, int v, TF f, TC c) {
    if (maxcost) c *= -1;
    id[u].push_back(((int)(edge).size()));
    edge.push_back(Edge(u, v, f, c));
    id[v].push_back(((int)(edge).size()));
    edge.push_back(Edge(v, u, 0, -c));
  }
  pair<bool, TC> spfa() {
    static TC dis[maxn];
    static int par[maxn];
    bitset<maxn> isq;
    queue<int> q;
    memset(dis, 0x3f, sizeof(TC) * n);
    memset(par, -1, sizeof(int) * n);
    dis[0] = 0;
    isq[0] = 1;
    q.push(0);
    while (((int)(q).size())) {
      int u = q.front();
      q.pop();
      isq[u] = 0;
      for (int i : id[u])
        if (edge[i].f > 0) {
          const auto &e = edge[i];
          if (dis[e.v] > dis[u] + e.c) {
            dis[e.v] = dis[u] + e.c;
            par[e.v] = i;
            if (!isq[e.v]) isq[e.v] = 1, q.push(e.v);
          }
        }
    }
    if (par[n - 1] == -1) return make_pair(false, 0);
    for (int u = n - 1; u; u = edge[par[u]].u)
      edge[par[u]].f--, edge[par[u] ^ 1].f++;
    if (maxcost) dis[n - 1] *= -1;
    return make_pair(true, dis[n - 1]);
  }
  pair<TF, TC> calc() {
    TF cnt = 0;
    TC ans = 0;
    while (1) {
      pair<bool, TC> sub = spfa();
      if (!sub.first) break;
      cnt++;
      ans += sub.second;
    }
    return make_pair(cnt, ans);
  }
};
const int maxn = 1e2 + 2;
int n, m;
vector<int> atk, def;
int s[maxn];
void read() {
  RI(n, m);
  for (int i = 0; i < int(n); i++) {
    char t[5];
    int x;
    RI(t, x);
    (t[0] == 'A' ? atk : def).push_back(x);
  }
  for (int i = 0; i < int(m); i++) RI(s[i]);
}
const long long K = 10LL * 8000 * maxn;
Flow<int, long long, true, maxn * 2 + 3> flow;
void build() {
  flow.init(1 + m + n + 1 + 1);
  for (int i = 0; i < int(m); i++) flow.add(0, 1 + i, 1, 0);
  for (int i = 0; i < int(m); i++)
    for (int j = 0; j < int(((int)(atk).size())); j++)
      if (s[i] >= atk[j]) flow.add(1 + i, 1 + m + j, 1, s[i] - atk[j]);
  for (int i = 0; i < int(m); i++)
    for (int j = 0; j < int(((int)(def).size())); j++)
      if (s[i] > def[j]) flow.add(1 + i, 1 + m + ((int)(atk).size()) + j, 1, 0);
  for (int i = 0; i < int(n); i++) flow.add(1 + m + i, flow.n - 1, 1, 0);
  flow.add(flow.n - 2, flow.n - 1, m, -K);
  for (int i = 0; i < int(m); i++) flow.add(1 + i, flow.n - 2, 1, s[i]);
}
void sol() {
  long long ans = 0, cur = 0;
  for (int _ = 0; _ < int(n); _++) {
    auto sub = flow.spfa();
    if (sub.second < -K / 2) {
      PL(ans);
      return;
    }
    cur += sub.second;
    cur %= K;
    if (cur < 0) cur += K;
    ans = max(ans, cur);
    ;
  }
  while (1) {
    auto sub = flow.spfa();
    if (!sub.first) {
      PL(ans);
      return;
    }
    cur += sub.second;
    cur %= K;
    if (cur < 0) cur += K;
    ans = max(ans, cur);
    ;
  }
}
int main() {
  read();
  build();
  sol();
  return 0;
}
