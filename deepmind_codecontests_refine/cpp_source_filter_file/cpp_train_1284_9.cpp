#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int e[30][30];
int v[30];
int cnt;
long long low, high, mid;
void dfs(int d, long long val) {
  if (d > n) {
    cnt++;
    return;
  }
  for (int i = 1; i <= n && cnt < k; i++) {
    if (e[d][i] && (val + e[d][i] <= mid) && !v[i]) {
      v[i] = 1;
      dfs(d + 1, val + e[d][i]);
      v[i] = 0;
    }
  }
  dfs(d + 1, val);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int u, v, w;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &u, &v, &w);
    e[u][v] = w;
  }
  if (k == 1) {
    printf("0\n");
    return 0;
  }
  low = 0;
  high = m * 1000;
  while (low < high) {
    mid = (low + high) >> 1;
    cnt = 0;
    dfs(1, 0);
    if (cnt < k) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  printf("%d\n", low);
  return 0;
}
