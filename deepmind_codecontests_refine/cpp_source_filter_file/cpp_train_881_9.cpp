#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > graph[100005];
int value[100005];
void dfs(int from, int now, int v) {
  value[now] = v;
  int i;
  for (i = 0; i < graph[now].size(); i++) {
    if (graph[now][i].first == from) continue;
    if (value[graph[now][i].first] != -1) {
      if (value[graph[now][i].first] != (v ^ (graph[now][i].second))) {
        printf("0\n");
        exit(0);
      }
      continue;
    }
    dfs(now, graph[now][i].first, v ^ (graph[now][i].second));
  }
  return;
}
long long bigmod(long long a, long long b, int M) {
  if (b == 0) return 1 % M;
  long long x = bigmod(a, b / 2, M);
  x = (x * x) % M;
  if (b % 2) x = (x * a) % M;
  return x;
}
int main() {
  int i, n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  memset(value, -1, sizeof(value));
  for (i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    a--;
    b--;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
  long long total = 0;
  for (i = 0; i < n; i++) {
    if (value[i] != -1) continue;
    dfs(-1, i, 0);
    total++;
  }
  total--;
  printf("%I64d\n", bigmod(2, total, 1000000007));
  return 0;
}
