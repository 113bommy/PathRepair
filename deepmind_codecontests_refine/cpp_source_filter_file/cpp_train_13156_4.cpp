#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
long long mem[MAXN + 1][2];
int visited[MAXN + 1][2];
int b[MAXN + 1][2];
int a[MAXN + 1];
int n;
int input() {
  int i;
  scanf("%d", &n);
  for (i = 2; i <= n; i++) scanf("%d", &a[i]);
  return 0;
}
int search(int x, int k) {
  int i, tx;
  if (visited[x][k] == 1) {
    mem[x][k] = -1;
    return 0;
  }
  if (visited[x][k] == 2) {
    return 0;
  }
  if (x == 1 && k == 1) {
    b[x][k] = 1;
    mem[x][k] = 0;
    return 0;
  }
  mem[x][k] += a[x];
  visited[x][k] = 1;
  tx = x;
  if (k)
    tx -= a[x];
  else
    tx += a[x];
  if (tx >= 1 && tx <= n) {
    search(tx, k ^ 1);
    if (mem[tx][k ^ 1] != -1) {
      mem[x][k] += mem[tx][k ^ 1];
      b[x][k] = b[tx][k ^ 1];
    } else
      mem[x][k] = -1;
  }
  visited[x][k] = 2;
  return 0;
}
int solve() {
  int i;
  memset(visited, 0, sizeof(visited));
  memset(mem, 0, sizeof(mem));
  memset(b, 0, sizeof(b));
  visited[1][0] = 1;
  for (i = 2; i <= n; i++)
    if (!visited[i][1]) search(i, 1);
  for (i = 1; i < n; i++) {
    a[1] = i;
    a[0] = 0;
    if (mem[i + 1][1] == -1)
      printf("-1\n");
    else
      printf("%d\n", mem[i + 1][1] + i + a[b[i + 1][1]]);
  }
  return 0;
}
int main() {
  input();
  solve();
  return 0;
}
