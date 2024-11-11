#include <bits/stdc++.h>
using namespace std;
inline int Max(int x, int y) { return x > y ? x : y; }
inline int Min(int x, int y) { return x < y ? x : y; }
inline int Abs(int x) { return x < 0 ? -x : x; }
inline double Fmax(double x, double y) { return x > y ? x : y; }
inline double Fmin(double x, double y) { return x < y ? x : y; }
inline double Fabs(double x) { return x < 0 ? -x : x; }
const int M = 1e5 + 5;
int n;
long long ans;
int a[M];
int mx[M], mn[M], rec[M * 2];
void dfs(int l, int r) {
  if (l == r) {
    ans++;
    return;
  }
  int mid = (l + r) / 2;
  dfs(l, mid);
  dfs(mid + 1, r);
  mx[mid] = mn[mid] = a[mid];
  mx[mid + 1] = mn[mid + 1] = a[mid + 1];
  for (int i = mid - 1; i >= l; i--) {
    mx[i] = Max(mx[i + 1], a[i]);
    mn[i] = Min(mn[i + 1], a[i]);
  }
  for (int i = mid + 2; i <= r; i++) {
    mx[i] = Max(mx[i - 1], a[i]);
    mn[i] = Min(mn[i - 1], a[i]);
  }
  for (int i = mid; i >= l; i--) {
    int p = mx[i] - mn[i] + i;
    if (mid + 1 <= p && p <= r && mx[p] < mx[i] && mn[i] < mn[p]) ans++;
  }
  for (int i = mid + 1; i <= r; i++) {
    int p = mn[i] - mx[i] + i;
    if (l <= p && p <= mid && mx[p] < mx[i] && mn[i] < mn[p]) ans++;
  }
  int p1 = mid + 1, p2 = mid + 1;
  for (int i = mid; i >= l; i--) {
    while (p1 <= r && mn[p1] > mn[i]) {
      rec[mx[p1] - p1 + n]++;
      p1++;
    }
    while (p2 < p1 && mx[p2] < mx[i]) {
      rec[mx[p2] - p2 + n]--;
      p2++;
    }
    ans += rec[mn[i] - i + n];
  }
  while (p2 < p1) {
    rec[mx[p2] - p2 + n]--;
    p2++;
  }
  p1 = p2 = mid;
  for (int i = mid + 1; i <= r; i++) {
    while (p1 >= l && mn[p1] > mn[i]) {
      rec[mx[p1] + p1]++;
      p1--;
    }
    while (p2 > p1 && mx[p2] < mx[i]) {
      rec[mx[p2] + p2]--;
      p2--;
    }
    ans += rec[mn[i] + i];
  }
  while (p2 > p1) {
    rec[mx[p2] + p2]--;
    p2--;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i <= n; i++) {
    scanf("%d%d", &x, &y);
    a[x] = y;
  }
  dfs(1, n);
  printf("%lld", ans);
  return 0;
}
