#include <bits/stdc++.h>
using namespace std;
int x[400], vis[400];
int main() {
  int p, n, ans;
  scanf("%d%d", &p, &n);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (int i = 1; i <= n; i++) {
    int pos = x[i] % p;
    if (!vis[pos])
      vis[pos] = 1;
    else {
      ans = i;
      break;
    }
  }
  if (ans <= n)
    printf("%d\n", ans);
  else
    printf("-1\n");
  return 0;
}
