#include <bits/stdc++.h>
using namespace std;
long long _sieve_size;
bitset<10000010> bs;
vector<int> primes;
void sieve(long long upperbound) {
  _sieve_size = upperbound + 1;
  bs.reset();
  bs.flip();
  bs.set(0, false);
  bs.set(1, false);
  for (long long i = 2; i <= _sieve_size; ++i) {
    for (long long j = i * i; j <= _sieve_size; j += i)
      bs.set((size_t)j, false);
    primes.push_back((int)i);
  }
}
bool is_prime(long long N) {
  if (N < _sieve_size) return bs.test(N);
  for (int i = 0; i < primes.size(); ++i)
    if (N % primes[i] == 0) return false;
  return true;
}
struct FlowNetwork {
  struct edge {
    int v, nxt;
    long long cap, flo;
    edge(int _v, long long _cap, int _nxt)
        : v(_v), cap(_cap), nxt(_nxt), flo(0) {}
  };
  int n, edge_count = 0, *h;
  vector<edge> e;
  FlowNetwork(int V, int E = 0) : n(V) {
    e.reserve(2 * (E == 0 ? V : E));
    memset(h = new int[V], -1, n * sizeof(int));
  }
  void add_edge(int u, int v, long long uv_cap, long long vu_cap = 0) {
    e.push_back(edge(v, uv_cap, h[u]));
    h[u] = edge_count++;
    e.push_back(edge(u, vu_cap, h[v]));
    h[v] = edge_count++;
  }
  void cleanup() { delete[] h; }
  long long edmonds_karp(int s, int t);
};
long long FlowNetwork::edmonds_karp(int s, int t) {
  int v, p[300], q[300];
  long long f = 0, c[300];
  while (true) {
    memset(p, -1, n * sizeof(int));
    int i, u = -1, l = 0, r = 0;
    c[s] = 9000000000000000;
    p[q[r++] = s] = -2;
    while (l != r && u != t) {
      for (u = q[l++], i = h[u]; i != -1; i = e[i].nxt) {
        if (e[i].cap > e[i].flo && p[v = e[i].v] == -1) {
          p[q[r++] = v] = i;
          c[v] = min(c[u], e[i].cap - e[i].flo);
        }
      }
    }
    if (p[t] == -1) break;
    for (i = p[t]; i != -2; i = p[e[i ^ 1].v]) {
      e[i].flo += c[t];
      e[i ^ 1].flo -= c[t];
    }
    f += c[t];
  }
  return f;
}
struct Fox {
 public:
  int a = -1, id = -1;
  bool odd = false;
  vector<int> nbrs;
  Fox() {}
  Fox(int a, int id) : a(a), odd(a % 2 == 1), id(id) {}
};
void dfs(int ix, vector<Fox>& mine, vector<Fox>& other, bitset<210>& vs,
         vector<vector<int> >& table) {
  vs.set(mine[ix].id, true);
  table[table.size() - 1].push_back(mine[ix].id);
  for (int nx : mine[ix].nbrs) {
    if (vs.test(other[nx].id)) continue;
    dfs(nx, other, mine, vs, table);
  }
}
int main() {
  sieve(1e5);
  int n;
  cin >> n;
  vector<Fox> oddFoxes, evenFoxes;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a % 2 == 0)
      evenFoxes.push_back(Fox(a, i + 1));
    else
      oddFoxes.push_back(Fox(a, i + 1));
  }
  int evsize = evenFoxes.size(), odsize = oddFoxes.size();
  if (evsize != odsize)
    cout << "Impossible" << endl;
  else {
    int SOURCE = 0, SINK = evsize + odsize + 1;
    FlowNetwork fn(n + 2);
    for (int i = 0; i < evsize; ++i) {
      fn.add_edge(SOURCE, i + 1, 2);
    }
    for (int i = 0; i < odsize; ++i) {
      fn.add_edge(evsize + i + 1, SINK, 2);
    }
    for (int i = 0; i < evsize; ++i) {
      for (int j = 0; j < odsize; ++j) {
        if (is_prime(evenFoxes[i].a + oddFoxes[j].a)) {
          fn.add_edge(i + 1, evsize + j + 1, 1);
        }
      }
    }
    long long flow = fn.edmonds_karp(SOURCE, SINK);
    if (flow < evsize) {
      cout << "Impossible" << endl;
    } else {
      for (int i = 0; i < fn.e.size(); ++i) {
        if (fn.e[i].cap != 1) continue;
        if (fn.e[i].flo != 1) continue;
        int ev = fn.e[i ^ 1].v - 1, od = fn.e[i].v - 1 - evsize;
        evenFoxes[ev].nbrs.push_back(od);
        oddFoxes[od].nbrs.push_back(ev);
      }
      vector<vector<int> > table;
      bitset<210> vs;
      vs.reset();
      for (int i = 0; i < evsize; ++i) {
        if (vs.test(evenFoxes[i].id)) continue;
        table.push_back(vector<int>());
        dfs(i, evenFoxes, oddFoxes, vs, table);
      }
      cout << table.size() << endl;
      for (vector<int>& t : table) {
        cout << t.size();
        for (int i = 0; i < t.size(); ++i) cout << ' ' << t[i];
        cout << endl;
      }
    }
    fn.cleanup();
  }
  return 0;
}
