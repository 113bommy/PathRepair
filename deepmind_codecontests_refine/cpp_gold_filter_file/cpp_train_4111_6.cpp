#include <bits/stdc++.h>
using namespace std;
const int maxn = 600000 + 21;
int n, x, y, k, L, R;
int a[maxn], lmax[maxn], lmin[maxn], rmin[maxn], rmax[maxn];
long long ans, cnt[maxn];
void solve(int l, int r) {
  if (l > r) return;
  int mid = (l + r) >> 1;
  if (l == r) {
    ++ans;
    return;
  }
  if (l < r) solve(l, mid), solve(mid + 1, r);
  lmax[mid] = lmin[mid] = a[mid], rmin[mid + 1] = rmax[mid + 1] = a[mid + 1];
  for (int i = mid + 2; i <= r; i++)
    rmin[i] = min(rmin[i - 1], a[i]), rmax[i] = max(rmax[i - 1], a[i]);
  for (int i = mid - 1; i >= l; i--)
    lmin[i] = min(lmin[i + 1], a[i]), lmax[i] = max(lmax[i + 1], a[i]);
  for (int i = mid + 1; i <= r; i++) {
    k = i - (rmax[i] - rmin[i]);
    if ((l <= k) && (k <= mid) && (lmin[k] >= rmin[i]) && (lmax[k] <= rmax[i]))
      ans++;
  }
  for (int i = mid; i >= l; i--) {
    k = i + (lmax[i] - lmin[i]);
    if ((mid < k) && (k <= r) && (rmin[k] >= lmin[i]) && (rmax[k] <= lmax[i]))
      ans++;
  }
  L = mid + 1, R = mid;
  for (int i = mid; i >= l; i--) {
    while ((R <= r) && (rmin[R + 1] >= lmin[i])) ++R, cnt[rmax[R] - R + n]++;
    while ((L <= R) && (rmax[L] <= lmax[i])) cnt[rmax[L] - L + n]--, ++L;
    ans += cnt[lmin[i] - i + n];
  }
  for (int i = mid + 1; i <= r; i++) cnt[rmax[i] - i + n] = 0;
  L = mid + 1, R = mid;
  for (int i = mid + 1; i <= r; i++) {
    while ((L >= l) && (lmin[L - 1] >= rmin[i])) --L, cnt[lmax[L] + L]++;
    while ((L <= R) && (lmax[R] <= rmax[i])) cnt[lmax[R] + R]--, --R;
    ans += cnt[rmin[i] + i];
  }
  for (int i = l; i <= mid; i++) cnt[lmax[i] + i] = 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    a[x] = y;
  }
  solve(1, n);
  printf("%I64d\n", ans);
  return 0;
}
