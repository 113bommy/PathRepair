#include <bits/stdc++.h>
using namespace std;
int n, m;
char states[100010], used[100010], stored[100010];
char dirmask[2][100010];
set<int> adj[100010], rev[100010];
void bfs(set<int> *graph, int start, char *target, char *mask) {
  queue<int> q;
  int trnt;
  q.push(start);
  mask[start] = 1;
  while (q.size()) {
    trnt = q.front();
    q.pop();
    target[trnt] = 1;
    if (states[trnt] == 0 || trnt == start) {
      for (set<int>::iterator i = graph[trnt].begin(); i != graph[trnt].end();
           ++i) {
        int tmp = *i;
        if (mask[tmp] == 1) {
          continue;
        }
        q.push(tmp);
        mask[tmp] = 1;
      }
    }
  }
}
int main() {
  int i, a, b;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%hhd", states + i);
  }
  for (i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    adj[a].insert(b);
    rev[b].insert(a);
  }
  for (i = 1; i <= n; i++) {
    if (states[i] == 1) {
      bfs(adj, i, stored, dirmask[0]);
    }
    if (states[i] == 2) {
      bfs(rev, i, used, dirmask[1]);
    }
  }
  for (i = 1; i <= n; i++) {
    printf("%d\n", (int)(used[i] && stored[i]));
  }
  return 0;
}
