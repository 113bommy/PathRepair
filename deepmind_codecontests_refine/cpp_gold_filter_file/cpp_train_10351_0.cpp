#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
struct Edge {
  int y, next;
};
struct Tree {
  long long n, head[MAXN], nodeCnt[MAXN], edgeCnt, dis[MAXN], pos, maxTot;
  long long curSum[MAXN], tot[MAXN], pathCnt;
  Edge edge[MAXN << 1];
  void addEdge(int x, int y) {
    edge[edgeCnt].y = y;
    edge[edgeCnt].next = head[x];
    head[x] = edgeCnt++;
  }
  void build(int n) {
    memset(head, -1, sizeof(head));
    this->n = n;
    int x, y;
    for (int i = 1; i < n; i++) {
      scanf("%d%d", &x, &y);
      addEdge(x, y);
      addEdge(y, x);
    }
  }
  void dfs0(int son, int fa) {
    nodeCnt[son] = 1;
    curSum[son] = 0;
    int y;
    for (int i = head[son]; i != -1; i = edge[i].next) {
      y = edge[i].y;
      if (y == fa) {
        continue;
      }
      dfs0(y, son);
      nodeCnt[son] += nodeCnt[y];
      curSum[son] += curSum[y] + nodeCnt[y];
    }
  }
  void dfs1(int son, int fa, long long faLeft) {
    tot[son] = curSum[son] + faLeft;
    int y;
    for (int i = head[son]; i != -1; i = edge[i].next) {
      y = edge[i].y;
      if (y == fa) {
        continue;
      }
      dfs1(y, son,
           faLeft + curSum[son] - curSum[y] - nodeCnt[y] + n - nodeCnt[y]);
    }
  }
  void dfs2(int son, int fa) {
    dis[son] = dis[fa] + 1;
    int y;
    for (int i = head[son]; i != -1; i = edge[i].next) {
      y = edge[i].y;
      if (y == fa) {
        continue;
      }
      dfs2(y, son);
    }
  }
  void solve() {
    dfs0(1, 0);
    dfs1(1, 0, 0);
    for (int i = 1; i <= n; i++) {
      pathCnt += tot[i];
      if (tot[i] > maxTot) {
        maxTot = tot[i];
        pos = i;
      }
    }
    dis[0] = -1;
    dfs2(pos, 0);
  }
};
Tree t[3];
long long getAns(const Tree &t1, const Tree &t2, const Tree &t3) {
  long long tmp = (long long)(t2.n + t3.n) * t1.maxTot +
                  (t1.n + t2.n) * t3.maxTot + t1.n * t2.n + t2.n * t3.n +
                  2 * t1.n * t3.n + (t1.pathCnt + t2.pathCnt + t3.pathCnt) / 2;
  long long ans, maxAns = 0;
  tmp += (long long)t1.n * t2.maxTot;
  for (int i = 1; i <= t2.n; i++) {
    ans = (long long)tmp + t3.n * t2.tot[i] + t1.n * t3.n * t2.dis[i];
    maxAns = max(ans, maxAns);
  }
  return maxAns;
}
int main() {
  int n[3], i, j;
  long long ans = 0;
  scanf("%d%d%d", &n[0], &n[1], &n[2]);
  for (i = 0; i < 3; i++) {
    t[i].build(n[i]);
    t[i].solve();
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (i == j) {
        continue;
      }
      ans = max(ans, getAns(t[i], t[j], t[3 - i - j]));
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
