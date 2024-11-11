#include <bits/stdc++.h>
using namespace std;
int arr[100005][5];
long long seg[400005][5];
int n, m, k;
int ans1, ans2;
void Build(int p, int k, int l, int r) {
  if (l == r) {
    seg[p][k] = arr[l][k];
    return;
  }
  Build(2 * p, k, l, (l + r) / 2);
  Build(2 * p + 1, k, (l + r) / 2 + 1, r);
  seg[p][k] = max(seg[2 * p][k], seg[2 * p + 1][k]);
}
long long Max(int p, int k, int l, int r, int i, int j) {
  if (l > j || r < i) return -1;
  if (l >= i && r <= j) {
    return seg[p][k];
  }
  long long p2 = Max(2 * p, k, l, (l + r) / 2, i, j);
  long long p1 = Max(2 * p + 1, k, (l + r) / 2 + 1, r, i, j);
  if (p1 == -1) return p2;
  if (p2 == -1) return p1;
  return max(p1, p2);
}
bool SumOfMaximums(int len) {
  for (int j = 1; j <= n - len; j++) {
    long long sum = 0;
    for (int i = 1; i <= m; i++) {
      sum += Max(1, i, 1, n, j, j + len - 1);
    }
    if (sum <= k) {
      ans1 = j;
      ans2 = j + len - 1;
      return 1;
    }
  }
  return 0;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  for (int i = 1; i <= m; i++) Build(1, i, 1, n);
  int lo = 0, hi = n, mid;
  while (lo < hi) {
    mid = lo + (hi - lo + 1) / 2;
    if (SumOfMaximums(mid)) {
      lo = mid;
    } else
      hi = mid - 1;
  }
  if (lo == 0) {
    for (int j = 0; j < m; j++) cout << 0 << ' ';
  } else {
    for (int j = 1; j <= m; j++) {
      cout << Max(1, j, 1, n, ans1, ans2) << ' ';
    }
  }
  return 0;
}
