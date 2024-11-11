#include <bits/stdc++.h>
using namespace std;
char s[11][40];
int n, m, ans = 0, c[11];
void dfs(int f) {
  for (int i = 0; i < f; i++)
    if (c[i] < 0) return;
  if (f == n) {
    for (int i = 0; i < n; i++)
      if (c[i] > 0) return;
    ++ans;
    return;
  }
  for (int k = 0; k <= 1; k++) {
    for (int i = 0; i < n; i++)
      if (s[i][f] == k + '0') --c[i];
    dfs(f + 1);
    for (int i = 0; i < n; i++)
      if (s[i][f] == k + '0') ++c[i];
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%s %d", s[i], &c[i]);
  dfs(0);
  printf("%d\n", ans);
}
