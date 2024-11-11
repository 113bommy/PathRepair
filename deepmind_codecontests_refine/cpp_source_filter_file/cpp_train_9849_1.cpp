#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int sz[maxn];
struct edg {
  int x, y;
} edg[maxn];
int main() {
  int i, j, n, k;
  cin >> n >> k;
  for (i = 1; i <= k; i++) a[i] = 1;
  for (i = 2, j = 1; i <= n; i++) {
    edg[i].x = a[j], edg[i].y = i;
    a[j] = i;
    sz[j]++;
    j++;
    if (j > k) j = 1;
  }
  sort(sz + 1, sz + k + 1);
  printf("%d\n", sz[1] + sz[k]);
  for (i = 2; i <= n; i++) printf("%d %d\n", edg[i].x, edg[i].y);
}
