#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const long long INF = 1LL << 55;
struct Tree {
  Tree *nex[26];
  vector<int> G[2];
  int deep;
  Tree() {
    for (int i = 0; i < 26; i++) nex[i] = NULL;
    deep = 0;
  }
};
Tree *tree;
void Insert(char *s, int u, int id) {
  Tree *p = tree;
  for (int i = 0; s[i]; i++) {
    int a = s[i] - 'a';
    if (p->nex[a] == NULL) {
      Tree *q = new Tree;
      q->deep = i + 1;
      p->nex[a] = q;
    }
    p = p->nex[a];
    p->G[u].push_back(id);
  }
}
char vis1[N], vis2[N];
int ans[N];
long long ret;
void DFS(Tree *t) {
  for (int i = 0; i < 26; i++)
    if (t->nex[i]) DFS(t->nex[i]);
  int a = 0;
  int b = t->G[1].size();
  for (int i = 0; i < t->G[0].size(); i++) {
    while (a < b && vis2[t->G[1][a]]) a++;
    if (a >= b) break;
    int v = t->G[0][i];
    if (!vis1[v]) {
      vis1[v] = 1;
      vis2[t->G[1][a]] = 1;
      ret += (long long)(t->deep);
      ans[v] = t->G[1][a++];
    }
  }
}
int main() {
  int i, j, k, m, n;
  char s[800010];
  while (scanf("%d", &n) == 1) {
    tree = new Tree;
    for (i = 1; i <= n; i++) tree->G[0].push_back(i);
    for (i = 1; i <= n; i++) tree->G[1].push_back(i);
    for (i = 1; i <= n; i++) scanf("%s", s), Insert(s, 0, i);
    for (i = 1; i <= n; i++) scanf("%s", s), Insert(s, 1, i);
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    ret = 0;
    DFS(tree);
    printf("%I64d\n", ret);
    for (i = 1; i <= n; i++) printf("%d %d\n", i, ans[i]);
  }
  return 0;
}
