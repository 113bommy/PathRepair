#include <bits/stdc++.h>
using namespace std;
int n, m;
int s, t;
struct Edge {
  int from, to, next;
  int cap, flow;
  void get(int u, int a, int b, int c, int d) {
    from = u;
    to = a;
    next = b;
    cap = c;
    flow = d;
  }
} edge[20005];
int tol;
int head[205];
int gap[205], dep[205], pre[205], cur[205];
bool is_prime[20005];
void init() {
  memset(is_prime, 1, sizeof is_prime);
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i < 20005; i++)
    if (is_prime[i]) {
      for (int j = i + i; j < 20005; j += i) is_prime[j] = 0;
    }
  tol = 0;
  memset(head, -1, sizeof head);
}
void add_edge(int u, int v, int w, int rw = 0) {
  edge[tol].get(u, v, head[u], w, 0);
  head[u] = tol++;
  edge[tol].get(v, u, head[v], rw, 0);
  head[v] = tol++;
}
int sap(int start, int end, int N) {
  memset(gap, 0, sizeof gap);
  memset(dep, 0, sizeof dep);
  memcpy(cur, head, sizeof head);
  int u = start;
  pre[u] = -1;
  gap[0] = N;
  int ans = 0;
  while (dep[start] < N) {
    if (u == end) {
      int Min = 1e8;
      for (int i = pre[u]; i != -1; i = pre[edge[i ^ 1].to])
        if (Min > edge[i].cap - edge[i].flow) Min = edge[i].cap - edge[i].flow;
      for (int i = pre[u]; i != -1; i = pre[edge[i ^ 1].to]) {
        edge[i].flow += Min;
        edge[i ^ 1].flow -= Min;
      }
      u = start;
      ans += Min;
      continue;
    }
    bool flag = false;
    int v;
    for (int i = cur[u]; i != -1; i = edge[i].next) {
      v = edge[i].to;
      if (edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u]) {
        flag = true;
        cur[u] = pre[v] = i;
        break;
      }
    }
    if (flag) {
      u = v;
      continue;
    }
    int Min = N;
    for (int i = head[u]; i != -1; i = edge[i].next)
      if (edge[i].cap - edge[i].flow && dep[edge[i].to] < Min) {
        Min = dep[edge[i].to];
        cur[u] = i;
      }
    gap[dep[u]]--;
    if (!gap[dep[u]]) return ans;
    dep[u] = Min + 1;
    gap[dep[u]]++;
    if (u != start) u = edge[pre[u] ^ 1].to;
  }
  return ans;
}
int a[205], k;
vector<int> table[205], con[205];
bool vis[205];
void dfs(int u) {
  if (vis[u]) return;
  table[k].push_back(u);
  vis[u] = 1;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].to;
    if (edge[i].flow && !vis[v]) {
      table[k].push_back(v);
      vis[v] = 1;
      dfs(con[v][0] == u ? con[v][1] : con[v][0]);
      break;
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    con[i].clear();
  }
  init();
  int N;
  s = 0, t = n + 1, N = t + 1;
  int odd = 0, even = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] & 1) {
      odd++;
      add_edge(s, i, 2);
      for (int j = 1; j <= n; j++)
        if (a[j] % 2 == 0 && is_prime[a[i] + a[j]]) {
          add_edge(i, j, 1);
        }
    } else {
      even++;
      add_edge(i, t, 2);
    }
  }
  if (odd != even) {
    cout << "Impossible" << endl;
    return 0;
  }
  int ans = sap(s, t, N);
  if (ans != even * 2) {
    cout << "Impossible" << endl;
    return 0;
  }
  k = 0;
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= n; i++)
    if (a[i] & 1) {
      for (int j = head[i]; j != -1; j = edge[j].next) {
        int v = edge[j].to;
        if (edge[j].flow) {
          con[v].push_back(i);
        }
      }
    }
  for (int i = 1; i <= n; i++)
    if ((a[i] & 1) && !vis[i]) {
      table[++k].clear();
      dfs(i);
    }
  cout << k << endl;
  for (int i = 1; i <= k; i++) {
    int sz = table[k].size();
    cout << sz << " ";
    for (int j = 0; j < sz; j++) {
      cout << table[i][j] << (j == sz - 1 ? '\n' : ' ');
    }
  }
  return 0;
}
