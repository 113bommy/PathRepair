#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, m, a[maxn], b[maxn], c;
inline bool Find(int *a, int n, int x) {
  int i = lower_bound(a, a + n, x) - a;
  if (i == n || a[i] != x) return false;
  return true;
}
inline int ksm(int x, int n) {
  int ret = 1;
  while (n) {
    if (n & 1) ret = 1LL * ret * x % m;
    n >>= 1;
    x = 1LL * x * x % m;
  }
  return ret;
}
inline void solve(int *a, int n, int ty) {
  if (n <= 1 || m == 1) {
    printf("%d 1\n", ty ? (a[0] + n) % m : a[0]);
    return;
  }
  int d = ((a[1] - a[0]) % m + m) % m;
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    if (Find(a, n, (a[i] + d) % m)) ++cnt;
  d = 1LL * d * ksm(n - cnt, m - 2) % m;
  int id = -1;
  for (int i = 0; i < n; ++i)
    if (!Find(a, n, ((a[i] - d) % m + m) % m)) {
      if (id == -1) {
        id = i;
        continue;
      } else {
        puts("-1");
        return;
      }
    }
  if (ty) (a[id] += 1LL * n * d % m) %= m;
  printf("%d %d\n", a[id], d);
}
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(a, a + n);
  if (2 * n - 3 <= m)
    solve(a, n, 0);
  else {
    for (int i = 0; i < m; ++i)
      if (!Find(a, n, i)) b[c++] = i;
    solve(b, c, 1);
  }
  return 0;
}
