#include <bits/stdc++.h>
using namespace std;
int vis[100004][2];
int w, n, k;
char a[100004];
char c[100004];
void dfs(int i, int b) {
  if (i > n) {
    printf("YES\n");
    exit(0);
  }
  if (i < w) return;
  if (b) {
    if (c[i] == 'X') return;
  } else {
    if (a[i] == 'X') return;
  }
  if (vis[i][b]) return;
  vis[i][b] = 1;
  w++;
  dfs(i - 1, b);
  dfs(i + 1, b);
  dfs(i + k, !b);
  w--;
}
int main() {
  scanf("%d %d", &n, &k);
  scanf("%s", a);
  scanf("%s", c);
  dfs(0, 0);
  printf("NO\n");
  return 0;
}
