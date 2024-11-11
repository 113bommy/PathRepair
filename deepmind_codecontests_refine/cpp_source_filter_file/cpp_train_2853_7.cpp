#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int n;
int a[1010];
struct node {
  int l, r;
} ans[1000002];
int len;
void dfs(int x, int y, int z) {
  if (a[x] == 0) return;
  int q = a[y] / a[x];
  int r = a[y] % a[x];
  int i = 0;
  while (q) {
    if (q & (1 << i)) {
      q -= (1 << i);
      a[y] -= a[x];
      a[x] *= 2;
      ans[len].l = y;
      ans[len].r = x;
    } else {
      a[z] -= a[x];
      a[x] *= 2;
      ans[len].l = z;
      ans[len].r = x;
    }
    i++;
    len++;
  }
  if (a[x] > a[z])
    dfs(y, z, x);
  else
    dfs(y, x, z);
}
bool cmp(int x, int y) { return a[x] < a[y]; }
int main() {
  while (scanf("%d", &n) != EOF) {
    int i, sum = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    len = 0;
    while (1) {
      sum = 0;
      int h[5];
      for (i = 0; i < n; i++) {
        if (sum >= 3) break;
        if (a[i] == 0) continue;
        h[sum++] = i;
      }
      if (sum < 3) break;
      sort(h, h + sum, cmp);
      dfs(h[0], h[1], h[2]);
    }
    if (sum < 2)
      printf("-1\n");
    else {
      printf("%d\n", len);
      for (i = 0; i < len; i++) {
        printf("%d %d\n", ans[i].l + 1, ans[i].r + 1);
      }
    }
  }
  return 0;
}
