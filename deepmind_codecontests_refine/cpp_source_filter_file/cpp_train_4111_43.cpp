#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0', c = getchar();
  }
  return x * f;
}
const int MAXN = 3e5 + 10;
int n, r[MAXN], c[MAXN], p[MAXN], a[MAXN];
long long ans = 0;
inline bool cmp(const int &a, const int &b) { return r[a] < r[b]; }
void Solve(int l, int r) {
  if (l > r) return;
  if (l == r) {
    ::ans++;
    return;
  }
  int mid = (l + r) >> 1;
  static int mx[MAXN], mn[MAXN];
  long long ans = 0;
  mx[mid] = mn[mid] = a[mid];
  mx[mid + 1] = mn[mid + 1] = a[mid + 1];
  for (int i = mid - 1; i >= l; i--)
    mn[i] = min(mn[i + 1], a[i]), mx[i] = max(mx[i + 1], a[i]);
  for (int i = mid + 2; i <= r; i++)
    mn[i] = min(mn[i - 1], a[i]), mx[i] = max(mx[i - 1], a[i]);
  static int buc[MAXN << 1];
  for (int i = l; i <= mid; i++) {
    int nr = i + mx[i] - mn[i];
    if (nr > mid && nr <= r && mn[nr] > mn[i] && mx[nr] < mx[i]) ans++;
  }
  for (int i = mid + 1; i <= r; i++) {
    int nl = i - (mx[i] - mn[i]);
    if (nl <= mid && nl >= l && mn[nl] > mn[i] && mx[nl] < mx[i]) ans++;
  }
  int j = mid + 1, k = j;
  for (int i = mid; i >= l; i--) {
    while (j <= r && mx[j] < mx[i]) {
      int now = j + mn[j] + n;
      buc[now]++, j++;
    }
    while (k < j && mn[k] > mn[i]) {
      int now = k + mn[k] + n;
      buc[now]--, k++;
    }
    ans += buc[i + mx[i] + n];
  }
  while (k < j) {
    int now = k + mn[k] + n;
    buc[now]--, k++;
  }
  j = mid + 1, k = j;
  for (int i = mid; i >= l; i--) {
    while (j <= r && mn[j] > mn[i]) {
      int now = j - mx[j] + n;
      buc[now]++, j++;
    }
    while (k < j && mx[k] < mx[i]) {
      int now = k - mx[k] + n;
      buc[now]--, k++;
    }
    ans += buc[i - mn[i] + n];
  }
  while (k < j) {
    int now = k - mx[k] + n;
    buc[now]--, k++;
  }
  ::ans += ans;
  Solve(l, mid), Solve(mid + 1, r);
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) r[i] = read(), c[i] = read();
  for (int i = 1; i <= n; i++) p[i] = i;
  sort(p + 1, p + 1 + n, cmp);
  for (int i = 1; i <= n; i++) a[i] = c[p[i]];
  Solve(1, n);
  printf("%lld\n", ans);
  return 0;
}
