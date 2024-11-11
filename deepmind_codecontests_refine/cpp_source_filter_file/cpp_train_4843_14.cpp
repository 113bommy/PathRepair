#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void chkmax(T& x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
inline void chkmin(T& x, U y) {
  if (y < x) x = y;
}
const int MAXN = 111111;
int id[MAXN], a[MAXN], b[MAXN];
long long s[MAXN];
bool cmp(int u, int v) { return a[u] < a[v]; }
int main() {
  int n;
  long long A, cf, cm, m;
  cin >> n >> A >> cf >> cm >> m;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[id[i]];
  for (int i = 1; i <= n; i++) b[i] = a[id[i]];
  long long cur = 0, ans = -1, cmin = -1, cmax = 0;
  for (int i = n; i >= 0 && cur <= m; i--) {
    int lo = 0, hi = A + 1;
    while (hi - lo > 1) {
      int mid = lo + hi >> 1;
      int j = lower_bound(b + 1, b + n + 1, mid) - b - 1;
      long long cost = 1LL * mid * j - s[j];
      if (cost <= m - cur)
        lo = mid;
      else
        hi = mid;
    }
    long long ret = (n - i) * cf + lo * cm;
    if (ret > ans) ans = ret, cmax = n - i, cmin = lo;
    cur += A - b[i];
  }
  cout << ans << endl;
  for (int i = n; i > n - cmax; i--) a[id[i]] = A;
  for (int i = 1; i <= n; i++) {
    a[i] = max(cmin, (long long)a[i]);
    printf("%d ", a[i]);
  }
  puts("");
  return 0;
}
