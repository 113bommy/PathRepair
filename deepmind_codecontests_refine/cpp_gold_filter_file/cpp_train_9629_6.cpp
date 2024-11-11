#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
struct qw {
  int u, v, next;
} side[N];
struct er {
  int u, v;
} w;
int n, m;
int head[N], siz[N], ceng[N], son[N], nowson = 0;
int ls[N][30];
char color[N];
bool ans[N];
vector<er> p[N];
void add(int u, int v, int idx) {
  side[idx].u = u;
  side[idx].v = v;
  side[idx].next = head[u];
  head[u] = idx;
}
void dfs(int u, int f) {
  siz[u] = 1;
  for (int i = head[u]; i != -1; i = side[i].next) {
    int v = side[i].v;
    if (f == v) continue;
    ceng[v] = ceng[u] + 1;
    dfs(v, u);
    siz[u] += siz[v];
    if (son[u] == 0 || siz[v] > siz[son[u]]) son[u] = v;
  }
}
void cel(int u, int f, int val) {
  ls[ceng[u]][color[u] - 'a'] += val;
  for (int i = head[u]; i != -1; i = side[i].next) {
    int v = side[i].v;
    if (v == f || v == nowson) continue;
    cel(v, u, val);
  }
}
bool find(int u) {
  int suma = 0, sumb = 0;
  for (int i = 0; i < 26; i++) {
    suma += ls[u][i];
    sumb += ls[u][i] / 2;
  }
  if (sumb * 2 + 1 >= suma) return 1;
  return 0;
}
void upAdd(int u) {
  int k = p[u].size();
  for (int i = 0; i < k; i++) {
    if (!find(p[u][i].u)) ans[p[u][i].v] = 1;
  }
}
void dsudfs(int u, int f, int flag) {
  for (int i = head[u]; i != -1; i = side[i].next) {
    int v = side[i].v;
    if (v == f || v == son[u]) continue;
    dsudfs(v, u, 0);
  }
  if (son[u]) dsudfs(son[u], u, 1), nowson = son[u];
  cel(u, f, 1);
  upAdd(u);
  nowson = 0;
  if (!flag) cel(u, f, -1);
}
void init() { memset(head, -1, sizeof(head)); }
int main() {
  init();
  scanf("%d%d", &n, &m);
  for (int i = 2; i <= n; i++) {
    int a;
    scanf("%d", &a);
    add(a, i, i - 1);
  }
  getchar();
  for (int i = 1; i <= n; i++) {
    char s;
    scanf("%c", &color[i]);
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    w.u = b;
    w.v = i;
    p[a].push_back(w);
  }
  ceng[1] = 1;
  dfs(1, 0);
  dsudfs(1, 0, 0);
  for (int i = 1; i <= m; i++) {
    if (!ans[i])
      printf("Yes\n");
    else
      printf("No\n");
  }
}
