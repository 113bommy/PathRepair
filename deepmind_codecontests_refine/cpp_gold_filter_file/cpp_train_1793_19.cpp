#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, m;
int cnt[maxn];
int a[maxn][10];
int num[270];
int ans1, ans2;
bool check(int cur) {
  memset(num, 0, sizeof(num));
  for (int i = 1; i <= n; i++) {
    int x = 0;
    for (int j = m - 1; j >= 0; j--) {
      if (a[i][j] >= cur) x += (1 << j);
    }
    num[x] = i;
  }
  for (int i = 0; i < (1 << m); i++) {
    for (int j = 0; j < (1 << m); j++) {
      if (num[i] != 0 && num[j] != 0 && (j | i) == (1 << m) - 1) {
        ans1 = num[i];
        ans2 = num[j];
        return true;
      }
    }
  }
  return false;
}
int main() {
  int r = -1, l = 1e9 + 10;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      r = max(r, a[i][j]);
      l = min(l, a[i][j]);
    }
  }
  int mid;
  while (l < r) {
    mid = (l + r + 1) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  check(l);
  printf("%d %d", ans1, ans2);
  return 0;
}
