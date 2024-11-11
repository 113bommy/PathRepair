#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1 << 16;
int deg[MAX_N + 10], ss[MAX_N + 10];
int n;
struct Edge {
  int a, b;
};
Edge edges[MAX_N + 10];
int en;
queue<int> q;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", deg + i, ss + i);
    if (deg[i] == 1) q.push(i);
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (deg[cur] != 1) continue;
    ++en;
    edges[en].a = cur;
    edges[en].b = ss[cur];
    ss[ss[cur]] ^= cur;
    --deg[ss[cur]];
    if (deg[ss[cur]] == 1) q.push(ss[cur]);
  }
  printf("%d\n", en);
  for (int i = 1; i <= en; i++) printf("%d %d\n", edges[i].a, edges[i].b);
  return 0;
}
