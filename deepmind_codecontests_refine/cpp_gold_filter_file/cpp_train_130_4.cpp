#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int a[N];
int sum[N];
int f[2 * N + 10];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum[a[i]]++;
  }
  int mx = *max_element(sum + 1, sum + n + 1);
  int cnt = 0, val;
  for (int i = 1; i <= n; i++) {
    if (mx == sum[i]) {
      cnt++;
      val = i;
    }
  }
  if (cnt > 1) {
    printf("%d\n", n);
    return 0;
  }
  int ans = 0;
  int sz = sqrt(n * 1.0);
  for (int i = 1; i <= n; i++) {
    if (sum[i] <= sz) continue;
    if (i == val) continue;
    memset(f, -1, sizeof(f));
    f[N] = 0;
    int tot = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j] == val)
        tot++;
      else if (a[j] == i)
        tot--;
      if (f[tot + N] != -1)
        ans = max(ans, j - f[tot + N]);
      else
        f[tot + N] = j;
    }
  }
  for (int i = 1; i <= sz; i++) {
    memset(f, 0, sizeof(f));
    int tot = 0;
    for (int l = 1, r = 1; r <= n; r++) {
      f[a[r]]++;
      if (f[a[r]] == i) tot++;
      while (f[a[r]] > i) {
        if (f[a[l]] == i) tot--;
        f[a[l++]]--;
      }
      if (tot >= 2) ans = max(ans, r - l + 1);
    }
  }
  printf("%d\n", ans);
  return 0;
}
