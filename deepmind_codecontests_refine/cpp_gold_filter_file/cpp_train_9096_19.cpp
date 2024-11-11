#include <bits/stdc++.h>
using namespace std;
using LL = long long;
namespace _buff {
const size_t BUFF = 1 << 19;
char buff[BUFF], *begin = buff, *end = buff;
char getc() {
  if (begin == end) {
    begin = buff;
    end = buff + fread(buff, 1, BUFF, stdin);
  }
  return begin == end ? -1 : *begin++;
}
}  // namespace _buff
LL read() {
  using namespace _buff;
  LL ret = 0;
  bool pos = true;
  char c = getc();
  for (; (c < '0' || c > '9') && c != '-'; c = getc()) {
    assert(~c);
  }
  if (c == '-') {
    pos = false;
    c = getc();
  }
  for (; c >= '0' && c <= '9'; c = getc()) {
    ret = (ret << 3) + (ret << 1) + (c ^ 48);
  }
  return pos ? ret : -ret;
}
const int INF = numeric_limits<int>::max();
struct Maxflow {
  static constexpr size_t V = 2e4 + 5;
  static constexpr size_t E = 2e5 + 5;
  struct Edge {
    int to, cap, nxt;
  } e[E];
  int tot = 1, head[V];
  void addEdge(int u, int v, int cap) {
    e[++tot] = (Edge){v, cap, head[u]};
    head[u] = tot;
    e[++tot] = (Edge){u, 0, head[v]};
    head[v] = tot;
  }
  int n, s, t, cur[V], d[V], f[V];
  int dfs(int u, int fl = INF) {
    if (u == t) return fl;
    int ret = 0;
    for (int &i = cur[u]; i; i = e[i].nxt) {
      if (e[i].cap && d[e[i].to] + 1 == d[u]) {
        int tmp = dfs(e[i].to, min(fl, e[i].cap));
        ret += tmp;
        fl -= tmp;
        e[i].cap -= tmp;
        e[i ^ 1].cap += tmp;
        if (!fl) return ret;
      }
    }
    cur[u] = head[u];
    if (!(--f[d[u]])) d[s] = n + 1;
    ++f[++d[u]];
    return ret;
  }
  int maxflow(int _n, int _s, int _t) {
    n = _n;
    s = _s;
    t = _t;
    memset(cur, 0, sizeof cur);
    memset(d, 0, sizeof d);
    memset(f, 0, sizeof f);
    f[0] = n;
    int ret = 0;
    while (d[s] <= n) ret += dfs(s);
    return ret;
  }
} maxflow;
const size_t N = 1e4 + 5;
int gender[N];
int main() {
  int n = read(), m = read(), g = read();
  int S = 0, T = n + m + 1;
  generate_n(gender + 1, n, read);
  for (int i = 1; i <= n; ++i) {
    if (gender[i]) {
      maxflow.addEdge(S, i, read());
    } else {
      maxflow.addEdge(i, T, read());
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    int gender = read(), w = read(), k = read();
    ans += w;
    while (k--) {
      if (gender) {
        maxflow.addEdge(i + n, read(), INF);
      } else {
        maxflow.addEdge(read(), i + n, INF);
      }
    }
    w += read() * g;
    if (gender) {
      maxflow.addEdge(S, i + n, w);
    } else {
      maxflow.addEdge(i + n, T, w);
    }
  }
  ans -= maxflow.maxflow(T + 1, S, T);
  printf("%d\n", ans);
  return 0;
}
