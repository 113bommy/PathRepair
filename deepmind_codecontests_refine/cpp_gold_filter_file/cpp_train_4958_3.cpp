#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const long long inf = 1e18;
long long f[N], g[N];
int a[N], n, k;
int c[N];
long long tot;
inline void add(int x) {
  tot += c[x];
  c[x]++;
}
inline void sub(int x) {
  c[x]--;
  tot -= c[x];
}
void solve(int l, int r, int L, int R) {
  if (l > r) return;
  int mid = l + r >> 1;
  g[mid] = inf;
  int pos;
  for (int i = mid; i >= l && i > R; i--) add(a[i]);
  for (int i = min(mid, R); i >= L; i--) {
    add(a[i]);
    if (f[i - 1] + tot < g[mid]) {
      g[mid] = f[i - 1] + tot;
      pos = i;
    }
  }
  for (int i = min(mid, R); i >= L; i--) sub(a[i]);
  for (int i = mid; i >= l && i > R; i--) sub(a[i]);
  for (int i = pos + 1; i < l && i <= R; i++) add(a[i]);
  solve(l, mid - 1, L, pos);
  for (int i = pos + 1; i < l && i <= R; i++) sub(a[i]);
  for (int i = max(l, R + 1); i <= mid; i++) add(a[i]);
  solve(mid + 1, r, pos, R);
  for (int i = max(l, R + 1); i <= mid; i++) sub(a[i]);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) f[i] = inf;
  for (int i = 1; i <= k; i++) {
    solve(1, n, 1, n);
    memcpy(f, g, sizeof(g));
  }
  printf("%I64d\n", f[n]);
  return 0;
}
