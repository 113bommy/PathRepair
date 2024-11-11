#include <bits/stdc++.h>
using namespace std;
struct node {
  int money, c1, c2, id;
  friend bool operator<(node a, node b) { return a.money > b.money; }
} a[200005];
bool vis[200005];
priority_queue<node> Q[4];
int main() {
  for (int i = 1; i <= 3; i++)
    while (!Q[i].empty()) Q[i].pop();
  int n, m, t;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].money);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].c1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].c2);
    a[i].id = i;
    if (a[i].c1 == 1 || a[i].c2 == 1) Q[1].push(a[i]);
    if (a[i].c1 == 2 || a[i].c2 == 2) Q[2].push(a[i]);
    if (a[i].c1 == 3 || a[i].c2 == 3) Q[3].push(a[i]);
  }
  scanf("%d", &m);
  memset(vis, false, sizeof(vis));
  while (m--) {
    scanf("%d", &t);
  L:
    node temp;
    if (!Q[t].empty()) {
      temp = Q[t].top();
      Q[t].pop();
    } else {
      printf("-1 ");
      continue;
    }
    if (vis[temp.id]) goto L;
    printf("%d", temp.money);
    vis[temp.id] = true;
    if (m != 0)
      printf(" ");
    else
      printf("\n");
  }
  return 0;
}
