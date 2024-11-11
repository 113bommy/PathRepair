#include <bits/stdc++.h>
using namespace std;
int a[1001];
int b[1001];
int vis[1001];
struct node {
  int x;
  int val;
};
node oa[5];
node ob[5];
int ans[1001];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    for (int j = 1; j <= n; j++) {
      scanf("%d", &b[j]);
    }
    int k = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == b[i]) {
        ans[i] = a[i];
        vis[a[i]] = 1;
        continue;
      }
      ++k;
      oa[k].x = i;
      oa[k].val = a[i];
      ob[k].x = i;
      ob[k].val = b[i];
    }
    if (k == 1) {
      for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
          ans[oa[1].x] = i;
          break;
        }
      }
    }
    if (k == 2) {
      if (vis[oa[1].val] == 0 && vis[ob[2].val] == 0) {
        ans[oa[1].x] = oa[1].val;
        ans[oa[2].x] = ob[2].val;
      } else {
        ans[oa[1].x] = ob[1].val;
        ans[oa[2].x] = oa[2].val;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i != 1) printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
