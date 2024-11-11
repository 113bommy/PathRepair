#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long OO = 1e18;
const int N = 5e5 + 100;
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
int cnt;
int fa[N], rk[N];
inline int find(int x) {
  ++cnt;
  return fa[x] == x ? x : find(fa[x]);
}
int u[N], v[N], w[N], id[N];
vector<int> p[N], q[N];
bool ans[N];
int st[N], in[N];
int *x[N * 2], y[N * 2], all;
inline bool merge(int a, int b) {
  cnt = 0;
  a = find(a), b = find(b);
  if (cnt > 100) printf("TLE"), exit(0);
  if (a == b) return false;
  if (rk[a] > rk[b])
    swap(a, b);
  else if (rk[a] == rk[b])
    x[++all] = &rk[a], y[all] = rk[a]++;
  x[++all] = &fa[a], y[all] = fa[a], fa[a] = b;
  return true;
}
int main() {
  int n = gi(), m = gi(), Q, i, k, l, r, top = 0, last;
  for (i = 1; i <= n; i++) fa[i] = i;
  for (i = 1; i <= m; i++) u[id[i] = i] = gi(), v[i] = gi(), w[i] = gi();
  sort(id + 1, id + 1 + m, [&](int a, int b) { return w[a] < w[b]; });
  Q = gi();
  for (i = 1; i <= Q; ans[i++] = true)
    for (k = gi(); k; k--) p[gi()].push_back(i);
  for (l = 1; l <= m; l = r) {
    for (r = l; w[id[l]] == w[id[r]]; r++)
      ;
    for (i = l; i < r; i++)
      for (int t : p[id[i]]) {
        if (!in[t]) st[in[t] = ++top] = t;
        q[in[t]].push_back(id[i]);
      }
    for (i = 1; i <= top; i++) {
      last = all;
      for (int t : q[i])
        if (!merge(u[t], v[t])) ans[st[i]] = false;
      while (all > last) *x[all] = y[all], all--;
    }
    for (i = l; i < r; i++) merge(u[id[i]], v[id[i]]);
    while (top) q[top].clear(), in[st[top--]] = 0;
  }
  for (i = 1; i <= Q; i++) puts(ans[i] ? "YES" : "NO");
  return 0;
}
