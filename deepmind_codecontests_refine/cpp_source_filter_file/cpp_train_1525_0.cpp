#include <bits/stdc++.h>
using namespace std;
int indegree[100010], mark[100010];
vector<int> graph[100010];
queue<int> que[2];
int N, M;
void init() {
  for (int i = 0; i < 100010; ++i) graph[i].clear();
  memset(indegree, 0, sizeof(indegree));
  while (que[0].size()) que[0].pop();
  while (que[1].size()) que[1].pop();
}
int main() {
  while (scanf("%d%d", &N, &M) == 2) {
    init();
    for (int i = 0; i < N; ++i) scanf("%d", &mark[i]);
    int s, t;
    for (int i = 0; i < M; ++i) {
      scanf("%d%d", &s, &t);
      ++indegree[s];
      graph[t].push_back(s);
    }
    for (int i = 0; i < N; ++i) {
      if (indegree[i]) continue;
      que[mark[i]].push(i);
    }
    int havedone = 0;
    int ans = 0;
    while (havedone < N) {
      if (que[1].size()) {
        while (que[1].size()) {
          int temp = que[1].front();
          que[1].pop();
          ++havedone;
          for (int i = 0; i < graph[temp].size(); ++i) {
            int np = graph[temp][i];
            --indegree[np];
            if (indegree[np] == 0) que[mark[np]].push(np);
          }
        }
      } else {
        ++ans;
        while (que[0].size()) {
          int temp = que[0].front();
          que[0].pop();
          ++havedone;
          for (int i = 0; i < graph[temp].size(); ++i) {
            int np = graph[temp][i];
            --indegree[np];
            if (indegree[np] == 0) que[mark[np]].push(np);
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
