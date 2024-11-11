#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, mod = 998244353;
int to[N], prv[N], head[N], ecnt;
long long d[N], cap[N];
int ptr[N];
void add_edge(int x, int y, long long c) {
  to[ecnt] = y, cap[ecnt] = c, prv[ecnt] = head[x], head[x] = ecnt++;
  c = 0;
  swap(x, y);
  to[ecnt] = y, cap[ecnt] = c, prv[ecnt] = head[x], head[x] = ecnt++;
}
bool bfs(int s, int t) {
  memset(d, 0, sizeof d);
  d[s] = 1;
  queue<int> q;
  q.push(s);
  while (q.size()) {
    int x = q.front();
    q.pop();
    if (x == t) return 1;
    for (int e = head[x]; e != -1; e = prv[e]) {
      int v = to[e];
      if (!cap[e] || d[v]) continue;
      d[v] = d[x] + 1;
      q.push(v);
    }
  }
  return 0;
}
long long dfs(int s, int t, long long f) {
  if (s == t) return f;
  long long ans = 0;
  for (int& e = ptr[s]; e != -1; e = prv[e]) {
    if (!cap[e] || d[to[e]] != d[s] + 1) continue;
    long long x = dfs(to[e], t, min(f, cap[e]));
    ans += x;
    cap[e] -= x;
    cap[e ^ 1] += x;
    f -= x;
    if (!f) break;
  }
  return ans;
}
long long max_flow(int s, int t) {
  long long ans = 0;
  while (bfs(s, t)) {
    memcpy(ptr, head, sizeof head);
    for (int i = 0; i < N; i++)
      if (ptr[i] != head[i]) cout << '*' << endl;
    ans += dfs(s, t, 1e18);
  }
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(head, -1, sizeof head);
  int n, m;
  cin >> n >> m;
  int s = N - 1, t = N - 2;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    add_edge(s, i, x);
  }
  long long sum = 0;
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    x--, y--;
    add_edge(x, i + n, 1e17);
    add_edge(y, i + n, 1e17);
    add_edge(i + n, t, w);
    sum += w;
  }
  cout << sum - max_flow(s, t) << endl;
}
