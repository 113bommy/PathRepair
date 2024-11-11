#include <bits/stdc++.h>
using namespace std;
const int maxNode = 1e5 + 10, maxAsk = 1e5 + 10;
int nodeN = 0, askM = 0, totEdg = 0, bloSze = 0;
queue<int> que;
struct list {
  int to, next;
} edge[maxNode << 1] = {};
struct qurey {
  int type, nodId, ans;
} ask[maxAsk] = {};
int head[maxNode], fa[maxNode][20] = {}, dep[maxNode] = {}, dis[maxNode] = {};
bool vis[maxNode] = {}, col[maxNode] = {};
void addedge(int from, int to) {
  edge[++totEdg].to = to;
  edge[totEdg].next = head[from];
  head[from] = totEdg;
}
void init() {
  scanf("%d%d", &nodeN, &askM);
  for (int edgeI = 1; edgeI <= nodeN - 1; ++edgeI) {
    int nodu, nodv;
    scanf("%d%d", &nodu, &nodv);
    addedge(nodu, nodv);
    addedge(nodv, nodu);
  }
  for (int askI = 1; askI <= askM; ++askI) {
    scanf("%d%d", &ask[askI].type, &ask[askI].nodId);
  }
}
void dfs(int now, int from) {
  fa[now][0] = from;
  dep[now] = dep[from] + 1;
  for (int upI = 1; upI <= 18; ++upI)
    fa[now][upI] = fa[fa[now][upI - 1]][upI - 1];
  for (int pt = head[now]; pt; pt = edge[pt].next) {
    int to = edge[pt].to;
    if (to != from) dfs(to, now);
  }
}
int LCA(int nodU, int nodV) {
  int oriU = nodU, oriV = nodV;
  if (dep[nodU] < dep[nodV]) swap(nodU, nodV);
  for (int upI = 18; upI >= 0; --upI)
    if (dep[fa[nodU][upI]] >= dep[nodV]) nodU = fa[nodU][upI];
  if (nodU == nodV) return dep[oriU] + dep[oriV] - 2 * dep[nodU];
  for (int upI = 18; upI >= 0; --upI)
    if (fa[nodU][upI] != fa[nodV][upI])
      nodU = fa[nodU][upI], nodV = fa[nodV][upI];
  return dep[oriU] + dep[oriV] - 2 * dep[fa[nodU][0]];
}
void bfs() {
  memset(dis, 0x3f, sizeof(dis));
  for (int nodI = 1; nodI <= nodeN; ++nodI)
    if (col[nodI]) dis[nodI] = 0, que.push(nodI);
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (int pt = head[now]; pt; pt = edge[pt].next) {
      int to = edge[pt].to;
      if (dis[to] == 0x3f3f3f3f) que.push(to), dis[to] = dis[now] + 1;
    }
  }
}
int main() {
  init();
  dfs(1, 0);
  bloSze = (int)sqrt(1.0 * nodeN / (log(nodeN) / log(2)));
  col[1] = 1;
  bfs();
  for (int askI = 1; askI <= askM; ++askI) {
    int nodId = ask[askI].nodId;
    if (ask[askI].type == 2) {
      int belong = ((askI - 1) / bloSze) + 1, beg = (belong - 1) * bloSze + 1,
          end = belong * bloSze;
      ask[askI].ans = dis[nodId];
      for (int chanJ = beg; chanJ <= end; ++chanJ) {
        if (ask[chanJ].type == 1) {
          int juLi = LCA(ask[chanJ].nodId, nodId);
          ask[askI].ans = min(ask[askI].ans, juLi);
        }
      }
      printf("%d\n", ask[askI].ans);
    } else if (ask[askI].type == 1) {
      col[nodId] = 1;
    }
    if (askI % bloSze == 0) bfs();
  }
  return 0;
}
