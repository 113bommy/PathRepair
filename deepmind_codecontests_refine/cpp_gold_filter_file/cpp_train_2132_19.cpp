#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void mx(T& x, const T& y) {
  if (x < y) x = y;
}
template <typename T>
inline void mn(T& x, const T& y) {
  if (y < x) x = y;
}
template <typename T>
inline int sz(const T& x) {
  return (int)x.size();
}
bool isPrime[25000];
const int N = 1 + 100 + 100 + 1;
const int M = 2 * (100 + 10000 + 100);
int nodes;
int edges;
int S;
int T;
int head[N], dhead[N], linke[M], cap[M], dest[M], lvl[N];
int q[N];
inline void addArc(int u, int v, int c) {
  cap[edges] = c;
  dest[edges] = v;
  linke[edges] = head[u];
  head[u] = edges++;
  cap[edges] = 0;
  dest[edges] = u;
  linke[edges] = head[v];
  head[v] = edges++;
}
bool bfs() {
  fill(lvl, lvl + nodes, -1);
  int qh = 0, qt = 0;
  lvl[S] = 0;
  q[qt++] = S;
  while (qh != qt) {
    int u = q[qh++];
    for (int arc = head[u]; arc != -1; arc = linke[arc]) {
      int v = dest[arc];
      if (cap[arc] > 0 && lvl[v] == -1) {
        lvl[v] = lvl[u] + 1;
        q[qt++] = v;
      }
    }
  }
  return lvl[T] != -1;
}
inline int dfs(int u, int f) {
  if (u == T || f == 0) {
    return f;
  }
  for (int& arc = dhead[u]; arc != -1; arc = linke[arc]) {
    int v = dest[arc];
    if (cap[arc] > 0 && lvl[v] == lvl[u] + 1) {
      int pushed = dfs(v, min(f, cap[arc]));
      if (pushed > 0) {
        cap[arc] -= pushed;
        cap[arc ^ 1] += pushed;
        return pushed;
      }
    }
  }
  return 0;
}
vector<vector<int>> g;
vector<bool> used;
vector<vector<int>> comps;
void dfs(int u) {
  used[u] = true;
  comps.back().push_back(u);
  for (int v : g[u]) {
    if (!used[v]) {
      dfs(v);
      break;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < (n); ++i) {
    cin >> a[i];
  }
  vector<int> even, odd;
  for (int i = 0; i < (n); ++i) {
    (a[i] % 2 == 0 ? even : odd).push_back(i);
  }
  if (sz(even) != sz(odd)) {
    cout << "Impossible" << endl;
    return 0;
  }
  fill(isPrime, isPrime + 25000, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= 25000; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j <= 25000; j += i) {
        isPrime[j] = false;
      }
    }
  }
  nodes = n + 2;
  edges = 0;
  S = n;
  T = n + 1;
  fill(head, head + nodes, -1);
  for (int i = 0; i < (sz(even)); ++i) {
    addArc(S, i, 2);
  }
  for (int i = 0; i < (sz(even)); ++i) {
    for (int j = 0; j < (sz(odd)); ++j) {
      int u = even[i];
      int v = odd[j];
      if (isPrime[a[u] + a[v]]) {
        addArc(i, sz(even) + j, 1);
      }
    }
  }
  for (int i = 0; i < (sz(odd)); ++i) {
    addArc(sz(even) + i, T, 2);
  }
  int f = 0;
  while (bfs()) {
    copy(head, head + nodes, dhead);
    int pushed;
    while ((pushed = dfs(S, 1000000)) > 0) {
      f += pushed;
    }
  }
  if (f != 2 * sz(even)) {
    cout << "Impossible" << endl;
    return 0;
  }
  g.assign(n, vector<int>());
  for (int i = 0; i < (sz(even)); ++i) {
    for (int arc = head[i]; arc != -1; arc = linke[arc]) {
      int j = dest[arc];
      if (j != S && cap[arc] == 0) {
        j -= sz(even);
        int u = even[i];
        int v = odd[j];
        g[u].push_back(v);
        g[v].push_back(u);
      }
    }
  }
  used.assign(n, false);
  for (int i = 0; i < (n); ++i) {
    if (!used[i]) {
      comps.push_back(vector<int>());
      dfs(i);
    }
  }
  cout << sz(comps) << endl;
  for (int i = 0; i < (sz(comps)); ++i) {
    cout << sz(comps[i]);
    for (int x : comps[i]) {
      cout << ' ' << x + 1;
    }
    cout << endl;
  }
  return 0;
}
