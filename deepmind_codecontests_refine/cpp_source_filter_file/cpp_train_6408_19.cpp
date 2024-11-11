#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int INF = 2e9;
int n, m;
int a[maxn];
int dp[maxn];
bool check(int x, int id) {
  for (int i = 1; i <= n; i++) {
    dp[i] = -INF;
  }
  if (id == 1)
    dp[1] = 0;
  else
    dp[2] = x;
  for (int i = id = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    if (dp[i - 1] >= a[i] - 1) {
      dp[i] = max(dp[i], a[i] + x);
    }
    if (dp[i - 1] >= a[i] - x - 1) {
      dp[i] = max(dp[i], a[i]);
    }
    if (i >= 3 && dp[i - 2] >= a[i] - x - 1) {
      dp[i] = max(dp[i], a[i - 1] + x);
    }
  }
  if (dp[n] >= min(m - 1, m - x - 1 + a[id])) return 1;
  return 0;
}
int main() {
  scanf("%d%d", &m, &n);
  if (n == 1) {
    printf("%d\n", m);
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + 1 + n);
  int id = 1, mx = a[1] + m - a[n];
  for (int i = 2; i <= n; i++) {
    int tmp = a[i] - a[i - 1];
    if (tmp > mx) {
      id = i;
      mx = tmp;
    }
  }
  rotate(a + 1, a + id, a + 1 + n);
  for (int i = n; i; i--) {
    a[i] -= a[1];
    if (a[i] < 0) a[i] += m;
  }
  int l = 0, r = a[1] + m - a[n] - 1, ans = a[1] + m - a[n] - 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid, 1) || check(mid, 2)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}
