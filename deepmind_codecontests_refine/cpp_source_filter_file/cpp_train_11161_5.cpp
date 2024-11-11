#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const int inf = 1e9;
inline int read() {
  int p = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    p = p * 10 + ch - '0';
    ch = getchar();
  }
  return p * f;
}
struct node {
  int x, y, nex;
} edge[N];
int len, fir[N];
void ins(int x, int y) {
  len++;
  edge[len].x = x;
  edge[len].y = y;
  edge[len].nex = fir[x];
  fir[x] = len;
}
int l[N], r[N], d[N];
int dfs(int x, int fa) {
  int tmp = r[x] - 1;
  int sz = 1;
  for (int k = fir[x]; k != -1; k = edge[k].nex) {
    int y = edge[k].y;
    if (y == fa) continue;
    l[y] = tmp;
    r[y] = tmp + sz * 2 - 1 + d[y] - 1;
    sz += dfs(y, x);
    tmp--;
  }
  return sz;
}
int main() {
  int n = read();
  len = 0;
  memset(fir, -1, sizeof(fir));
  memset(d, 0, sizeof(d));
  for (int i = 1; i < n; i++) {
    int x, y;
    x = read();
    y = read();
    ins(x, y);
    ins(y, x);
    d[x]++;
    d[y]++;
  }
  l[1] = 1;
  r[1] = d[1] + 2;
  dfs(1, 0);
  for (int i = 1; i <= n; i++) printf("%d %d\n", l[i], r[i]);
  return 0;
}
