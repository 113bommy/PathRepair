#include <bits/stdc++.h>
using namespace std;
int a[10005];
int sumans = 0;
int dis[10005];
int n;
void dfs1(int x, int deep) {
  if (deep == n) {
    dis[x] = 0;
    return;
  }
  dfs1(x * 2 + 1, deep + 1);
  dfs1(x * 2 + 1, deep + 1);
  dis[x] = max(dis[x * 2 + 1] + a[x * 2 + 1], dis[x * 2 + 2] + a[x * 2 + 2]);
}
void dfs2(int x, int deep) {
  if (deep == n) {
    return;
  }
  int t1 = dis[x * 2 + 1] + a[x * 2 + 1];
  int t2 = dis[x * 2 + 2] + a[x * 2 + 2];
  if (t1 < t2) {
    sumans += t2 - t1;
    dfs2(x * 2 + 1, deep + 1);
    dfs2(x * 2 + 2, deep + 1);
  } else {
    sumans += t1 - t2;
    dfs2(x * 2 + 1, deep + 1);
    dfs2(x * 2 + 2, deep + 1);
  }
}
int main() {
  scanf("%d", &n);
  int i;
  for (i = 1; i < (1 << (n + 1)) - 1; i++) {
    scanf("%d", &a[i]);
  }
  dis[0] = 0;
  dfs1(0, 0);
  dfs2(0, 0);
  printf("%d\n", sumans);
  return 0;
}
