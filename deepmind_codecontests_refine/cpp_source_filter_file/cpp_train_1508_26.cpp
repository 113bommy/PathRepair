#include <bits/stdc++.h>
using namespace std;
int n, a[205];
int c[205][205], f[205][205];
int mf, s, t;
int cl[205], q[205], pre[205];
int fac[10004], np, pr[10004];
int deg[205], slt, sl[205];
vector<int> g[205];
vector<int> lt[205];
bool findp() {
  for (int i = 1; i <= t; ++i) cl[i] = 0;
  int L = 1, R = 0;
  cl[s] = 1;
  q[++R] = s;
  pre[s] = 0;
  while (L <= R) {
    int u = q[L++];
    for (int v = 1; v <= t; ++v)
      if (f[u][v] < c[u][v] && cl[v] == 0) {
        cl[v] = 1;
        q[++R] = v;
        pre[v] = u;
        if (v == t) return 1;
      }
    for (int v = 1; v <= t; ++v)
      if (f[v][u] > 0 && cl[v] == 0) {
        cl[v] = 1;
        q[++R] = v;
        pre[v] = -u;
      }
  }
  return 0;
}
void incf() {
  int d = 1e9, v = t;
  while (pre[v]) {
    int u = pre[v];
    if (u > 0)
      d = min(d, c[u][v] - f[u][v]);
    else {
      u = -u;
      d = min(d, f[v][u]);
    }
    v = u;
  }
  mf += d;
  v = t;
  while (pre[v]) {
    int u = pre[v];
    if (u > 0)
      f[u][v] += d;
    else {
      u = -u;
      f[v][u] -= d;
    }
    v = u;
  }
}
void sang(int n) {
  for (int i = 2; i <= n; ++i) {
    if (fac[i] == 0) {
      fac[i] = i;
      pr[++np] = i;
    }
    int j = 1;
    while (j <= np && pr[j] <= n / i) {
      fac[pr[j] * i] = pr[j];
      ++j;
    }
  }
}
void dfs(int u) {
  cl[u] = 1;
  lt[slt].push_back(u);
  sl[slt]++;
  for (int i = 0; i < deg[u]; ++i) {
    int v = g[u][i];
    if (cl[v] == 0) dfs(v);
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  sang(10000);
  cin >> n;
  s = n + 1;
  t = n + 2;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] % 2)
      c[s][i] = 2;
    else
      c[i][t] = 2;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (a[i] % 2 && a[j] % 2 == 0 && fac[a[i] + a[j]] == a[i] + a[j])
        c[i][j] = 1;
  while (findp()) incf();
  if (mf < n) {
    cout << "Impossible";
    return 0;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (f[i][j]) {
        deg[i]++;
        g[i].push_back(j);
        deg[j]++;
        g[j].push_back(i);
      }
  memset(cl, 0, sizeof(cl));
  for (int i = 1; i <= n; ++i)
    if (cl[i] == 0) {
      ++slt;
      dfs(i);
    }
  cout << slt << "\n";
  for (int i = 1; i <= slt; ++i) {
    cout << sl[i] << " ";
    for (int j = 0; j < sl[i]; ++j) cout << lt[i][j] << " ";
    cout << "\n";
  }
}
