#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, r, cnt, ans;
int a[10], b[10];
struct node {
  int x, y;
} point[5005];
inline bool cmp(node a, node b) {
  return a.x * a.x + a.y * a.y > b.x * b.x + b.y * b.y;
}
inline int pre(node a, node b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
void dfs(int x, int first, int num) {
  if (x == n + 1) {
    if (ans >= num) return;
    for (int i = 1; i <= n; i++) a[i] = b[i];
    ans = num;
    return;
  }
  for (int i = first; i <= 18 && i <= cnt; i++) {
    int tmp = num;
    b[x] = i;
    for (int j = 1; j < x; j++) tmp += pre(point[i], point[b[j]]);
    dfs(x + 1, i, tmp);
  }
}
int main() {
  n = read();
  r = read();
  for (int i = -r; i <= r; i++)
    for (int j = -r; j <= r; j++)
      if (i * i + j * j <= r * r) point[++cnt] = (node){i, j};
  sort(point + 1, point + cnt + 1, cmp);
  dfs(1, 1, 0);
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) printf("%d %d \n", point[a[i]].x, point[a[i]].y);
  return 0;
}
