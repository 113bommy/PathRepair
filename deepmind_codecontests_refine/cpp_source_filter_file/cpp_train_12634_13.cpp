#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:250000000")
template <typename T>
int size(T& a) {
  return (int)a.size();
}
template <typename T>
T sqr(T a) {
  return a * a;
}
const int MAXE = 200100;
int to[MAXE], nxt[MAXE], head[MAXE], id[MAXE];
int edge;
void clear() {
  edge = 0;
  memset((head), (255), sizeof(head));
}
void ae(int u, int v, int i) {
  to[edge] = v;
  id[edge] = i;
  nxt[edge] = head[u];
  head[u] = edge++;
}
void dfs(int v, int p, int pedge) {
  vector<int> son;
  for (int e = head[v]; e >= 0; e = nxt[e])
    if (to[e] != p) {
      son.push_back(id[e]);
      dfs(to[e], v, e);
    }
  if (p == -1) {
    if (size(son) > 0) {
      int a = son[0];
      for (int j = (1), _up = (int)size(son); j < _up; ++j)
        printf("%d %d\n", a + 1, son[j] + 1);
    }
  } else {
    for (int j = (0), _up = (int)size(son); j < _up; ++j)
      printf("%d %d\n", pedge + 1, son[j] + 1);
  }
}
int main() {
  clear();
  int n;
  scanf("%d", &n);
  printf("%d\n", n - 1);
  for (int i = (0), _up = (int)n - 1; i < _up; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x, --y;
    printf("%d %d %d\n", 2, x + 1, y + 1);
    ae(x, y, i);
    ae(y, x, i);
  }
  dfs(0, -1, -1);
}
