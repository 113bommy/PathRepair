#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read() {
  T sum = 0, fl = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') fl = -1;
  for (; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + ch - '0';
  return sum * fl;
}
const int maxn = 5000 + 5;
const int maxm = 1e5 + 5;
int n, m, k, c;
long long mx[maxn];
bool del[maxm << 1], no[maxn];
int fa[maxn], id[maxm << 1];
vector<int> vec, E;
int he[maxn], ne[maxm << 1], to[maxm << 1], w[maxm << 1];
struct EDGE {
  int u, v, w, id;
} e[maxn];
bool operator<(const EDGE& a, const EDGE& b) { return a.w < b.w; }
void add_edge(int u, int v, int val) {
  ne[++c] = he[u];
  he[u] = c;
  to[c] = v;
  w[c] = val;
  ne[++c] = he[v];
  he[v] = c;
  to[c] = u;
  w[c] = val;
}
int find(int first) {
  return fa[first] == first ? first : fa[first] = find(fa[first]);
}
void forest() {
  for (int i = 1; i <= n; ++i) fa[i] = i;
  sort(e + 1, e + m + 1);
  for (int i = 1; i <= m; ++i) {
    int u = find(e[i].u), v = find(e[i].v);
    if (u == v || u == 1 || v == 1) continue;
    fa[u] = v;
    E.push_back(e[i].id);
    add_edge(e[i].u, e[i].v, e[i].w);
    id[c] = id[c - 1] = e[i].id;
  }
}
void get_max(int p, int f) {
  for (int i = he[p]; i; i = ne[i]) {
    if (to[i] == f || del[i] || to[i] == 1) continue;
    if (w[i] >= w[mx[p]])
      mx[to[i]] = i;
    else
      mx[to[i]] = mx[p];
    get_max(to[i], p);
  }
}
void Solve() {
  n = read<int>(), m = read<int>(), k = read<int>();
  c = 1;
  for (int i = 1; i <= m; ++i)
    e[i] = (EDGE){read<int>(), read<int>(), read<int>(), i};
  forest();
  for (int i = 1; i <= m; ++i) {
    if (e[i].u != 1 && e[i].v != 1) continue;
    int u = find(e[i].u), v = find(e[i].v);
    if (u == v)
      vec.push_back(i);
    else
      fa[u] = v, add_edge(e[i].u, e[i].v, e[i].w), E.push_back(e[i].id), --k;
  }
  for (int i = 2; i <= n; ++i)
    if (find(i) != find(i - 1)) return (void)printf("-1");
  if (k < 0) return (void)printf("-1");
  for (int i = 1; i <= k; ++i) {
    memset(mx, 0, sizeof(mx));
    for (int j = he[1]; j; j = ne[j]) get_max(to[j], 1);
    int now = -1, ans = 2147483647;
    for (int j = vec.size() - 1; j >= 0; --j) {
      int p = vec[j], var = max(e[p].u, e[p].v);
      if (e[p].w - w[mx[var]] < ans) ans = e[p].w - w[mx[var]], now = j;
    }
    int p = vec[now], var = e[p].u == 1 ? e[p].v : e[p].u;
    add_edge(e[p].v, e[p].u, e[p].w);
    E.push_back(e[p].id);
    no[id[var]] = 1;
    del[mx[var]] = del[mx[var] ^ 1] = 1;
    vec.erase(vec.begin() + now);
  }
  printf("%d\n", n - 1);
  for (int i = E.size() - 1; i >= 0; --i)
    if (!no[E[i]]) printf("%d ", E[i]);
}
int main() {
  Solve();
  return 0;
}
