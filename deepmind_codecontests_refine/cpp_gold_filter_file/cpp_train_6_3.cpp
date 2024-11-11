#include <bits/stdc++.h>
using namespace std;
int a[200000], b[200000];
vector<int> pos[200000];
int p[200000], nxt[200000];
int parent[200000];
int find(int n) {
  if (parent[n] != n) parent[n] = find(parent[n]);
  return parent[n];
}
int visited[200000];
vector<int> cycles[200000];
int main() {
  int i;
  int n, s;
  scanf("%d %d", &n, &s);
  for (i = 0; i < n; i++) scanf("%d", &a[i]), b[i] = a[i];
  sort(b, b + n);
  for (i = 0; i < n; i++) a[i] = lower_bound(b, b + n, a[i]) - b;
  for (i = 0; i < n; i++) b[i] = a[i];
  sort(b, b + n);
  int j, c = 0;
  for (i = 0; i < n; i++) {
    if (a[i] != b[i]) pos[b[i]].push_back(i), c++;
    parent[i] = i, p[i] = -1;
  }
  if (c > s) {
    printf("-1\n");
    return 0;
  }
  for (i = 0; i < n; i++) {
    if (a[i] == b[i])
      nxt[i] = i;
    else
      nxt[i] = pos[a[i]].back(), pos[a[i]].pop_back();
    int pa = find(i), push_back = find(nxt[i]);
    if (pa != push_back) parent[pa] = push_back;
  }
  for (i = 0; i < n; i++) {
    if (a[i] == b[i]) continue;
    if (p[a[i]] != -1) {
      int pa = find(p[a[i]]), push_back = find(i);
      if (pa != push_back) {
        int t = nxt[p[a[i]]];
        nxt[p[a[i]]] = nxt[i];
        nxt[i] = t;
        parent[pa] = push_back;
      }
    }
    p[a[i]] = i;
  }
  int cc = 0;
  for (i = 0; i < n; i++) {
    if (!visited[i] && (i != nxt[i])) {
      int u = i;
      do cycles[cc].push_back(u), visited[u] = 1, u = nxt[u];
      while (u != i);
      cc++;
    }
  }
  int x = min(s - c, cc);
  printf("%d\n", cc - x + min(x, 2));
  int sum = 0;
  if (x > 0) {
    for (i = 0; i < x; i++) sum += cycles[i].size();
    printf("%d\n", sum);
    for (i = 0; i < x; i++) {
      for (j = 0; j < cycles[i].size(); j++) printf("%d ", cycles[i][j] + 1);
    }
    printf("\n");
    if (x > 1) {
      printf("%d\n", x);
      for (i = x - 1; i >= 0; i--) printf("%d ", cycles[i][0] + 1);
      printf("\n");
    }
  }
  for (i = x; i < cc; i++) {
    printf("%d\n", cycles[i].size());
    for (j = 0; j < cycles[i].size(); j++) printf("%d ", cycles[i][j] + 1);
    printf("\n");
  }
  return 0;
}
