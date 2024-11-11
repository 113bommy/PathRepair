#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int s, e, l, h;
  int v[10];
  bool operator<(const Edge& x) const { return s < x.s; }
} edge[50];
int n, m, cur[10], flow, price;
void dfs(int idx, int ret) {
  if (idx == m + 1) {
    for (int i = 1; i <= n - 1; i++) {
      if (cur[i] > 0) return;
    }
    price = max(price, ret);
  } else {
    int u = edge[idx].s;
    int v = edge[idx].e;
    for (int i = 1; i <= u - 1; i++) {
      if (cur[i] > 0) return;
    }
    int low = edge[idx].l;
    int high = edge[idx].h;
    for (int i = low; i <= high && i <= cur[u]; i++) {
      cur[u] -= i;
      cur[v] += i;
      dfs(idx + 1, ret + edge[idx].v[i]);
      cur[u] += i;
      cur[v] -= i;
    }
  }
}
int main(int argc, char** argv) {
  cin >> n;
  m = n * (n - 1) / 2;
  for (int i = 1; i <= m; i++) {
    cin >> edge[i].s >> edge[i].e;
    cin >> edge[i].l >> edge[i].h;
    cin >> edge[i].v[0];
    for (int j = 1; j <= 8; j++) edge[i].v[j] = edge[i].v[0] + j * j;
    edge[i].v[0] = 0;
  }
  sort(edge + 1, edge + m + 1);
  price = -1;
  flow = 0;
  while (price == -1) {
    memset(cur, 0, sizeof(cur));
    cur[1] = flow;
    dfs(1, 0);
    flow += 1;
    if (flow == 30) break;
  }
  if (price == -1)
    cout << "-1 -1" << endl;
  else
    cout << flow - 1 << " " << price << endl;
  return (EXIT_SUCCESS);
}
