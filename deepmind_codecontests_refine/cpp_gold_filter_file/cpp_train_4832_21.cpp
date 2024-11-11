#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int a[maxn];
int n, m, ma, mi;
int sum[2000005], ans[2000005];
bool ok(int mid) {
  int ans = 0, i;
  for (i = mid; i <= ma; i += mid) {
    ans += sum[i + m] - sum[i - 1];
  }
  if (ans == n) return true;
  return false;
}
int main() {
  int i, j;
  scanf("%d %d", &n, &m);
  ma = 1, mi = 1000008;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    mi = min(mi, a[i]);
    ma = max(ma, a[i]);
    sum[a[i]]++;
  }
  if (m >= mi) {
    printf("%d\n", mi);
    return 0;
  }
  for (i = 1; i <= ma + m; i++) {
    sum[i] += sum[i - 1];
  }
  for (i = mi; i > m; i--) {
    if (ok(i)) break;
  }
  printf("%d\n", i);
  return 0;
}
