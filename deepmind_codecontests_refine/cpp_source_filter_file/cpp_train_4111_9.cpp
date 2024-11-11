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
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f == 1 ? x : -x;
}
const int N = 3e5 + 4;
long long ans = 0;
int n, a[N], mx[N], mn[N], cnt[N << 1];
inline void solve(int l, int r) {
  if (l == r) return ++ans, void();
  int mid = l + r >> 1;
  mx[mid] = mn[mid] = a[mid];
  mx[mid + 1] = mn[mid + 1] = a[mid + 1];
  for (int i = mid + 2; i <= r; i++) {
    mx[i] = (mx[i - 1] > a[i] ? mx[i - 1] : a[i]);
    mn[i] = (mn[i - 1] > a[i] ? a[i] : mn[i - 1]);
  }
  for (int i = mid - 1; i >= l; i--) {
    mx[i] = (mx[i + 1] > a[i] ? mx[i + 1] : a[i]);
    mn[i] = (mn[i + 1] > a[i] ? a[i] : mn[i + 1]);
  }
  int ll = mid, rr = mid;
  for (int i = mid + 1, x; i <= r; i++) {
    x = i - mx[i] + mn[i];
    if (x >= l && x <= mid && mx[x] < mx[i] && mn[x] > mn[i]) ans++;
    while (ll >= l && mx[ll] < mx[i]) {
      cnt[N + mn[ll] - ll]++;
      ll--;
    }
    while (rr > ll && mn[rr] > mn[i]) {
      cnt[N + mn[rr] - rr]--;
      rr--;
    }
    ans += cnt[N + mx[i] - i];
  }
  while (rr != ll) {
    cnt[N + mn[rr] - rr]--;
    rr--;
  }
  ll = rr = mid + 1;
  for (int i = l, x; i <= mid; i++) {
    x = mx[i] - mn[i] + i;
    if (x > mid && x <= r && mx[x] < mx[i] && mn[x] > mn[i]) ans++;
    while (rr <= r && mx[rr] < mx[i]) {
      cnt[mn[rr] + rr]++;
      rr++;
    }
    while (ll < rr && mn[ll] > mn[i]) {
      cnt[mn[ll] + ll]--;
      ll++;
    }
    ans += cnt[mx[i] + i];
  }
  while (ll != rr) {
    cnt[mn[ll] + ll]--;
    ll++;
  }
  solve(l, mid);
  solve(mid + 1, r);
}
int main() {
  n = read();
  for (int i = 1, u, v; i <= n; i++) {
    u = read();
    v = read();
    a[u] = v;
  }
  solve(1, n);
  cout << ans;
  return 0;
}
