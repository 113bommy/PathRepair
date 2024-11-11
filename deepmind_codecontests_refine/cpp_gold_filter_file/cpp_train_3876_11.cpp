#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int M = 3e6 + 5;
const int N = 305;
int read() {
  int s = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * f;
}
int n, m, Q, tot, num;
struct Node {
  int x, y, c1, c2;
} P[M];
int a[N][N], b[N][N], id[N][N], fa[M], Ans[M];
int Find(int x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }
void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (x != y) {
    fa[y] = x;
    num--;
  }
}
void update(int x, int y) {
  if (a[x][y] == a[x - 1][y] && id[x - 1][y]) Union(id[x][y], id[x - 1][y]);
  if (a[x][y] == a[x + 1][y] && id[x + 1][y]) Union(id[x][y], id[x + 1][y]);
  if (a[x][y] == a[x][y - 1] && id[x][y - 1]) Union(id[x][y], id[x][y - 1]);
  if (a[x][y] == a[x][y + 1] && id[x][y + 1]) Union(id[x][y], id[x][y + 1]);
}
void Update(int i, int x, int y, int c, int f) {
  id[x][y] = ++tot;
  a[x][y] = c;
  num = 1;
  update(x, y);
  Ans[i] += num * f;
}
int main() {
  n = read();
  m = read();
  Q = read();
  for (int i = 1; i <= Q; i++) {
    int x = read(), y = read(), c = read();
    P[i] = (Node){x, y, b[x][y], c};
    b[x][y] = c;
  }
  memset(a, -1, sizeof(a));
  for (int i = 1; i < M; i++) fa[i] = i;
  tot = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      id[i][j] = ++tot;
      a[i][j] = 0;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) update(i, j);
  for (int i = 1; i <= Q; i++)
    if (a[P[i].x][P[i].y] != P[i].c2) Update(i, P[i].x, P[i].y, P[i].c2, 1);
  memset(a, -1, sizeof(a));
  for (int i = 1; i < M; i++) fa[i] = i;
  tot = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      id[i][j] = ++tot;
      a[i][j] = b[i][j];
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) update(i, j);
  for (int i = Q; i >= 1; i--)
    if (a[P[i].x][P[i].y] != P[i].c1) Update(i, P[i].x, P[i].y, P[i].c1, -1);
  Ans[0] = 1;
  for (int i = 1; i <= Q; i++) Ans[i] += Ans[i - 1];
  for (int i = 1; i <= Q; i++) printf("%d\n", Ans[i]);
  return 0;
}
