#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int n, s[N], mn[N], mx[N], sum[N * 2];
long long ans;
void divide(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  divide(l, mid);
  divide(mid + 1, r);
  mn[mid] = mx[mid] = s[mid];
  mn[mid + 1] = mx[mid + 1] = s[mid + 1];
  for (int i = mid - 1; i >= l; i--)
    mn[i] = min(s[i], mn[i + 1]), mx[i] = max(s[i], mx[i + 1]);
  for (int i = mid + 2; i <= r; i++)
    mn[i] = min(s[i], mn[i - 1]), mx[i] = max(s[i], mx[i - 1]);
  for (int i = mid; i >= l; i--) {
    int j = mx[i] - mn[i] + i;
    if (j > mid && j <= r && mx[j] < mx[i] && mn[j] > mn[i]) ans++;
  }
  for (int j = mid + 1; j <= r; j++) {
    int i = j - mx[j] + mn[j];
    if (i >= l && i <= mid && mx[j] > mx[i] && mn[j] < mn[i]) ans++;
  }
  int hea, tai;
  hea = tai = mid + 1;
  for (int i = mid; i >= l; i--) {
    while (tai <= r && mn[tai] > mn[i]) ++sum[mx[tai] - tai + n], ++tai;
    while (hea < tai && mx[hea] < mx[i]) --sum[mx[hea] - hea + n], ++hea;
    ans += (long long)sum[mn[i] - i + n];
  }
  while (hea < tai) --sum[mx[hea] - hea + n], ++hea;
  hea = tai = mid;
  for (int j = mid + 1; j <= r; j++) {
    while (hea >= l && mn[hea] > mn[j]) ++sum[mx[hea] + hea], --hea;
    while (tai > hea && mx[tai] < mx[j]) --sum[mx[tai] + tai], --tai;
    ans += (long long)sum[mn[j] + j];
  }
  while (tai > hea) --sum[mx[tai] + tai], --tai;
}
int main() {
  ans = 3e10;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    s[x] = y;
  }
  divide(1, n);
  printf("%lld", ans + (long long)n);
  return 0;
}
