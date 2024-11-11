#include <bits/stdc++.h>
using namespace std;
int aa[100000];
int ab[200000];
int ans[200000];
bool dfs(int u = 0, int c = 0) {
  if (ans[u] == c) return true;
  if (ans[u] != -1) return false;
  ans[u] = c;
  return dfs(u ^ 1, c ^ 1) && dfs(ab[u], c ^ 1);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    ab[a - 1] = b - 1;
    ab[b - 1] = aa[i - 1] = a - 1;
  }
  memset(ans, -1, sizeof(ans));
  for (int i = 0; i < n + n; i++)
    if (ans[i] == -1 && !dfs(i)) {
      puts("-1");
      return 0;
    }
  for (int i = 0; i < n; i++)
    printf("%d %d\n", 1 + ans[aa[i]], 1 + ans[ab[aa[i]]]);
  return 0;
}
