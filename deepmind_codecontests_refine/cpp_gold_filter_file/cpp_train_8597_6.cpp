#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
int n, k, tot, head[M], Next[M * 2], vet[M * 2], len[M * 2];
int f[M][2], s[M], sum[M];
void add(int a, int b, int c) {
  Next[++tot] = head[a], vet[tot] = b, len[tot] = c;
  head[a] = tot;
}
int cmp(int a, int b) { return f[a][0] > f[b][0]; }
void dfs(int x, int pre) {
  for (int i = head[x]; i; i = Next[i]) {
    int y = vet[i], z = len[i];
    if (y == pre) continue;
    dfs(y, x);
    f[y][0] += z;
    f[y][1] += z;
  }
  int t = 0;
  for (int i = head[x]; i; i = Next[i]) {
    int y = vet[i];
    if (y == pre) continue;
    s[++t] = y;
  }
  sort(s + 1, s + 1 + t, cmp);
  for (int i = 1; i <= t; i++) sum[i] = sum[i - 1] + f[s[i]][0];
  f[x][0] = sum[min(t, k - 1)];
  for (int i = 1; i <= t; i++) {
    if (i <= k)
      f[x][1] = max(f[x][1], sum[min(t, k)] - f[s[i]][0] + f[s[i]][1]);
    else
      f[x][1] = max(f[x][1], sum[k - 1] + f[s[i]][1]);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n - 1; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a++;
    b++;
    add(a, b, c);
    add(b, a, c);
  }
  dfs(1, 0);
  printf("%d", f[1][1]);
  return 0;
}
