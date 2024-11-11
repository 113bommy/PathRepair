#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T LCM(T a, T b) {
  return a * (b / gcd(a, b));
}
template <typename T>
T expo(T b, T e, const T &m) {
  if (e <= 1) return e == 0 ? 1 : b;
  return (e & 1) == 0 ? expo((b * b) % m, e >> 1, m)
                      : (b * expo((b * b) % m, e >> 1, m)) % m;
}
template <typename T>
T modinv(T a) {
  return expo(a, 1000000007ll - 2, 1000000007ll);
}
template <class T, class second>
std::ostream &operator<<(std::ostream &os, const std::pair<T, second> &t) {
  os << "(" << t.first << ", " << t.second << ")";
  return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &t) {
  os << "[";
  for (__typeof(t.begin()) it = t.begin(); it != t.end(); it++) {
    if (it != t.begin()) os << ", ";
    os << *it;
  }
  os << "]";
  return os;
}
int N;
int arr[209];
bool is_prime[20009] = {false};
vector<int> primes;
bool fwd_edge[209][209] = {{false}};
void sieve_eratosthenes() {
  for (__typeof(20009) i = 0; i < 20009; i++) is_prime[i] = true;
  is_prime[1] = false;
  for (int i = 2; i * i <= 20009; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i * i; j < 20009; j += i) {
        is_prime[j] = false;
      }
    }
  }
}
class Dinic {
 private:
  struct edge {
    int a, b, cap, flow;
  };
  int n, s, t, d[209], ptr[209], q[209];
  bool matrix[209][209];
  vector<edge> e;
  vector<int> g[209];

 public:
  Dinic(int a, int b, int c) : n(a), s(b), t(c) {}
  void create_adj_list() {
    for (__typeof(209) i = 0; i < 209; i++) {
      for (__typeof(209) j = 0; j < 209; j++) {
        matrix[i][j] = false;
      }
    }
    vector<int> odd, even;
    for (__typeof(N) i = 1; i <= N; i++) {
      if (arr[i] % 2 == 0) {
        even.push_back(i);
      } else {
        odd.push_back(i);
      }
    }
    for (__typeof(int(odd.size())) i = 0; i < int(odd.size()); i++) {
      add_edge(0, odd[i], 2);
    }
    for (__typeof(N) i = 1; i <= N; i++) {
      if (arr[i] % 2 == 0) continue;
      for (__typeof(N) j = 1; j <= N; j++) {
        if (arr[j] % 2 == 0 && is_prime[arr[i] + arr[j]]) {
          add_edge(i, j, 1);
        }
      }
    }
    for (__typeof(int(even.size())) i = 0; i < int(even.size()); i++) {
      add_edge(even[i], N + 1, 2);
    }
  }
  void add_edge(int a, int b, int cap) {
    edge e1 = {a, b, cap, 0};
    edge e2 = {b, a, 0, 0};
    g[a].push_back((int)e.size());
    e.push_back(e1);
    fwd_edge[a][b] = true;
    g[b].push_back((int)e.size());
    e.push_back(e2);
  }
  bool bfs() {
    int qh = 0, qt = 0;
    q[qt++] = s;
    memset(d, -1, n * sizeof d[0]);
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
      int v = q[qh++];
      for (size_t i = 0; i < g[v].size(); ++i) {
        int id = g[v][i], to = e[id].b;
        if (d[to] == -1 && e[id].flow < e[id].cap) {
          q[qt++] = to;
          d[to] = d[v] + 1;
        }
      }
    }
    return d[t] != -1;
  }
  int dfs(int v, int flow) {
    if (!flow) return 0;
    if (v == t) return flow;
    for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
      int id = g[v][ptr[v]], to = e[id].b;
      if (d[to] != d[v] + 1) continue;
      int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
      if (pushed) {
        e[id].flow += pushed;
        e[id ^ 1].flow -= pushed;
        return pushed;
      }
    }
    return 0;
  }
  int dinic() {
    int flow = 0;
    for (;;) {
      if (!bfs()) break;
      memset(ptr, 0, n * sizeof ptr[0]);
      while (int pushed = dfs(s, 1 << 28)) flow += pushed;
    }
    return flow;
  }
  bool if_poss() {
    if (dinic() == N) {
      return true;
    }
    return false;
  }
  void create_matrix() {
    for (__typeof(int(e.size())) i = 0; i < int(e.size()); i++) {
      if (max(e[i].a, e[i].b) <= N && min(e[i].a, e[i].b) >= 1 &&
          e[i].flow == 1) {
        matrix[e[i].a][e[i].b] = true;
      }
    }
  }
  void answer() {
    bool vis[209] = {false};
    vector<int> tables[209];
    int cnt = 0;
    for (__typeof(N) i = 1; i <= N; i++) {
      if (vis[i]) continue;
      int curr = i;
      while (true) {
        bool found = false;
        vis[curr] = true;
        tables[cnt].push_back(curr);
        for (__typeof(N) j = 1; j <= N; j++) {
          if (!vis[j] && ((matrix[j][curr] && arr[curr] % 2 == 0) ||
                          (matrix[curr][j] && arr[curr] % 2 == 1))) {
            curr = j;
            found = true;
            break;
          }
        }
        if (!found) break;
      }
      cnt++;
    }
    cout << cnt << '\n';
    for (__typeof(cnt) i = 0; i < cnt; i++) {
      cout << int(tables[i].size()) << ' ';
      for (__typeof(int(tables[i].size())) j = 0; j < int(tables[i].size());
           j++) {
        cout << tables[i][j] << ' ';
      }
      cout << '\n';
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cout << unitbuf;
  sieve_eratosthenes();
  cin >> N;
  for (__typeof(N) i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  Dinic one(N + 2, 0, N + 1);
  one.create_adj_list();
  if (one.if_poss()) {
    one.create_matrix();
    one.answer();
  } else {
    cout << "Impossible\n";
  }
  return 0;
}
