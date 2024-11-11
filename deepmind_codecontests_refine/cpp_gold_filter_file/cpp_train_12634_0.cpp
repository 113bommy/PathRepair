#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Edge {
  int x, nex;
} edge[123456 << 1];
int head[123456], edgenum;
void add(int u, int v) {
  Edge E = {v, head[u]};
  edge[edgenum] = E;
  head[u] = edgenum++;
}
void init() {
  memset(head, -1, sizeof head);
  edgenum = 0;
}
int main() {
  int i, j, u, v, d;
  while (cin >> n) {
    init();
    cout << n - 1 << endl;
    for (i = 1; i < n; i++) {
      scanf("%d %d", &u, &v);
      printf("2 %d %d\n", u, v);
      add(u, i);
      add(v, i);
    }
    for (i = 1; i <= n; i++) {
      for (j = head[i]; ~j && ~edge[j].nex; j = edge[j].nex) {
        cout << edge[j].x << " " << edge[edge[j].nex].x << endl;
      }
    }
  }
  return 0;
}
