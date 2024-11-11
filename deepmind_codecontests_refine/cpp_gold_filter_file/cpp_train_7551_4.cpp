#include <bits/stdc++.h>
using namespace std;
const int NUM = 4e5 + 10;
int head[NUM], nxt[NUM << 1], to[NUM << 1], cnt = 0, n;
int siz[NUM];
double ans[NUM];
void addedge(int u, int v) {
  nxt[++cnt] = head[u];
  to[cnt] = v;
  head[u] = cnt;
}
void getsize(int u, int fa) {
  siz[u] = 1;
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v == fa) continue;
    getsize(v, u);
    siz[u] += siz[v];
  }
}
void dfs(int u, int fa) {
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v == fa) continue;
    ans[v] = ans[u] + 1 + (double)(siz[u] - siz[v] - 1) / 2.0;
    dfs(v, u);
  }
}
int main() {
  cin >> n;
  int u;
  for (int i = 2; i <= n; i++) {
    scanf("%d", &u);
    addedge(i, u);
    addedge(u, i);
  }
  getsize(1, 0);
  ans[1] = 1;
  dfs(1, 0);
  for (int i = 1; i <= n; i++) printf("%.8f ", ans[i]);
}
