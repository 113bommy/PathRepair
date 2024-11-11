#include <bits/stdc++.h>
using namespace std;
const int MAXN = 114514 * 10;
int n, m;
int T;
struct Edge {
  int to, next;
} edge[MAXN];
int edge_head[MAXN];
int edge_cnt = 0;
void AddEdge(int form, int to) {
  edge[++edge_cnt].to = to;
  edge[edge_cnt].next = edge_head[form];
  edge_head[form] = edge_cnt;
}
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }
void read(int &a) { scanf("%d", &a); }
void work() {}
struct P {
  int size, deep;
} p[MAXN];
bool Cmp(P a, P b) { return a.deep - a.size > b.deep - b.size; }
void DFS(int now = 1) {
  p[now].size = 1;
  for (int edge_i = edge_head[now]; edge_i; edge_i = edge[edge_i].next) {
    if (!p[edge[edge_i].to].deep) {
      p[edge[edge_i].to].deep = p[now].deep + 1;
      DFS(edge[edge_i].to);
      p[now].size += p[edge[edge_i].to].size;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  int f, t;
  for (int i = 1; i <= n - 1; ++i) {
    scanf("%d%d", &f, &t);
    AddEdge(f, t);
    AddEdge(t, f);
  }
  p[1].deep = 1;
  DFS();
  sort(p + 1, p + 1 + n, Cmp);
  long long answer = 0;
  for (int i = 1; i <= m; ++i) {
    answer += p[i].deep - p[i].size;
  }
  printf("%lld", answer);
  return 0;
}
