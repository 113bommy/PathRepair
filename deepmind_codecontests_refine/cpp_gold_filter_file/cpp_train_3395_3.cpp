#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename flow_t = long long>
struct PushRelabel {
  struct Edge {
    long long to, rev;
    flow_t f, c;
  };
  vector<vector<Edge> > g;
  vector<flow_t> ec;
  vector<Edge *> cur;
  vector<vector<long long> > hs;
  vector<long long> H;
  PushRelabel(long long n) : g(n), ec(n), cur(n), hs(2 * n), H(n) {}
  long long add_edge(long long s, long long t, flow_t cap, flow_t rcap = 0) {
    assert(s != t);
    Edge a = {t, (long long)g[t].size(), 0, cap};
    Edge b = {s, (long long)g[s].size(), 0, rcap};
    g[s].push_back(a);
    g[t].push_back(b);
    return b.rev;
  }
  void add_flow(Edge &e, flow_t f) {
    Edge &back = g[e.to][e.rev];
    if (!ec[e.to] && f) hs[H[e.to]].push_back(e.to);
    e.f += f;
    e.c -= f;
    ec[e.to] += f;
    back.f -= f;
    back.c += f;
    ec[back.to] -= f;
  }
  flow_t max_flow(long long s, long long t) {
    long long v = g.size();
    H[s] = v;
    ec[t] = 1;
    vector<long long> co(2 * v);
    co[0] = v - 1;
    for (long long i = 0; i < v; ++i) cur[i] = g[i].data();
    for (auto &e : g[s]) add_flow(e, e.c);
    if (hs[0].size())
      for (long long hi = 0; hi >= 0;) {
        long long u = hs[hi].back();
        hs[hi].pop_back();
        while (ec[u] > 0)
          if (cur[u] == g[u].data() + g[u].size()) {
            H[u] = 1e9;
            for (auto &e : g[u])
              if (e.c && H[u] > H[e.to] + 1) H[u] = H[e.to] + 1, cur[u] = &e;
            if (++co[H[u]], !--co[hi] && hi < v)
              for (long long i = 0; i < v; ++i)
                if (hi < H[i] && H[i] < v) {
                  --co[H[i]];
                  H[i] = v + 1;
                }
            hi = H[u];
          } else if (cur[u]->c && H[u] == H[cur[u]->to] + 1)
            add_flow(*cur[u], min(ec[u], cur[u]->c));
          else
            ++cur[u];
        while (hi >= 0 && hs[hi].empty()) --hi;
      }
    return -ec[s];
  }
};
template <typename flow_t = long long, typename cost_t = long long>
struct mcSFlow {
  struct Edge {
    cost_t c;
    flow_t f;
    long long to, rev;
    Edge(long long _to, cost_t _c, flow_t _f, long long _rev)
        : c(_c), f(_f), to(_to), rev(_rev) {}
  };
  const cost_t INFCOST = numeric_limits<cost_t>::max() / 2;
  const cost_t INFFLOW = numeric_limits<flow_t>::max() / 2;
  cost_t epsilon;
  long long N, S, T;
  vector<vector<Edge> > G;
  vector<unsigned long long> isEnqueued, state;
  mcSFlow(long long _N, long long _S, long long _T)
      : epsilon(0), N(_N), S(_S), T(_T), G(_N) {}
  long long add_edge(long long a, long long b, cost_t cost, flow_t cap) {
    if (a == b) {
      assert(a != b);
      return -1;
    }
    cost *= N;
    epsilon = max(epsilon, abs(cost));
    assert(a >= 0 && a < N && b >= 0 && b < N);
    G[a].emplace_back(b, cost, cap, G[b].size());
    G[b].emplace_back(a, -cost, 0, G[a].size() - 1);
    return G[a].size() - 1;
  }
  flow_t calc_max_flow() {
    vector<flow_t> dist(N), state(N);
    vector<Edge *> path(N);
    auto cmp = [](Edge *a, Edge *b) { return a->f < b->f; };
    flow_t addFlow, retflow = 0;
    do {
      fill(dist.begin(), dist.end(), -1);
      dist[S] = 0;
      auto head = state.begin(), tail = state.begin();
      for (*tail++ = S; head != tail; ++head) {
        for (Edge const &e : G[*head]) {
          if (e.f && dist[e.to] == -1) {
            dist[e.to] = dist[*head] + 1;
            *tail++ = e.to;
          }
        }
      }
      addFlow = 0;
      fill(state.begin(), state.end(), 0);
      auto top = path.begin();
      Edge dummy(S, 0, INFFLOW, -1);
      *top++ = &dummy;
      while (top != path.begin()) {
        long long n = (*prev(top))->to;
        if (n == T) {
          auto next_top = min_element(path.begin(), top, cmp);
          flow_t flow = (*next_top)->f;
          while (--top != path.begin()) {
            Edge &e = **top, &f = G[e.to][e.rev];
            e.f -= flow;
            f.f += flow;
          }
          addFlow = 1;
          retflow += flow;
          top = next_top;
          continue;
        }
        flow_t &i = state[n];
        for (unsigned long long i_max = G[n].size(), need = dist[n];; ++i) {
          if (i == i_max) {
            dist[n] = -1;
            --top;
            break;
          }
          if (dist[G[n][i].to] == need + 1 && G[n][i].f) {
            *top++ = &G[n][i];
            break;
          }
        }
      }
    } while (addFlow);
    return retflow;
  }
  vector<flow_t> excess;
  vector<cost_t> h;
  void push(Edge &e, flow_t amt) {
    if (e.f < amt) amt = e.f;
    e.f -= amt;
    excess[e.to] += amt;
    G[e.to][e.rev].f += amt;
    excess[G[e.to][e.rev].to] -= amt;
  }
  void relabel(long long vertex) {
    cost_t newHeight = -INFCOST;
    for (unsigned long long i = 0; i < G[vertex].size(); ++i) {
      Edge const &e = G[vertex][i];
      if (e.f && newHeight < h[e.to] - e.c) {
        newHeight = h[e.to] - e.c;
        state[vertex] = i;
      }
    }
    h[vertex] = newHeight - epsilon;
  }
  const long long scale = 1;
  pair<flow_t, cost_t> minCostFlow() {
    cost_t retCost = 0;
    for (long long i = 0; i < N; ++i) {
      for (Edge &e : G[i]) {
        retCost += e.c * (e.f);
      }
    }
    flow_t retFlow = 0;
    add_edge(T, S, 0, 1e15);
    excess.resize(N);
    h.resize(N);
    queue<long long> q;
    isEnqueued.assign(N, 0);
    state.assign(N, 0);
    for (; epsilon; epsilon >>= scale) {
      fill(state.begin(), state.end(), 0);
      for (long long i = 0; i < N; ++i)
        for (auto &e : G[i])
          if (h[i] + e.c - h[e.to] < 0 && e.f) push(e, e.f);
      for (long long i = 0; i < N; ++i) {
        if (excess[i] > 0) {
          q.push(i);
          isEnqueued[i] = 1;
        }
      }
      while (!q.empty()) {
        long long cur = q.front();
        q.pop();
        isEnqueued[cur] = 0;
        while (excess[cur] > 0) {
          if (state[cur] == G[cur].size()) {
            relabel(cur);
          }
          for (unsigned long long &i = state[cur], max_i = G[cur].size();
               i < max_i; ++i) {
            Edge &e = G[cur][i];
            if (h[cur] + e.c - h[e.to] < 0) {
              push(e, excess[cur]);
              if (excess[e.to] > 0 && isEnqueued[e.to] == 0) {
                q.push(e.to);
                isEnqueued[e.to] = 1;
              }
              if (excess[cur] == 0) break;
            }
          }
        }
      }
      if (epsilon > 1 && epsilon >> scale == 0) {
        epsilon = 1 << scale;
      }
    }
    for (long long i = 0; i < N; ++i) {
      for (Edge &e : G[i]) {
        retCost -= e.c * (e.f);
      }
    }
    return make_pair(retFlow, retCost / 2 / N);
  }
  flow_t getFlow(Edge const &e) { return G[e.to][e.rev].f; }
};
template <typename S, typename T>
void xmin(S &a, T const &b) {
  if (b < a) a = b;
}
template <typename S, typename T>
void xmax(S &a, T const &b) {
  if (b > a) a = b;
}
mt19937 rng(5325);
long long getrand(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
signed gen() {
  long long n = 10, m = 30, s = 1, t = n;
  ofstream o("gen.txt");
  o << "1\n";
  o << n << " " << m << " " << s << " " << t << "\n";
  for (long long i = 0; i < n - 1; ++i) {
    o << i + 1 << " " << i + 2 << " " << 1 << "\n";
  }
  set<pair<long long, long long> > ss;
  for (long long i = n - 1; i < m; ++i) {
    long long a, b, c;
    do {
      a = getrand(1, n - 1);
      b = getrand(2, n);
    } while (a == b || ss.count(make_pair(a, b)));
    c = !!getrand(0, 3);
    ss.insert(make_pair(a, b));
    o << a << " " << b << " " << c << "\n";
  }
  o << endl;
  o.close();
  return 0;
}
const ll infcap = 1e4;
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<long long> edge_ind_1(m, -1), edge_ind_2(m, -1);
  PushRelabel<> flow(n + 2);
  mcSFlow<ll, ll> mcflow(n + 2, s, t);
  vector<array<long long, 3> > edges;
  long long ctot = 0;
  for (long long i = 0; i < m; ++i) {
    long long a, b, c;
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
    if (c) {
      ++ctot;
      edge_ind_1[i] = flow.add_edge(a, b, 1, infcap);
    } else {
      edge_ind_1[i] = flow.add_edge(a, b, infcap);
    }
  }
  ll flowval = flow.max_flow(s, t);
  vector<char> issat(m, 0);
  for (long long i = 0; i < m; ++i) {
    long long a = edges[i][0], b = edges[i][1], c = edges[i][2];
    if (flow.H[a] >= flow.H[s] && flow.H[b] < flow.H[s]) {
      assert(c);
      issat[i] = 1;
      mcflow.add_edge(a, b, -1, 1);
      edge_ind_2[i] = mcflow.add_edge(a, b, 0, infcap);
    } else if (c) {
      mcflow.add_edge(a, b, -1, 1);
      edge_ind_2[i] = mcflow.add_edge(a, b, 0, infcap);
    } else {
    }
  }
  long long sat = accumulate(issat.begin(), issat.end(), 0);
  assert(flowval == sat);
  auto flowcost = mcflow.minCostFlow();
  assert(flowcost.second == ctot * ll(-1));
  vector<ll> ex(n + 2);
  cout << sat << "\n";
  for (long long i = 0; i < m; ++i) {
    long long a = edges[i][0], b = edges[i][1], c = edges[i][2];
    if (!c) {
      cout << 0 << " " << 1 << "\n";
    } else {
      assert(mcflow.G[edges[i][0]][edge_ind_2[i] - 1].f == 0);
      auto e = infcap - mcflow.G[a][edge_ind_2[i]].f + 1;
      cout << e << " ";
      if (issat[i])
        cout << e;
      else
        cout << e + 1;
      ex[a] -= e;
      ex[b] += e;
      cout << "\n";
    }
  }
  for (long long i = 1; i <= n; ++i) {
    assert(i == s || i == t || ex[i] == 0);
  }
  return 0;
}
