#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 5;
const int maxm = 30;
int d_min[maxn][maxm], d_max[maxn][maxm], a[maxn], b[maxn];
int n, k;
void RMQ_init() {
  int i, j;
  for (i = 1; i <= n; i++) {
    d_min[i][0] = b[i];
    d_max[i][0] = a[i];
  }
  for (j = 1; (1 << j) <= n; j++)
    for (i = 1; i + (1 << j) - 1 <= n; i++) {
      d_min[i][j] = min(d_min[i][j - 1], d_min[i + (1 << (j - 1))][j - 1]);
      d_max[i][j] = max(d_max[i][j - 1], d_max[i + (1 << (j - 1))][j - 1]);
    }
}
int RMQ_min(int l, int r) {
  int k = 0;
  while ((1 << (k + 1)) <= r - l + 1) k++;
  return min(d_min[l][k], d_min[r - (1 << k) + 1][k]);
}
int RMQ_max(int l, int r) {
  int k = 0;
  while ((1 << (k + 1)) <= r - l + 1) k++;
  return max(d_max[l][k], d_max[r - (1 << k) + 1][k]);
}
int main() {
  int l, r, i, t;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  RMQ_init();
  long long ans = 0;
  int kk = 1;
  int flag = 0;
  for (int i = 1; i <= n; ++i) {
    while (RMQ_max(kk, i) - RMQ_min(kk, i) > 0 && kk < i) kk++;
    if (kk == i && a[i] != b[i])
      continue;
    else if (RMQ_max(kk, i) - RMQ_min(kk, i) < 0)
      continue;
    else {
      if (flag < kk) flag = kk;
      while (RMQ_max(flag + 1, i) - RMQ_min(flag + 1, i) == 0 && flag < i)
        flag++;
      if (flag == i && a[i] != b[i]) flag--;
      ans += flag - kk + 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
