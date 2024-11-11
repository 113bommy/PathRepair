#include <bits/stdc++.h>
using namespace std;
const int N = 1505;
void f1(int& x, int y) {
  if (x < y) {
    x = y;
  }
}
int n, s, m, k, a[N], maxr[N], pre[N], f[N][N];
bool lite(int x) {
  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1] + (a[i] <= x);
  }
  memset(f, 0, sizeof f);
  int answer = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      f1(f[i][j], f[i - 1][j]);
      if (maxr[i]) {
        f1(f[maxr[i]][j + 1], f[i - 1][j] + pre[maxr[i]] - pre[i - 1]);
      }
      if (i == n) {
        f1(answer, f[n][j]);
      }
    }
  }
  return answer >= k;
}
int main() {
  scanf("%d%d%d%d", &n, &s, &m, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= s; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    for (int j = l; j <= r; ++j) {
      f1(maxr[j], r);
    }
  }
  int l = 1, r = 1e9;
  while (l != r) {
    int mid = l + r >> 1;
    if (lite(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", lite(l) ? l : -1);
  return 0;
}
