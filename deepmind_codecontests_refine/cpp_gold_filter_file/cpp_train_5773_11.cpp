#include <bits/stdc++.h>
using namespace std;
int a[10];
int dirn[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dirm[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool vis[105][105];
int n, m;
void dfsr(int r, int c) {
  int tr, tc, flag = 0;
  for (int w = 0; w < 4; w++) {
    tr = r + dirn[w][0], tc = c + dirn[w][1];
    if (tr <= n && tr >= 1 && tc <= m && tc >= 2 && vis[tr][tc] == 0) {
      flag = 1;
      break;
    }
  }
  if (flag == 0) return;
  printf("%d %d\n", tr, tc);
  vis[tr][tc] = 1;
  dfsr(tr, tc);
  return;
}
void dfsc(int r, int c) {
  int tr, tc, flag = 0;
  for (int w = 0; w < 4; w++) {
    tr = r + dirm[w][0], tc = c + dirm[w][1];
    if (tr <= n && tr >= 2 && tc <= m && tc >= 1 && vis[tr][tc] == 0) {
      flag = 1;
      break;
    }
  }
  if (flag == 0) return;
  printf("%d %d\n", tr, tc);
  vis[tr][tc] = 1;
  dfsc(tr, tc);
  return;
}
void dfs(int r, int c) {
  int tr, tc, flag = 0;
  for (int w = 0; w < 4; w++) {
    tr = r + dirn[w][0], tc = c + dirn[w][1];
    if (tr <= n && tr >= 1 && tc <= m && tc >= 1 && vis[tr][tc] == 0) {
      flag = 1;
      break;
    }
  }
  if (flag == 0) return;
  printf("%d %d\n", tr, tc);
  vis[tr][tc] = 1;
  dfs(tr, tc);
  return;
}
int main() {
  scanf("%d%d", &n, &m);
  memset(vis, 0, sizeof(vis));
  if (n == 1 && m == 2) {
    puts("0\n1 1\n1 2\n1 1");
  } else if (n == 2 && m == 1) {
    puts("0\n1 1\n2 1\n1 1\n");
  } else if (n == 1) {
    printf("1\n1 %d 1 1\n", m);
    for (int i = 1; i <= m; i++) printf("1 %d\n", i);
    puts("1 1");
  } else if (m == 1) {
    printf("1\n%d 1 1 1\n", n);
    for (int i = 1; i <= n; i++) printf("%d 1\n", i);
    puts("1 1");
  } else if ((n & 1) == 0) {
    puts("0\n1 1");
    vis[1][1] = 1;
    dfsr(1, 1);
    for (int i = n; i >= 1; i--) printf("%d 1\n", i);
  } else if ((m & 1) == 0) {
    puts("0\n1 1");
    vis[1][1] = 1;
    dfsc(1, 1);
    for (int i = m; i >= 1; i--) printf("1 %d\n", i);
  } else {
    printf("1\n%d %d 1 1\n1 1\n", n, m);
    vis[1][1] = 1;
    dfs(1, 1);
    puts("1 1");
  }
}
