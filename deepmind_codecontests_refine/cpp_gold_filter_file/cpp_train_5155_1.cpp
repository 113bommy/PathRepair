#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m;
int a[maxn];
int mx;
void solve() {
  for (int i = 1; i <= n; i++) a[i] -= mx;
  long long ans = 1LL * mx * n;
  int l = 0, r = 0;
  int posl = 0, posr = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      l = i - 1;
      posl = i;
      break;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] == 0) {
      r = n - i;
      posr = i;
      break;
    }
  }
  int res = 0;
  for (int i = posl; i <= posr;) {
    int j = i;
    if (a[i] == 0) {
      i++;
      continue;
    }
    while (a[j] != 0 && j <= posr) j++;
    res = max(res, j - i);
    i = j;
  }
  res = max(res, l + r);
  ans += 1LL * res;
  printf("%I64d\n", ans);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    mx = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      mx = min(a[i], mx);
    }
    solve();
  }
  return 0;
}
