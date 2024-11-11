#include <bits/stdc++.h>
using namespace std;
const int maxN = 600005;
struct Edge {
  int next, now;
} edge[maxN * 2];
int head[maxN], cnt = 0;
void add(int from, int to) {
  edge[++cnt].next = head[from];
  head[from] = cnt;
  edge[cnt].now = to;
}
int N, M;
int val[maxN], DFS[maxN];
int answer = 0;
bool visit[maxN];
void no() {
  printf("-1");
  exit(0);
}
void dfs(int now, int father) {
  visit[now] = 1;
  DFS[++answer] = now;
  val[now] ^= 1;
  for (int _i_ = head[now]; _i_; _i_ = edge[_i_].next)
    if (!visit[edge[_i_].now]) {
      dfs(edge[_i_].now, now);
      DFS[++answer] = now;
      val[now] ^= 1;
    }
  if (val[now]) {
    DFS[++answer] = father;
    val[father] ^= 1;
    DFS[++answer] = now;
    val[now] ^= 1;
  }
}
int main() {
  scanf("%d%d", &N, &M);
  int i, from, to;
  for (i = 1; i <= M; i++) {
    scanf("%d%d", &from, &to);
    add(from, to);
    add(to, from);
  }
  int root = 0;
  for (i = 1; i <= N; i++) {
    scanf("%d", &val[i]);
    if (val[i]) root = i;
  }
  if (root) {
    dfs(root, -1);
    for (i = 1; i <= N; i++)
      if (!visit[i] && val[i]) no();
  }
  if (answer > 1 && DFS[answer - 1] == -1) answer -= 3;
  printf("%d\n", answer);
  for (i = 1; i <= answer; i++) printf("%d ", DFS[i]);
}
