#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T Tmin(const T &lch, const T &rch) {
  if (lch < rch) return lch;
  return rch;
}
template <class T>
inline T Tmax(const T &lch, const T &rch) {
  if (lch < rch) return rch;
  return lch;
}
template <class T>
inline T Tabs(const T &ch) {
  if (ch < 0) return -ch;
  return ch;
}
const int Inf = 0x3f3f3f3f;
const int Mod = 998244353;
const unsigned long long Rp = 1e9 + 9;
const int Gp = 3;
inline int R_int() {
  register int n = 0;
  register char ch = getchar();
  register bool I = false;
  while (ch < '0' || ch > '9') I = (ch == '-' ? 1 : 0), ch = getchar();
  while (ch >= '0' && ch <= '9')
    n = (n << 1) + (n << 3) + (ch ^ '0'), ch = getchar();
  return I ? -n : n;
}
inline int Add(int a, int b) {
  int ans = (a + b);
  ans = (ans >= Mod ? ans - Mod : ans);
  return ans;
}
inline int Mis(int a, int b) {
  int ans = a - b;
  ans = (ans < 0 ? ans + Mod : ans);
  return ans;
}
inline int Mul(int a, int b) { return a * 1ll * b % Mod; }
inline int Pow(int a, long long k) {
  int ans = 1;
  while (k) {
    if (k & 1) ans = Mul(ans, a);
    a = Mul(a, a);
    k = k >> 1;
  }
  return ans;
}
const int maxn = 500000 + 10;
struct Edge {
  int to, next;
  Edge() {}
  Edge(int to, int next) {
    this->to = to;
    this->next = next;
  }
};
Edge edges[maxn << 1];
int Dist[maxn];
bool vis[maxn];
int son[maxn];
int prt[maxn];
int G[maxn];
int tot = 0;
int n, m, k;
inline void AddEdge(int from, int to) {
  edges[++tot] = Edge(to, G[from]);
  G[from] = tot;
}
inline void Dfs(int u) {
  vis[u] = 1;
  for (int i = G[u]; i != 0; i = edges[i].next) {
    int t = edges[i].to;
    if (vis[t]) continue;
    Dist[t] = Dist[u] + 1;
    prt[t] = u;
    son[u]++;
    Dfs(t);
  }
}
signed main() {
  n = R_int(), m = R_int(), k = R_int();
  for (int i = 1, x, y; i <= m; i++) {
    x = R_int();
    y = R_int();
    AddEdge(x, y);
    AddEdge(y, x);
  }
  Dist[1] = 1;
  Dfs(1);
  int lim = n / k + 1;
  for (int i = 1; i <= n; i++) {
    if (Dist[i] >= lim) {
      printf("PATH\n%d\n", Dist[i]);
      for (int x = i; x; x = prt[x]) {
        printf("%d ", x);
      }
      putchar('\n');
      return 0;
    }
  }
  printf("CYCLES\n");
  for (int u = 1; u <= n; u++) {
    if (!son[u]) {
      int a = -1, b = -1;
      for (int i = G[u]; i != 0; i = edges[i].next) {
        int t = edges[i].to;
        if (t == prt[u]) continue;
        if (a == -1)
          a = t;
        else if (b == -1)
          b = t;
      }
      if (Dist[a] < Dist[b]) swap(a, b);
      if ((Dist[u] - Dist[a] + 1) % 3) {
        printf("%d\n", Dist[u] - Dist[a] + 1);
        for (int x = u; x != prt[a]; x = prt[x]) {
          printf("%d ", x);
        }
        putchar('\n');
      } else if ((Dist[u] - Dist[b] + 1) % 3) {
        printf("%d\n", Dist[u] - Dist[b] + 1);
        for (int x = u; x != prt[b]; x = prt[x]) {
          printf("%d ", x);
        }
        putchar('\n');
      } else if ((Dist[a] - Dist[b] + 2) % 3) {
        printf("%d\n", Dist[a] - Dist[b] + 2);
        for (int x = a; x != prt[b]; x = prt[x]) {
          printf("%d ", x);
        }
        putchar('\n');
      }
      k--;
      if (!k) break;
    }
  }
  return 0;
}
