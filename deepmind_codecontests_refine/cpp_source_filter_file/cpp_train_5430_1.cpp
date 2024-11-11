#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return x * f;
}
const int N = 300005;
int n, m, a[N], ans;
int check(int k) {
  int mx = m;
  for (int i = n; i; --i) {
    if (a[i] + k <= m) {
      if (a[i] > mx) return 0;
      mx = min(mx, a[i] + k);
    } else {
      if (a[i] <= mx)
        continue;
      else
        mx = min(mx, (a[i] + k) % m);
    }
  }
  return 1;
}
signed main() {
  n = rd(), m = rd();
  for (int i = 1; i <= n; ++i) a[i] = rd();
  int l = 0, r = m;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}
