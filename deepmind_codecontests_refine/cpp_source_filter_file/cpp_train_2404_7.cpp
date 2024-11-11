#include <bits/stdc++.h>
using namespace std;
unsigned long long n, m, k;
unsigned long long a[20][20];
unsigned long long ans;
unsigned long long mid;
struct Counter {
  unsigned long long count = 0;
};
map<unsigned long long, Counter> sum[20];
void dfs_forward(int i, int j, unsigned long long s) {
  if (i >= n) {
    return;
  }
  if (j >= m) {
    return;
  }
  s ^= a[i][j];
  if (i + j == mid) {
    ++sum[i][s].count;
    return;
  }
  dfs_forward(i + 1, j, s);
  dfs_forward(i, j + 1, s);
}
void dfs_back(int i, int j, unsigned long long s) {
  if (i < 0) {
    return;
  }
  if (j < 0) {
    return;
  }
  if (i + j == mid) {
    ans += sum[i][s].count;
    return;
  }
  s ^= a[i][j];
  dfs_back(i - 1, j, s);
  dfs_back(i, j - 1, s);
}
int main() {
  scanf("%I64d %I64d %I64d", &n, &m, &k);
  mid = (n + m - 2) >> 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf(" %d", &a[i][j]);
    }
  }
  ans = 0;
  dfs_forward(0, 0, 0);
  dfs_back(n - 1, m - 1, k);
  printf("%I64d", ans);
  return 0;
}
