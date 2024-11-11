#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int M = 2e4 + 10;
int head[N], tot;
struct node {
  int nex, to, w;
} edge[N << 1];
void add(int x, int y) {
  edge[++tot].to = y;
  edge[tot].nex = head[x];
  head[x] = tot;
}
int v[N], d[N], cnt;
vector<int> q;
void dfs(int x) {
  q.push_back(x);
  d[x] = q.size();
  for (int i = head[x]; ~i; i = edge[i].nex) {
    int y = edge[i].to;
    if (!d[y])
      dfs(y);
    else if (d[x] - d[y] + 1 >= cnt) {
      printf("2\n%d\n", d[x] - d[y] + 1);
      for (int i = d[y] - 1; i < d[x]; i++) {
        printf("%d ", q[i]);
      }
      exit(0);
    }
  }
  if (!v[x]) {
    for (int i = head[x]; ~i; i = edge[i].nex) {
      int y = edge[i].to;
      v[y] = 1;
    }
  }
  q.pop_back();
}
int main() {
  memset(head, -1, sizeof(head));
  int n, m;
  scanf("%d%d", &n, &m);
  while (cnt * cnt < n) cnt++;
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  dfs(1);
  printf("1\n");
  for (int i = 1; cnt; i++) {
    if (!v[i]) {
      printf("%d ", i);
      cnt--;
    }
  }
  return 0;
}
