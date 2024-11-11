#include <bits/stdc++.h>
using namespace std;
const int maxn = 300500;
const int P = 1e9 + 7;
const int P2 = 998244353;
const int N = 262144;
int n, m, x, y, idx, scc, tot;
int dfn[maxn], low[maxn], bl[maxn];
int a[maxn], b[maxn], a2[maxn], b2[maxn];
vector<int> g[maxn], vec[maxn];
stack<int> st;
struct edge {
  int x, y, c;
} e[maxn];
void tarjan(int u, int fa) {
  st.push(u);
  dfn[u] = low[u] = ++idx;
  for (auto v : g[u]) {
    if (v == fa) continue;
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
    } else if (!bl[v])
      low[u] = min(low[u], dfn[v]);
  }
  if (dfn[u] == low[u]) {
    ++scc;
    while (1) {
      int x = st.top();
      st.pop();
      bl[x] = scc;
      if (x == u) break;
    }
  }
}
void fwt(int a[], int n, int P) {
  int inv2 = (P + 1) / 2;
  for (int d = 1; d < n; d <<= 1)
    for (int m = d << 1, i = 0; i < n; i += m)
      for (int j = 0; j < d; j++) {
        int x = a[i + j], y = a[i + j + d];
        a[i + j] = (x + y) % P;
        a[i + j + d] = (x - y + P) % P;
      }
}
void ufwt(int a[], int n, int P) {
  int inv2 = (P + 1) / 2;
  for (int d = 1; d < n; d <<= 1)
    for (int m = d << 1, i = 0; i < n; i += m)
      for (int j = 0; j < d; j++) {
        int x = a[i + j], y = a[i + j + d];
        a[i + j] = 1ll * (x + y) * inv2 % P;
        a[i + j + d] = 1ll * (x - y + P) * inv2 % P;
      }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    g[x].push_back(y);
    g[y].push_back(x);
    e[++tot] = {x, y, c};
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i, 0);
  for (int i = 1; i <= m; i++) {
    int x = e[i].x, y = e[i].y, c = e[i].c;
    if (bl[x] == bl[y]) {
      vec[bl[x]].push_back(c);
    } else {
      ans ^= c;
    }
  }
  a[ans] = 1;
  a2[ans] = 1;
  fwt(a, N, P);
  fwt(a2, N, P2);
  for (int i = 1; i <= scc; i++)
    if (vec[i].size()) {
      int res = 0;
      for (auto x : vec[i]) res ^= x;
      for (int j = 0; j <= N; j++) b[j] = b2[j] = 0;
      for (auto x : vec[i]) b[res ^ x]++, b2[res ^ x]++;
      fwt(b, N, P);
      fwt(b2, N, P2);
      for (int j = 0; j <= N - 1; j++) {
        a[j] = 1ll * a[j] * b[j] % P;
        a2[j] = 1ll * a2[j] * b2[j] % P2;
      }
    }
  ufwt(a, N, P);
  ufwt(a2, N, P2);
  for (int i = 0; i <= N; i++)
    if (a[i] && a2[i]) {
      printf("%d %d\n", i, a[i]);
      break;
    }
  return 0;
}
