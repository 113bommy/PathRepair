#include <bits/stdc++.h>
using namespace std;
const int M = 220000;
const int N = 40;
const int inf = 1 << 29;
const double dinf = 9999999999.9;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int mods = 1000000007;
struct node {
  int v;
  int next;
} edge[3 * M];
int head[M], cost[M];
int bctcnt[M], bcnt, bcost[M];
int top, dindex;
int dep[M], low[M], stac[M], belong[M];
bool instack[M];
int n, m, num;
void init() {
  for (int i = 0; i < n + 10; i++) {
    belong[i] = i + 1;
    head[i] = -1;
    bcost[i] = inf;
    bctcnt[i] = 0;
  }
  memset(dep, 0, sizeof(dep));
  memset(instack, 0, sizeof(instack));
  num = 0;
  bcnt = dindex = top = 0;
}
void build(int a, int b) {
  edge[num].v = b;
  edge[num].next = head[a];
  head[a] = num;
  num++;
}
void Tarjan(int u) {
  int j, v;
  dep[u] = low[u] = ++dindex;
  instack[u] = true;
  stac[++top] = u;
  for (j = head[u]; j != -1; j = edge[j].next) {
    v = edge[j].v;
    if (!dep[v]) {
      Tarjan(v);
      if (low[v] < low[u]) low[u] = low[v];
    } else if (instack[v] && dep[v] < low[u])
      low[u] = dep[v];
  }
  if (dep[u] == low[u]) {
    bcnt++;
    do {
      j = stac[top--];
      instack[j] = false;
      belong[j] = bcnt;
    } while (j != u);
  }
}
int main() {
  while (cin >> n) {
    init();
    for (int i = 1; i <= n; i++) {
      cin >> cost[i];
    }
    cin >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
      cin >> a >> b;
      build(a, b);
    }
    for (int i = 1; i <= n; i++)
      if (!dep[i]) {
        Tarjan(i);
      }
    for (int i = 1; i <= n; i++) {
      int idx = belong[i];
      if (cost[i] < bcost[idx]) {
        bcost[idx] = cost[i];
        bctcnt[idx] = 1;
      } else if (cost[i] == bcost[idx]) {
        bctcnt[idx]++;
      }
    }
    long long ans1 = 0;
    long long ans2 = 1;
    for (int i = 1; i <= bcnt; i++) {
      ans1 += bcost[i];
      ans2 = (ans2 * bctcnt[i]) % mods;
    }
    cout << ans1 << " " << ans2 << endl;
  }
  return 0;
}
