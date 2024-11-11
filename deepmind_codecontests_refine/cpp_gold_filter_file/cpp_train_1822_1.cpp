#include <bits/stdc++.h>
using namespace std;
int vis[(100000 + 10)], a[(100000 + 10)], b[(100000 + 10)];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    memset(vis, 0, sizeof(vis));
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      vis[--a[i]]++;
    }
    for (int i = 0, j = 0; i < n; i++) {
      if (!vis[i]) b[j++] = i;
    }
    for (int i = 0, j = 0; i < n; i++) {
      if (vis[a[i]] > 1 || a[i] >= n) {
        vis[a[i]]--;
        a[i] = b[j++];
      }
    }
    for (int i = 0; i < n; i++) {
      if (i) printf(" ");
      printf("%d", a[i] + 1);
    }
    printf("\n");
  }
  return 0;
}
