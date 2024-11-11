#include <bits/stdc++.h>
using namespace std;
struct data {
  int v, n;
};
data a[100005];
bool sf(data a, data b) { return a.v > b.v; }
int min(int a, int b) { return a < b ? a : b; }
int n, k, rst, mini = 90999;
long long s;
long long m;
int main() {
  scanf("%d%d%I64d", &n, &k, &m);
  int i, j;
  for (i = 1; i <= n; i++) scanf("%d", &a[i].v), a[i].n = i;
  sort(a + 1, a + n, sf);
  for (i = 1; i <= k; i++) {
    s += (long long)a[i].v;
    mini = min(mini, a[i].n);
  }
  if (s <= m) {
    printf("%d", n);
    return 0;
  }
  rst = mini;
  s -= (long long)a[k].v;
  for (i = k + 1; i < n; i++) {
    if (s + (long long)a[k].v > m) rst = min(rst, a[k].n);
  }
  printf("%d", rst);
  return 0;
}
