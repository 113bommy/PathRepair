#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 7;
int n, m, root;
int val[maxN];
struct Edge {
  int to, next;
} edge[maxN * 2];
int edge_head[maxN];
int edge_cnt = 0;
void AddEdge(int form, int to) {
  edge[++edge_cnt].to = to;
  edge[edge_cnt].next = edge_head[form];
  edge_head[form] = edge_cnt;
}
int point_deep[maxN];
int point_father[maxN];
int point_son[maxN];
int point_size[maxN];
void DFS_1(int now = 1) {
  int max_size = -1;
  point_size[now] = 1;
  for (int edge_i = edge_head[now]; edge_i; edge_i = edge[edge_i].next) {
    if (point_father[now] != edge[edge_i].to) {
      point_father[edge[edge_i].to] = now;
      point_deep[edge[edge_i].to] = point_deep[now] + 1;
      DFS_1(edge[edge_i].to);
      point_size[now] += point_size[edge[edge_i].to];
      if (point_size[edge[edge_i].to] > max_size) {
        max_size = point_size[edge[edge_i].to];
        point_son[now] = edge[edge_i].to;
      }
    }
  }
}
int chain_cnt = 0;
int point_id[maxN];
int point_val[maxN];
int chain_top[maxN];
void DFS_2(int now = 1, int top = 1) {
  point_id[now] = ++chain_cnt;
  point_val[chain_cnt] = val[now];
  chain_top[now] = top;
  if (!point_son[now]) {
    return;
  }
  DFS_2(point_son[now], top);
  for (int edge_i = edge_head[now]; edge_i; edge_i = edge[edge_i].next) {
    if (edge[edge_i].to != point_father[now] &&
        edge[edge_i].to != point_son[now]) {
      DFS_2(edge[edge_i].to, edge[edge_i].to);
    }
  }
}
int LCA(int u, int v) {
  while (chain_top[u] != chain_top[v]) {
    if (point_deep[chain_top[u]] < point_deep[chain_top[v]]) {
      swap(u, v);
    }
    u = point_father[chain_top[u]];
  }
  if (point_deep[u] > point_deep[v]) {
    swap(u, v);
  }
  return u;
}
int FindSon(int u, int v) {
  while (chain_top[u] ^ chain_top[v]) {
    if (point_deep[chain_top[u]] < point_deep[chain_top[v]]) {
      swap(u, v);
    }
    if (point_father[chain_top[u]] == v) {
      return chain_top[u];
    }
    u = point_father[chain_top[u]];
  }
  if (point_deep[u] > point_deep[v]) {
    swap(u, v);
  }
  return point_son[u];
}
struct LazyTag {
  long long add;
  void CleanLazyTag() { add = 0; }
} ForMake;
LazyTag MakeLazyTag(int add) {
  ForMake.add = add;
  return ForMake;
}
struct SegmaneTree {
  long long sum;
  LazyTag tag;
} sgt[maxN * 4];
void PushUp(int now) {
  sgt[now].sum = sgt[(now << 1)].sum + sgt[(now << 1 | 1)].sum;
}
void Build(int now = 1, int left = 1, int right = n) {
  if (left == right) {
    sgt[now].sum = point_val[left];
    return;
  }
  Build((now << 1), left, ((left + right) >> 1));
  Build((now << 1 | 1), ((left + right) >> 1) + 1, right);
  PushUp(now);
}
void Down(LazyTag tag, int now, int left, int right) {
  sgt[now].tag.add += tag.add;
  sgt[now].sum += 1ll * (right - left + 1) * tag.add;
}
void PushDown(int now, int left, int right) {
  if (sgt[now].tag.add) {
    Down(sgt[now].tag, (now << 1), left, ((left + right) >> 1));
    Down(sgt[now].tag, (now << 1 | 1), ((left + right) >> 1) + 1, right);
    sgt[now].tag.CleanLazyTag();
  }
}
void Updata(int now_left, int now_right, int add, int now = 1, int left = 1,
            int right = n) {
  if (now_right < left || right < now_left) {
    return;
  }
  if (now_left <= left && right <= now_right) {
    Down(MakeLazyTag(add), now, left, right);
    return;
  }
  PushDown(now, left, right);
  Updata(now_left, now_right, add, (now << 1), left, ((left + right) >> 1));
  Updata(now_left, now_right, add, (now << 1 | 1), ((left + right) >> 1) + 1,
         right);
  PushUp(now);
}
long long Query(int now_left, int now_right, int now = 1, int left = 1,
                int right = n) {
  if (now_right < left || right < now_left) {
    return 0;
  }
  if (now_left <= left && right <= now_right) {
    return sgt[now].sum;
  }
  PushDown(now, left, right);
  return Query(now_left, now_right, (now << 1), left, ((left + right) >> 1)) +
         Query(now_left, now_right, (now << 1 | 1), ((left + right) >> 1) + 1,
               right);
}
void UpdataTree(int u, int add) {
  Updata(point_id[u], point_id[u] + point_size[u] - 1, add);
}
long long QueryTree(int u) {
  return Query(point_id[u], point_id[u] + point_size[u] - 1);
}
void UpdataChain(int u, int v, int add) {
  while (chain_top[u] != chain_top[v]) {
    if (point_deep[chain_top[u]] < point_deep[chain_top[v]]) {
      swap(u, v);
    }
    Updata(point_id[chain_top[u]], point_id[u], add);
    u = point_father[chain_top[u]];
  }
  if (point_deep[u] > point_deep[v]) {
    swap(u, v);
  }
  Updata(point_id[u], point_id[v], add);
}
int QueryChain(int u, int v) {
  int result = 0;
  while (chain_top[u] != chain_top[v]) {
    if (point_deep[chain_top[u]] < point_deep[chain_top[v]]) {
      swap(u, v);
    }
    result += Query(point_id[chain_top[u]], point_id[u]);
    u = point_father[chain_top[u]];
  }
  if (point_deep[u] > point_deep[v]) {
    swap(u, v);
  }
  return result + Query(point_id[u], point_id[v]);
}
void AddTree(int u, int v, int x) {
  int lca_1 = LCA(u, v);
  int lca_2 = LCA(u, root);
  int lca_3 = LCA(v, root);
  if (point_deep[lca_2] > point_deep[lca_1]) {
    lca_1 = lca_2;
  }
  if (point_deep[lca_3] > point_deep[lca_1]) {
    lca_1 = lca_3;
  }
  if (lca_1 == root) {
    Updata(1, n, x);
    return;
  }
  int lca = LCA(lca_1, root);
  if (LCA(lca_1, root) != lca_1) {
    UpdataTree(lca_1, x);
  } else {
    Updata(1, n, x);
    UpdataTree(FindSon(lca_1, root), -x);
  }
}
long long AskTree(int u) {
  if (u == root) {
    return Query(1, n);
  }
  int lca = LCA(u, root);
  if (lca ^ u) {
    return QueryTree(u);
  } else {
    return Query(1, n) - QueryTree(FindSon(u, root));
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &val[i]);
  }
  int father, son;
  for (int i = 1; i <= n - 1; ++i) {
    scanf("%d%d", &father, &son);
    AddEdge(father, son);
    AddEdge(son, father);
  }
  DFS_1();
  DFS_2();
  Build();
  int opt, u, v, x, lca;
  root = 1;
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d", &root);
    }
    if (opt == 2) {
      scanf("%d%d%d", &u, &v, &x);
      AddTree(u, v, x);
    }
    if (opt == 3) {
      scanf("%d", &u);
      printf("%lld\n", AskTree(u));
    }
  }
  return 0;
}
