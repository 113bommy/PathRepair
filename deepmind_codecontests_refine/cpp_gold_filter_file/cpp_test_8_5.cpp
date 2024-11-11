#include <bits/stdc++.h>
using namespace std;
void read(int& x) { scanf("%d", &x); }
void read(long long& x) { scanf("%lld", &x); }
void read(double& x) { scanf("%lf", &x); }
long long gcd(long long x, long long y) {
  while (y) {
    long long t = x % y;
    x = y;
    y = t;
  }
  return x;
}
void update(vector<long long>& b, int sp, int x, long long val) {
  x += sp;
  b[x] = val;
  x >>= 1;
  while (x >= 1) {
    b[x] = b[x << 1] + b[(x << 1) + 1];
    x >>= 1;
  }
}
long long query(vector<long long>& b, int sp, int s, int e) {
  s += sp;
  e += sp;
  long long ret = 0;
  while (s <= e) {
    if (s == e) {
      ret += b[s];
      break;
    }
    if (s & 1) {
      ret += b[s];
      s = (s + 1) >> 1;
    } else
      s >>= 1;
    if (e & 1)
      e >>= 1;
    else {
      ret += b[e];
      e = (e - 1) >> 1;
    }
  }
  return ret;
}
int lca(int u, int v, vector<vector<int>>& pars, vector<int>& h) {
  int d = h[v] - h[u];
  for (int k = 0; d; k++, d >>= 1) {
    if (d & 1) v = pars[v][k];
  }
  if (u == v) return u;
  for (int k = pars[u].size() - 1; k >= 0; k--) {
    if (k >= pars[u].size() || pars[u][k] == pars[v][k]) continue;
    u = pars[u][k];
    v = pars[v][k];
  }
  return pars[u][0];
}
void print_tree(int sp, vector<long long>& b) {
  for (int i = 1; i < (sp * 2); i++) {
    printf("%d ", b[i]);
    if ((i & (i + 1)) == 0) printf("\n");
  }
  printf("\n");
}
void solve() {
  int n, q;
  scanf("%d%d", &n, &q);
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    if (a[i] < 0) a[i] = -a[i];
  }
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> h(n + 1, -1);
  vector<vector<int>> pars(n + 1);
  {
    vector<int> q;
    q.push_back(1);
    int hd = 0;
    h[1] = 0;
    while (hd < q.size()) {
      int u = q[hd++];
      if (pars[u].size()) {
        for (int k = 1; k - 1 < pars[pars[u][k - 1]].size(); k++) {
          pars[u].push_back(pars[pars[u][k - 1]][k - 1]);
        }
      }
      for (auto v : adj[u]) {
        if (h[v] != -1) continue;
        q.push_back(v);
        h[v] = h[u] + 1;
        pars[v].push_back(u);
      }
    }
  }
  vector<int> tour;
  vector<int> finds(n + 1), binds(n + 1);
  {
    stack<int> stk;
    stk.push(1);
    while (stk.size()) {
      int u = stk.top();
      stk.pop();
      tour.push_back(u);
      if (u < 0)
        binds[-u] = tour.size() - 1;
      else {
        finds[u] = tour.size() - 1;
        stk.push(-u);
        for (auto v : adj[u])
          if (h[v] == h[u] + 1) stk.push(v);
      }
    }
  }
  int m = tour.size();
  int sp = 1;
  while (sp < m) sp <<= 1;
  vector<long long> b(sp << 1);
  for (int i = 0; i < m; i++) {
    if (tour[i] < 0)
      b[sp + i] = -a[-tour[i]];
    else
      b[sp + i] = a[tour[i]];
  }
  for (int i = sp - 1; i >= 1; i--) {
    b[i] = b[i << 1] + b[(i << 1) + 1];
  }
  while (q--) {
    int t, u, v;
    scanf("%d%d%d", &t, &u, &v);
    if (t == 1) {
      a[u] = (long long)(abs(v));
      update(b, sp, finds[u], a[u]);
      update(b, sp, binds[u], -a[u]);
    } else {
      if (u == v) {
        printf("0\n");
        continue;
      }
      if (h[u] > h[v]) swap(u, v);
      int r = lca(u, v, pars, h);
      if (r == u) {
        long long val = query(b, sp, finds[u], finds[v]);
        printf("%lld\n", 2 * val - a[u] - a[v]);
      } else {
        long long val = query(b, sp, finds[r], finds[u]) +
                        query(b, sp, finds[r], finds[v]) - a[r];
        printf("%lld\n", 2 * val - a[u] - a[v]);
      }
    }
  }
}
int main() {
  solve();
  return 0;
}
