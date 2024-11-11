#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
int a[MAXN];
int vis[MAXN];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      vis[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= MAXN; i++) {
      ans = max(ans, vis[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
