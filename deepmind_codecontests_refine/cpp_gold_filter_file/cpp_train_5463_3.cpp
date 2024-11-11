#include <bits/stdc++.h>
using namespace std;
int a[100000 + 5][5];
int st[5][100000 + 5][20], lim = 20, ret[5], ans[5];
long long sum = 0;
void build(int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      st[j][i][0] = a[i][j];
    }
  }
  for (int j = 1; j < lim; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
      for (int k = 0; k < m; k++) {
        st[k][i][j] = max(st[k][i][j - 1], st[k][i + (1 << (j - 1))][j - 1]);
      }
    }
  }
}
void query(int l, int r, int m) {
  for (int i = 0; i < m; i++) ret[i] = 0;
  for (int j = lim - 1; j >= 0; j--) {
    if ((1 << j) <= r - l + 1) {
      for (int i = 0; i < m; i++) {
        ret[i] = max(ret[i], st[i][l][j]);
      }
      l += (1 << j);
    }
  }
  sum = 0LL;
  for (int j = 0; j < m; j++) sum += (long long)ret[j];
}
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  build(n, m);
  int low = 0, high = 2 * n + 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    long long x = 2000000000000000 + 5;
    int xx[m];
    for (int i = 0; i + mid <= n; i++) {
      query(i, i + mid - 1, m);
      if (sum <= (long long)k && (sum > x || x == 2000000000000000 + 5)) {
        x = sum;
        for (int j = 0; j < m; j++) xx[j] = ret[j];
      }
    }
    if (x <= (long long)k) {
      for (int i = 0; i < m; i++) ans[i] = xx[i];
      low = mid + 1;
    } else
      high = mid - 1;
  }
  for (int i = 0; i < m; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
