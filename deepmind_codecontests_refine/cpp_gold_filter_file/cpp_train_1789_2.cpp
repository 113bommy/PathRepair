#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int n, a[MAXN];
struct Node {
  int u, v, c;
  Node *next;
} * h[MAXN], pool[MAXN << 1];
int tot = 0;
inline void addEdge(int u, int v) {
  Node *p = &pool[++tot], *q = &pool[++tot];
  p->v = v;
  p->c = 0;
  p->next = h[u];
  h[u] = p;
  q->v = u;
  q->c = 0;
  q->next = h[v];
  h[v] = q;
}
int root, size[MAXN], mina = 1 << 30;
inline void findRoot(int u, int fa) {
  size[u] = 0;
  int maxa = 0;
  for (Node *p = h[u]; p; p = p->next) {
    if (p->v == fa) continue;
    findRoot(p->v, u);
    size[u] += size[p->v];
    maxa = max(maxa, size[p->v]);
  }
  if (max(maxa, n - 1 - size[u]) < mina) {
    mina = max(maxa, n - 1 - size[u]);
    root = u;
  }
  size[u]++;
}
inline void getSize(int u, int fa) {
  size[u] = 1;
  for (Node *p = h[u]; p; p = p->next) {
    if (p->v == fa) continue;
    getSize(p->v, u);
    size[u] += size[p->v];
  }
}
int son[MAXN], cnt = 0;
inline bool cmp(int x, int y) { return size[x] > size[y]; }
inline void setValue(int u, int fa, int rt) {
  int tmp = 1;
  for (Node *p = h[u]; p; p = p->next) {
    if (p->v == fa) continue;
    p->c = tmp * rt;
    setValue(p->v, u, rt);
    tmp += size[p->v];
  }
}
inline void print(int u, int fa) {
  for (Node *p = h[u]; p; p = p->next) {
    if (p->v == fa) continue;
    printf("%d %d %d\n", u, p->v, p->c);
    print(p->v, u);
  }
}
int main() {
  cin >> n;
  int u, v;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    addEdge(u, v);
  }
  if (n == 1)
    return 0;
  else if (n == 2) {
    cout << "1 2 1" << endl;
    return 0;
  }
  findRoot(1, 0);
  for (Node *p = h[root]; p; p = p->next) son[++cnt] = p->v;
  getSize(root, 0);
  sort(son + 1, son + cnt + 1, cmp);
  int tmp = 1, sum = 0, rt = 1;
  bool flag = false;
  for (int i = 1; i <= cnt; i++) {
    setValue(son[i], root, rt);
    printf("%d %d %d\n", root, son[i], tmp * rt);
    print(son[i], root);
    tmp += size[son[i]];
    if (!flag) sum += size[son[i]];
    if (sum * 3 >= n - 1) {
      rt = sum + 1;
      flag = true;
      tmp = 1;
      sum = 0;
    }
  }
  return 0;
}
