#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct edge {
  int u, v, w, pre;
} e[N * 2];
int dex, adj[N], n, C;
int sz[N], rt, f[N], Col[N], siz[N];
long long dis[N], ans;
set<int> H[N], S[N];
struct node {
  int x, y;
  node(int x = N - 1, int y = N - 1) : x(x), y(y) {}
  node operator+(node A) const {
    node res = *this;
    if (res.x > A.x) swap(res, A);
    if (A.x < res.y && Col[res.x] != Col[A.x]) res.y = A.x;
    if (A.y < res.y && Col[res.x] != Col[A.y]) res.y = A.y;
    return res;
  }
} T[N * 4];
void dfs(int x, int fa) {
  sz[x] = 1;
  for (int i = adj[x]; i; i = e[i].pre) {
    if (e[i].v == fa) continue;
    dfs(e[i].v, x);
    sz[x] += sz[e[i].v];
    f[x] = max(f[x], sz[e[i].v]);
  }
  f[x] = max(f[x], n - sz[x]);
  if (f[x] < f[rt]) rt = x;
}
void Dfs(int x, int fa, long long D) {
  ans += D;
  siz[Col[x] = C]++;
  H[C].insert(x);
  for (int i = adj[x]; i; i = e[i].pre) {
    int v = e[i].v;
    if (v == fa) continue;
    Dfs(v, x, D + e[i].w);
  }
}
void Bud(int x, int L, int R) {
  if (L == R) {
    T[x] = (node){L, N - 1};
    return;
  }
  int md = (L + R) >> 1;
  Bud(x * 2, L, md);
  Bud(x * 2 + 1, md + 1, R);
  T[x] = T[x * 2] + T[x * 2 + 1];
}
void Mod(int x, int L, int R, int v) {
  if (L == R) {
    T[x] = (node){N - 1, N - 1};
    return;
  }
  int md = (L + R) >> 1;
  if (v <= md)
    Mod(x * 2, L, md, v);
  else
    Mod(x * 2 + 1, md + 1, R, v);
  T[x] = T[x * 2] + T[x * 2 + 1];
}
void jian(int x) {
  if (!siz[x]) return;
  S[siz[x]].erase(x);
  --siz[x];
  if (!siz[x]) return;
  S[siz[x]].insert(x);
}
int main() {
  scanf("%d", &n);
  for (int i = (int)1; i <= (int)n - 1; i++) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    e[++dex] = (edge){x, y, w, adj[x]};
    adj[x] = dex;
    e[++dex] = (edge){y, x, w, adj[y]};
    adj[y] = dex;
  }
  f[0] = 2100000000;
  Col[N - 1] = N - 1;
  dfs(1, 0);
  for (int i = adj[rt]; i; i = e[i].pre) {
    int v = e[i].v;
    C = v;
    Dfs(v, rt, e[i].w);
    S[siz[C] *= 2].insert(C);
  }
  printf("%I64d\n", ans * 2ll);
  Bud(1, 1, n);
  for (int i = (int)1; i <= (int)n; i++) {
    int k = n - i + 1, cho = 0;
    for (set<int>::iterator it = S[k].begin(); it != S[k].end(); it++) {
      if (*it == Col[i]) continue;
      cho = *H[*it].begin();
      break;
    }
    if (!cho) {
      if (i == rt)
        cho = T[1].x;
      else if (Col[T[1].x] == Col[i])
        cho = T[1].y;
      else
        cho = T[1].x;
    }
    Mod(1, 1, n, cho);
    jian(Col[i]);
    jian(Col[cho]);
    H[Col[cho]].erase(cho);
    printf("%d ", cho);
  }
  puts("");
  return 0;
}
