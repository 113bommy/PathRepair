#include <bits/stdc++.h>
using namespace std;
vector<int> graf[1000001];
vector<int> chains[1000001];
vector<int> chainsbit[1000001];
int chainwhere[1000001], chainposition[1000001];
void update(int chainidx, int x, int val) {
  while (x <= chainsbit[chainidx].size() - 1) {
    chainsbit[chainidx][x] += val;
    x += (x & -x);
  }
}
int read(int chainidx, int x) {
  if (chainsbit[chainidx].size() < x)
    x = min(x, (int)(chainsbit[chainidx].size()) - 1);
  int ret = 0;
  while (x > 0) {
    ret += chainsbit[chainidx][x];
    x -= (x & -x);
  }
  return ret;
}
void DFS(int u, int chainidx, int prev) {
  chains[chainidx].push_back(u);
  chainsbit[u].push_back(0);
  chainwhere[u] = chainidx;
  chainposition[u] = chains[chainidx].size() - 1;
  for (int i = 0; i < graf[u].size(); i++)
    if (graf[u][i] != prev) DFS(graf[u][i], chainidx, u);
}
int rootvalue = 0;
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    graf[u].push_back(v);
    graf[v].push_back(u);
  }
  int chainnum = graf[1].size();
  for (int i = 0; i < n + 15; i++) chainsbit[0].push_back(0);
  for (int i = 0; i < graf[1].size(); i++) {
    chains[i + 1].push_back(0);
    chainsbit[i + 1].push_back(0);
    DFS(graf[1][i], i + 1, 1);
    int ln = chains[i + 1].size() * 2;
    for (int j = 0; j < ln; j++) {
      chains[i + 1].push_back(0);
      chainsbit[i + 1].push_back(0);
    }
  }
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 0) {
      int v, x, d;
      scanf("%d%d%d", &v, &x, &d);
      if (v == 1) {
        rootvalue += x;
        update(0, 1, +x);
        update(0, d + 1, -x);
      } else {
        int ch = chainwhere[v];
        int depth = chainposition[v];
        if (depth - d >= 1) {
          update(ch, depth - d, +x);
          update(ch, depth + d + 1, -x);
        } else {
          update(ch, 1, +x);
          update(ch, depth + d + 1, -x);
          int rest = d - depth;
          rootvalue += x;
          if (rest > 0) {
            update(0, 1, +x);
            update(0, rest + 1, -x);
            update(ch, 1, -x);
            update(ch, rest + 1, +x);
          }
        }
      }
    } else {
      int v;
      scanf("%d", &v);
      if (v == 1)
        printf("%d\n", rootvalue);
      else {
        int ret =
            read(0, chainposition[v]) + read(chainwhere[v], chainposition[v]);
        printf("%d\n", ret);
      }
    }
  }
  return 0;
}
