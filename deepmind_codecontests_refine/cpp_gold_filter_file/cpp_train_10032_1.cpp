#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000007;
int a[MAXN];
int l[MAXN];
bool vis[MAXN];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    memset(vis, 0, sizeof(vis));
    int i, j;
    for (i = 1; i <= n; i++) {
      scanf("%d", a + i);
      vis[a[i]] = 1;
      l[i] = i - 1;
      j = i;
      int t, sum = a[i];
      while (l[j]) {
        t = l[j];
        if ((sum | a[t]) == sum)
          l[j] = l[t];
        else
          sum |= a[t];
        vis[sum] = 1;
        j = t;
      }
    }
    int cnt = 0;
    for (i = 0; i < MAXN; i++)
      if (vis[i]) cnt++;
    printf("%d\n", cnt);
  }
  return 0;
}
