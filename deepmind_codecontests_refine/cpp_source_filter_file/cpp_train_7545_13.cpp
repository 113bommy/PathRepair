#include <bits/stdc++.h>
long long INF = (long long)1e18;
struct node {
  int n;
  double rat;
};
bool operator<(const node& n1, const node& n2) { return n1.rat > n2.rat; }
std::vector<int> edge[100010];
int ch[100010], ne[100010];
int main() {
  int x, a, b, k, n, m, q, t, num, in = 0, to, i;
  double d, s;
  scanf("%d%d%d", &n, &m, &q);
  for (k = 1; k <= q; k++) {
    scanf("%d", &x);
    ch[x] = -1;
  }
  for (k = 1; k <= m; k++) {
    scanf("%d%d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  double max = 0;
  std::priority_queue<node> PQ;
  for (k = 1; k <= n; k++) {
    if (ch[k] == -1) continue;
    t = 0;
    for (i = 0; i < edge[k].size(); i++) {
      int j = edge[k][i];
      if (ch[j] == 0) t++;
    }
    ne[k] = t;
    PQ.push(node{k, (double)t / (double)edge[k].size()});
  }
  num = n - q;
  in = 1;
  while (num != 0) {
    a = PQ.top().n;
    d = PQ.top().rat;
    PQ.pop();
    if (ch[a] != 0) continue;
    ch[a] = in++;
    if (d > max) {
      max = d;
      to = in;
    }
    num--;
    for (i = 0; i < edge[a].size(); i++) {
      int j = edge[a][i];
      if (ch[j] != 0) continue;
      ne[j]--;
      s = (double)ne[j] / (double)edge[j].size();
      PQ.push(node{j, s});
    }
  }
  int ans = 0;
  for (k = 1; k <= n; k++) {
    if (ch[k] >= to - 1) ans++;
  }
  printf("%d\n", ans);
  for (k = 1; k <= n; k++) {
    if (ch[k] >= to - 1) printf("%d ", k);
  }
}
