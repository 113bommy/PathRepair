#include <bits/stdc++.h>
using namespace std;
int n, m, k, len, tot, head[250005], qu[250005], id[250005], cnt, vis[250005];
struct edge {
  int u, v, nxt;
} edg[250005 << 2];
inline void addedg(int u, int v) {
  edg[tot].u = u;
  edg[tot].v = v;
  edg[tot].nxt = head[u];
  head[u] = tot++;
}
bool dfs1(int u, int fa) {
  if (cnt == len) return true;
  for (int i = head[u]; i != -1; i = edg[i].nxt) {
    int v = edg[i].v;
    if (v != fa && !vis[v]) {
      qu[cnt++] = v;
      vis[v] = 1;
      if (dfs1(v, u)) return true;
      --cnt;
    }
  }
  return false;
}
void dfs2(int u, int fa) {
  int flag = 0;
  if (k == 0) return;
  for (int i = head[u]; i != -1; i = edg[i].nxt) {
    int v = edg[i].v;
    if (v != fa && !vis[v]) {
      flag = 1;
      qu[cnt] = v;
      id[v] = cnt;
      vis[v] = 1;
      ++cnt;
      dfs2(v, u);
      --cnt;
    }
  }
  if (!flag) {
    int fa1 = -1, fa2 = -1;
    for (int i = head[u]; i != -1; i = edg[i].nxt) {
      int v = edg[i].v;
      if (v != fa) {
        if (fa1 == -1)
          fa1 = v;
        else {
          fa2 = v;
          break;
        }
      }
    }
    if (id[fa1] < id[fa2]) swap(fa1, fa2);
    flag = 0;
    if ((id[u] - id[fa1] + 1) % 3)
      flag = fa1;
    else if ((id[u] - id[fa2] + 1) % 3)
      flag = fa2;
    if (flag) {
      len = id[u] - id[flag] + 1;
      printf("%d\n", len);
      for (int i = id[u]; i >= id[flag]; --i) printf("%d ", qu[i]);
      printf("\n");
      --k;
    } else {
      len = id[fa1] - id[fa2] + 2;
      printf("%d\n", len);
      printf("%d ", u);
      for (int i = id[fa1]; i >= id[fa2]; --i) printf("%d ", qu[i]);
      printf("\n");
      --k;
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  memset(head, -1, 4 * n + 4);
  tot = cnt = 0;
  int u, v;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    addedg(u, v);
    addedg(v, u);
  }
  len = n / k;
  if (n % k) ++len;
  vis[1] = 1;
  qu[cnt++] = 1;
  if (dfs1(1, 1)) {
    printf("PATH\n%d\n", len);
    for (int i = 0; i < cnt; ++i) printf("%d ", qu[i]);
  } else {
    memset(vis, 0, 4 * n + 4);
    cnt = 0;
    printf("CYCLES\n");
    qu[cnt++] = 1;
    id[1] = 0;
    vis[1] = 1;
    dfs2(1, 1);
  }
  return 0;
}
