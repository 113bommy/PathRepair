#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int n, m, q, tot;
int ans[maxn];
int anc[maxn], sz[maxn], tail;
pair<int, int> o[maxn];
int Tail;
int find(int x) {
  if (x == anc[x]) {
    return x;
  }
  return anc[x] = find(anc[x]);
}
void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (sz[x] > sz[y]) {
    swap(x, y);
  }
  anc[x] = y;
  sz[y] += sz[x];
  o[++Tail] = {x, y};
}
void recall() {
  sz[o[Tail].second] -= sz[o[Tail].first];
  anc[o[Tail].first] = o[Tail].first;
  Tail--;
}
struct node1 {
  int u, v, w;
} edge[maxn];
bool cmp1(node1 a, node1 b) { return a.w < b.w; }
struct node2 {
  int id, u, v, w;
} query[maxn];
bool cmp2(node2 a, node2 b) {
  if (a.w != b.w) {
    return a.w < b.w;
  }
  return a.id < b.id;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    anc[i] = i;
    sz[i] = 1;
  }
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    edge[i] = (node1){u, v, w};
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 1; j <= k; j++) {
      int x;
      scanf("%d", &x);
      query[++tot] = (node2){i, edge[x].u, edge[x].v, edge[x].w};
    }
  }
  sort(edge + 1, edge + m + 1, cmp1);
  sort(query + 1, query + tot + 1, cmp2);
  int pos1 = 1, pos2 = 1;
  for (int i = 1; i <= tot; i = pos2) {
    while (edge[pos1].w < query[i].w && pos1 <= m) {
      int x = find(edge[pos1].u);
      int y = find(edge[pos1].v);
      if (x != y) {
        merge(x, y);
      }
      pos1++;
    }
    int now = Tail;
    while (query[pos2].w == query[i].w && pos2 <= tot) {
      if (query[pos2].id != query[pos2 - 1].id || pos2 == i) {
        while (Tail > now) {
          recall();
        }
      }
      int x = find(query[pos2].u);
      int y = find(query[pos2].v);
      if (x == y) {
        ans[query[pos2].id] = 1;
      } else {
        merge(x, y);
      }
      pos2++;
    }
    while (Tail > now) {
      recall();
    }
  }
  for (int i = 1; i <= q; i++) {
    if (ans[i]) {
      puts("NO");
    } else {
      puts("YES");
    }
  }
  return 0;
}
