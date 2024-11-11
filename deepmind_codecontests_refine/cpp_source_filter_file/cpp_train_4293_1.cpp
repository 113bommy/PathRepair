#include <bits/stdc++.h>
using namespace std;
int b[105], vis[105];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int pd = 0;
    memset(vis, 0, sizeof(vis));
    int maxx = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &b[i]);
      maxx = max(maxx, b[i]);
      vis[b[i]] = 1;
    }
    if (maxx >= 2 * n) pd = 1;
    if (pd) {
      printf("-1\n");
      continue;
    }
    vector<int> e;
    int pos = 1;
    for (int i = 0; i < n; i++) {
      pos = 1;
      while (pos <= b[i] || vis[pos] == 1) pos++;
      if (pos > 2 * n) break;
      vis[pos] = 1;
      e.push_back(pos);
    }
    if (e.size() != n) {
      printf("-1\n");
      continue;
    }
    for (int i = 0; i < n; i++) printf("%d %d ", b[i], e[i]);
    printf("\n");
  }
}
