#include <bits/stdc++.h>
using namespace std;
using vi = vector<long long>;
template <typename T>
std::istream& operator>>(std::istream& input, std::pair<T, T>& data) {
  input >> data.first >> data.second;
  return input;
}
template <typename T>
std::istream& operator>>(std::istream& input, std::vector<T>& data) {
  for (T& first : data) input >> first;
  return input;
}
template <typename T>
std::ostream& operator<<(std::ostream& output, const pair<T, T>& data) {
  output << "(" << data.first << "," << data.second << ")";
  return output;
}
template <typename T>
std::ostream& operator<<(std::ostream& output, const std::vector<T>& data) {
  for (const T& first : data) output << first << " ";
  return output;
}
std::ostream& operator<<(std::ostream& output, const __int128& first) {
  __int128 n = first;
  if (n == 0) {
    output << "0";
    return output;
  }
  if (n < 0) {
    n = -n;
    output << "-";
  }
  string s;
  while (n) {
    s += '0' + (n % 10);
    n /= 10;
  }
  reverse(s.begin(), s.end());
  cout << s;
  return output;
}
long long div_up(long long a, long long b) {
  return a / b + ((a ^ b) > 0 && a % b);
}
long long div_down(long long a, long long b) {
  return a / b - ((a ^ b) < 0 && a % b);
}
long long math_mod(long long a, long long b) { return a - b * div_down(a, b); }
template <class T>
using V = vector<T>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
long long gcd(long long a, long long b) {
  while (b) {
    tie(a, b) = make_pair(b, a % b);
  }
  return a;
}
long long Bit(long long mask, long long bit) { return (mask >> bit) & 1; }
const long long N = 23, INF = 1e18;
string greed[N];
struct Chel {
  long long first, second, t;
};
V<pair<long long, long long> > v = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
struct Dinic {
  struct edge {
    long long to, flow, cap;
  };
  const static long long N = 23 * 23 * 4;
  vector<edge> e;
  vector<long long> g[N + 7];
  long long dp[N + 7];
  long long ptr[N + 7];
  void clear() {
    for (long long i = 0; i < N + 7; i++) g[i].clear();
    e.clear();
  }
  void addEdge(long long a, long long b, long long cap) {
    g[a].push_back(e.size());
    e.push_back({b, 0, cap});
    g[b].push_back(e.size());
    e.push_back({a, 0, 0});
  }
  long long minFlow, start, finish;
  bool bfs() {
    for (long long i = 0; i < N; i++) dp[i] = -1;
    dp[start] = 0;
    vector<long long> st;
    long long uk = 0;
    st.push_back(start);
    while (uk < st.size()) {
      long long v = st[uk++];
      for (long long to : g[v]) {
        auto ed = e[to];
        if (ed.cap - ed.flow >= minFlow && dp[ed.to] == -1) {
          dp[ed.to] = dp[v] + 1;
          st.push_back(ed.to);
        }
      }
    }
    return dp[finish] != -1;
  }
  long long dfs(long long v, long long flow) {
    if (v == finish) return flow;
    for (; ptr[v] < g[v].size(); ptr[v]++) {
      long long to = g[v][ptr[v]];
      edge ed = e[to];
      if (ed.cap - ed.flow >= minFlow && dp[ed.to] == dp[v] + 1) {
        long long add = dfs(ed.to, min(flow, ed.cap - ed.flow));
        if (add) {
          e[to].flow += add;
          e[to ^ 1].flow -= add;
          return add;
        }
      }
    }
    return 0;
  }
  long long dinic(long long start, long long finish) {
    Dinic::start = start;
    Dinic::finish = finish;
    long long flow = 0;
    for (minFlow = (1 << 30); minFlow; minFlow >>= 1) {
      while (bfs()) {
        for (long long i = 0; i < N; i++) ptr[i] = 0;
        while (long long now = dfs(start, (long long)2e9 + 7)) flow += now;
      }
    }
    return flow;
  }
} dinic;
long long n, m;
void bfs(long long first, long long second, long long dist[N][N]) {
  for (long long i = (0); i < (N); ++i) {
    for (long long j = (0); j < (N); ++j) {
      dist[i][j] = INF;
    }
  }
  if (greed[first][second] == '#') {
    return;
  }
  queue<pair<long long, long long> > q;
  q.push(make_pair(first, second));
  dist[first][second] = 0;
  while (q.size()) {
    auto p = q.front();
    q.pop();
    long long i = p.first, j = p.second;
    for (auto& e : v) {
      long long first = i + e.first, second = j + e.second;
      if (0 <= first && first < n && 0 <= second && second < m &&
          greed[first][second] == '.') {
        if (ckmin(dist[first][second], dist[i][j] + 1)) {
          q.push(make_pair(first, second));
        }
      }
    }
  }
}
long long dist[N][N][N][N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long males, females;
  cin >> n >> m >> males >> females;
  for (long long i = (0); i < (n); ++i) {
    cin >> greed[i];
  }
  long long first, second, t;
  cin >> first >> second >> t;
  first--;
  second--;
  if (abs(males - females) != 1) {
    cout << -1 << '\n';
    exit(0);
  }
  V<Chel> a(males), b(females);
  for (long long i = (0); i < (males); ++i) {
    cin >> a[i].first >> a[i].second >> a[i].t;
    a[i].first--;
    a[i].second--;
  }
  for (long long i = (0); i < (females); ++i) {
    cin >> b[i].first >> b[i].second >> b[i].t;
    b[i].first--;
    b[i].second--;
  }
  if (males > females) {
    b.push_back({first, second, t});
  } else {
    a.push_back({first, second, t});
  }
  for (long long i = (0); i < (n); ++i) {
    for (long long j = (0); j < (m); ++j) {
      bfs(i, j, dist[i][j]);
    }
  }
  assert(a.size() == b.size());
  long long k = a.size();
  auto num = [&](long long first, long long second) {
    return first * m + second;
  };
  auto check = [&](long long Tim) {
    dinic.clear();
    const long long S = dinic.N - 2;
    const long long T = dinic.N - 1;
    for (long long i = (0); i < (k); ++i) {
      dinic.addEdge(S, i, 1);
      for (long long first = (0); first < (n); ++first) {
        for (long long second = (0); second < (m); ++second) {
          long long d = dist[a[i].first][a[i].second][first][second];
          if (d != INF) {
            if (d * a[i].t <= Tim) {
              dinic.addEdge(i, 2 * k + num(first, second), 1);
            }
          }
        }
      }
    }
    for (long long first = (0); first < (n); ++first) {
      for (long long second = (0); second < (m); ++second) {
        if (greed[first][second] == '.') {
          dinic.addEdge(2 * k + num(first, second),
                        2 * k + n * m + num(first, second), 1);
        }
      }
    }
    for (long long i = (0); i < (k); ++i) {
      dinic.addEdge(i + k, T, 1);
      for (long long first = (0); first < (n); ++first) {
        for (long long second = (0); second < (m); ++second) {
          long long d = dist[b[i].first][b[i].second][first][second];
          if (d != INF) {
            if (d * b[i].t <= Tim) {
              dinic.addEdge(2 * k + n * m + num(first, second), i + k, 1);
            }
          }
        }
      }
    }
    return dinic.dinic(S, T) == k;
  };
  long long l = 0, r = INF;
  if (!check(r)) {
    cout << -1 << '\n';
    exit(0);
  }
  while (l < r - 1) {
    long long m = (l + r) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << '\n';
}
