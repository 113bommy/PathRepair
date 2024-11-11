#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, x[N], b[N * 3], *bk = b + N, mx[N], mn[N];
long long solve(int l, int r) {
  if (l == r) return 1;
  long long ans = 0;
  int mid = (l + r) >> 1;
  ans += solve(l, mid);
  ans += solve(mid + 1, r);
  mx[mid + 1] = mn[mid + 1] = x[mid + 1];
  mx[mid] = mn[mid] = x[mid];
  for (int i = mid + 2; i <= r; i++)
    mx[i] = max(mx[i - 1], x[i]), mn[i] = min(mn[i - 1], x[i]);
  for (int i = mid - 1; i >= l; i--)
    mx[i] = max(mx[i + 1], x[i]), mn[i] = min(mn[i + 1], x[i]);
  for (int i = mid; i >= l; i--) {
    int p = mx[i] - mn[i] + i;
    if (p > mid && p <= r && mx[i] > mx[p] && mn[i] < mn[p]) ans++;
  }
  for (int i = mid + 1; i <= r; i++) {
    int p = i - mx[i] + mn[i];
    if (p >= l && p <= mid && mx[i] > mx[p] && mn[i] < mn[p]) ans++;
  }
  int i = mid + 1, j = mid + 1;
  for (int k = mid; k >= l; k--) {
    while (mn[j] > mn[k] && j <= r) bk[mx[j] - j]++, j++;
    while (mx[i] < mx[k] && i < j) bk[mx[i] - i]--, i++;
    ans += bk[mn[k] - k];
  }
  while (i < j) bk[mx[i] - i]--, i++;
  i = mid, j = mid;
  for (int k = mid + 1; k <= r; k++) {
    while (mn[j] > mn[k] && j >= l) bk[mx[j] + j]++, j--;
    while (mx[i] < mx[k] && i > j) bk[mx[i] + i]--, i--;
    ans += bk[mn[k] + k];
  }
  while (i > j) bk[mx[i] + i]--, i--;
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, a, b; i <= n; ++i) {
    scanf("%d%d", &a, &b);
    x[a] = b;
  }
  printf("%lld\n", solve(1, n));
  return 0;
}
