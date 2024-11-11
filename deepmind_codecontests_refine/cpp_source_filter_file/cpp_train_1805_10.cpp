#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
const int N = 200;
const int E = 4000;
const int MOD = 1e9 + 7;
const long double eps = 1e-12;
int n, k, s[N], t[N], c[N], from[E], to[E], cap[E], prv[E], head[E], cost[E],
    d[N], par[N], isWhat[E], ans[N], ecnt;
void add_edge(int u, int v, int c, int cst) {
  from[ecnt] = u, to[ecnt] = v, cap[ecnt] = c, cost[ecnt] = -cst,
  prv[ecnt] = head[u], head[u] = ecnt++;
  from[ecnt] = v, to[ecnt] = u, cap[ecnt] = 0, cost[ecnt] = +cst,
  prv[ecnt] = head[v], head[v] = ecnt++;
}
void solve(int source, int sink) {
  memset(d, 63, sizeof(d));
  memset(par, 0, sizeof(par));
  queue<int> q;
  q.push(source);
  par[source] = -1;
  d[source] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = head[v]; i != -1; i = prv[i]) {
      int u = to[i];
      if (d[u] > d[v] + cost[i] && (cap[i] > 0)) {
        d[u] = d[v] + cost[i];
        par[u] = i;
        q.push(u);
      }
    }
  }
  int v = sink;
  while (v != source) {
    cap[par[v]]--;
    cap[par[v] ^ 1]++;
    v = from[par[v]];
  }
}
int main() {
  memset(head, -1, sizeof(head));
  memset(isWhat, -1, sizeof(isWhat));
  n = in();
  k = in();
  vector<int> vec;
  for (int i = 0; i < n; i++) {
    s[i] = in(), t[i] = in(), c[i] = in();
    vec.push_back(s[i]);
    vec.push_back(s[i] + t[i]);
  }
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  for (int i = 0; i < n; i++) {
    int s1 = 0, t1 = 0;
    s1 = lower_bound(vec.begin(), vec.end(), s[i]) - vec.begin();
    t1 = lower_bound(vec.begin(), vec.end(), s[i] + t[i]) - vec.begin();
    isWhat[ecnt] = i;
    add_edge(s1, t1, 1, c[i]);
  }
  for (int i = 0; i < vec.size() - 1; i++) add_edge(i, i + 1, MOD, 0);
  for (int i = 0; i < k; i++) solve(0, vec.size() - 1);
  for (int i = 0; i < ecnt; i++) {
    if (cap[i] == 0 && cost[i] < 0 && isWhat[i] != -1) ans[isWhat[i]] = 1;
  }
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  return 0;
}
