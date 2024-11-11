#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Node {
  int u, v, w, num;
  bool type;
} edge[100011];
inline bool cmp(Node x, Node y) {
  return x.w < y.w || x.w == y.w && x.type > y.type;
}
inline bool cmpp(Node x, Node y) { return x.num < y.num; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &edge[i].w, &edge[i].type);
    edge[i].num = i;
  }
  sort(edge + 1, edge + 1 + m, cmp);
  int cnt = 1, uu = 1, vv = 3;
  for (int i = 1; i <= m; i++) {
    if (edge[i].type == 1) {
      edge[i].u = cnt;
      edge[i].v = cnt + 1;
      cnt++;
    } else {
      if (vv > cnt) {
        printf("-1\n");
        return 0;
      }
      edge[i].u = uu;
      edge[i].v = vv;
      uu++;
      if (uu == vv - 1) {
        uu = 1, vv++;
      }
    }
  }
  sort(edge + 1, edge + 1 + m, cmpp);
  for (int i = 1; i <= m; i++) printf("%d %d\n", edge[i].u, edge[i].v);
  return 0;
}
