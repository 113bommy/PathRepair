#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int n, m;
int a[maxn];
int res0, res1;
void output(int l, int r) {
  printf("? ");
  for (int i = 1; i < l; i++) printf("0");
  for (int i = l; i <= r; i++) printf("1");
  for (int i = r + 1; i <= n; i++) printf("0");
  printf("\n");
  fflush(stdout);
}
void dfs(int l, int r) {
  if (res0 && res1) return;
  if (l == r) {
    output(l, l);
    scanf("%d", &a[++m]);
    if (a[m] - a[1] == 1)
      res0 = l;
    else
      res1 = l;
    return;
  }
  if (r - l == 1) {
    output(l, l);
    scanf("%d", &a[++m]);
    if (a[m] - a[1] == 1) res0 = l;
    if (a[1] - a[m] == 1) res1 = l;
    if (res0 && res1) return;
    dfs(r, r);
    return;
  }
  int mid = (l + r) >> 1;
  output(l, mid);
  scanf("%d", &a[++m]);
  if (a[m] - a[1] == mid - l + 1) {
    res0 = l;
    if (res0 && res1) return;
    dfs(mid + 1, r);
  } else if (a[1] - a[m] == mid - l + 1) {
    res1 = l;
    if (res0 && res1) return;
    dfs(mid + 1, r);
  } else {
    if (res0 && res1) return;
    dfs(l, mid);
    if (res0 && res1) return;
    dfs(mid + 1, r);
  }
}
int main() {
  scanf("%d", &n);
  output(1, 0);
  scanf("%d", &a[++m]);
  dfs(1, n);
  printf("! %d %d\n", res0, res1);
  fflush(stdout);
  return 0;
}
