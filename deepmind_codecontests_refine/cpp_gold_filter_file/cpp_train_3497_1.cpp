#include <bits/stdc++.h>
using namespace std;
struct node {
  long long v, c, pre;
} edge[1000];
int size = 1;
int last[110] = {0};
bool used[110];
void add(int u, int v, int c) {
  edge[size++] = (node){v, c, last[u]};
  last[u] = size - 1;
  edge[size++] = (node){u, c, last[v]};
  last[v] = size - 1;
}
long long dfs(int u) {
  used[u] = true;
  long long maxi = 0;
  int now = last[u];
  while (now) {
    if (used[edge[now].v] == false) {
      maxi = max(maxi, edge[now].c + dfs(edge[now].v));
    }
    now = edge[now].pre;
  }
  used[u] = false;
  return maxi;
}
int main() {
  int n;
  scanf("%d", &n);
  int u;
  int v;
  int c;
  for (int i = 1; i < n; i++) {
    scanf("%d %d %d", &u, &v, &c);
    add(u, v, c);
  }
  memset(used, false, sizeof(used));
  long long k = dfs(0);
  printf("%lld", k);
  return 0;
}
