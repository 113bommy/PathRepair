#include <bits/stdc++.h>
using namespace std;
const long maxn = 2e5 + 100;
const long long mod = 1e9 + 9;
struct node {
  long d;
  struct node *next;
} * point[maxn];
long need[maxn], fa[maxn];
bool vis[maxn], feng[maxn];
long pr[maxn], pr_count = 0;
void dfs(long d) {
  long cc = 0;
  vis[d] = true;
  struct node *p = point[d];
  while (p) {
    if (!vis[p->d]) {
      cc++;
      dfs(p->d);
      need[d] = need[d] ^ need[p->d];
    } else
      fa[d] = p->d;
    p = p->next;
  }
}
void print(long d) {
  printf("%ld\n", d);
  struct node *p = point[d];
  while (p) {
    if (fa[d] != p->d && need[p->d] == 1) print(p->d);
    p = p->next;
  }
}
void work(long d) {
  struct node *p = point[d];
  struct node *q;
  while (p) {
    if (fa[d] != p->d) work(p->d);
    p = p->next;
  }
  if (need[d] == 0) {
    printf("%ld\n", d);
    p = point[d];
    while (p) {
      if (fa[d] != p->d && need[p->d] == 1) print(p->d);
      p = p->next;
    }
  }
}
int main() {
  struct node *p;
  long n, root, i, y;
  scanf("%ld", &n);
  for (i = 1; i <= n; i++) {
    point[i] = NULL;
    need[i] = 1;
    vis[i] = false;
  }
  for (i = 1; i <= n; i++) {
    scanf("%ld", &y);
    if (y == 0)
      root = i;
    else {
      p = (struct node *)malloc(sizeof(struct node));
      p->d = y;
      p->next = point[i];
      point[i] = p;
      p = (struct node *)malloc(sizeof(struct node));
      p->d = i;
      p->next = point[y];
      point[y] = p;
    }
  }
  need[root] = 0;
  fa[root] = 0;
  dfs(root);
  if (need[root] == 1) {
    printf("NO");
    return 0;
  }
  printf("YES\n");
  work(root);
  return 0;
}
