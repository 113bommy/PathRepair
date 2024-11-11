#include <bits/stdc++.h>
using namespace std;
const int MAX = 200500;
int inp[MAX];
int out[MAX];
bool flag[MAX];
map<long long, int> ID;
map<long long, int> hasInp;
namespace hopcroftKarp {
int ptr[200011], next[400011], zu[400011];
int n, m, match[200011], D[200011], q[200011];
void init(int _n) {
  n = _n;
  m = 0;
  memset(ptr, ~0, sizeof(int) * (n + 1));
}
void add_edge(int u, int v) {
  next[m] = ptr[u];
  ptr[u] = m;
  zu[m] = v;
  ++m;
}
bool bfs() {
  int u, v;
  register int i;
  int qh = 0, qt = 0;
  for (i = 1; i <= n; i++) {
    if (!match[i]) {
      D[i] = 0;
      q[qt++] = i;
    } else
      D[i] = (1 << 28);
  }
  D[0] = (1 << 28);
  while (qh < qt) {
    u = q[qh++];
    if (u != 0) {
      for (i = ptr[u]; ~i; i = next[i]) {
        v = zu[i];
        if (D[match[v]] == (1 << 28)) {
          D[match[v]] = D[u] + 1;
          q[qt++] = match[v];
        }
      }
    }
  }
  return D[0] != (1 << 28);
}
bool dfs(int u) {
  int v;
  register int i;
  if (u) {
    for (i = ptr[u]; ~i; i = next[i]) {
      v = zu[i];
      if (D[match[v]] == D[u] + 1) {
        if (dfs(match[v])) {
          match[v] = u;
          match[u] = v;
          return true;
        }
      }
    }
    D[u] = (1 << 28);
    return false;
  }
  return true;
}
int run() {
  int matching = 0;
  register int i;
  while (bfs())
    for (i = 1; i <= n; i++)
      if (!match[i] && dfs(i)) matching++;
  return matching;
}
void call(int N, long long a, long long b) {
  int x, y;
  long long vx, vy;
  for (int i = 1; i <= N; i++) {
    if (flag[i]) continue;
    x = i;
    y = match[x];
    vx = inp[i];
    vy = inp[y];
    if (vx + vy == a) {
      out[x] = out[y] = 0;
    } else
      out[x] = out[y] = 1;
    flag[x] = flag[y] = true;
  }
  for (int i = 1; i <= N; i++) {
    if (i != 1) cout << " ";
    cout << out[i];
  }
  cout << "\n";
  return;
}
};  // namespace hopcroftKarp
int main() {
  long long a, b;
  int n;
  std::ios_base::sync_with_stdio(false);
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> inp[i];
    hasInp[inp[i]] = i;
  }
  long long x, rx, tx;
  int p = 0;
  hopcroftKarp::init(n + n);
  for (int i = 1; i <= n; i++) {
    x = inp[i];
    rx = a - x;
    tx = b - x;
    if (x == rx || x == tx) {
      hopcroftKarp::add_edge(i, i + p);
      inp[i + p] = x;
      p++;
    }
    if (hasInp.find(rx) != hasInp.end() && !flag[hasInp[rx]]) {
      hopcroftKarp::add_edge(i, hasInp[rx]);
    }
    if (hasInp.find(tx) != hasInp.end() && !flag[hasInp[tx]]) {
      hopcroftKarp::add_edge(i, hasInp[tx]);
    }
  }
  int cnt = hopcroftKarp::run();
  if (2 * cnt >= (n)) {
    cout << "YES\n";
    hopcroftKarp::call(n, a, b);
  } else
    cout << "NO\n";
  return 0;
}
