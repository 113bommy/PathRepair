#include <bits/stdc++.h>
using namespace std;
struct node {
  int id, num;
} nd[100010];
bool cmp(node x, node y) {
  if (x.num != y.num)
    return x.num > y.num;
  else
    return x.id > y.id;
}
int t, n, k, z, sum[100010], ans;
int a[100010];
int main() {
  cin >> t;
  while (t--) {
    scanf("%d%d%d", &n, &k, &z);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sum[0] = 0;
    for (int i = 1; i <= k + 1; i++) {
      sum[i] = sum[i - 1] + a[i];
    }
    ans = sum[k + 1];
    for (int i = 1; i <= k; i++) {
      nd[i].id = i;
      nd[i].num = a[i] + a[i + 1];
    }
    sort(nd + 1, nd + 1 + k, cmp);
    int p = 1;
    for (int j = 1; j <= z; j++) {
      int pos = k + 1 - 2 * j;
      if (pos < 1) {
        break;
      }
      while (nd[p].id > pos && p <= k) {
        p++;
      }
      int tmp = 0;
      if (p != k + 1) {
        tmp = j * nd[p].num;
      }
      ans = max(ans, sum[pos] + tmp);
    }
    printf("%d\n", ans);
  }
  return 0;
}
