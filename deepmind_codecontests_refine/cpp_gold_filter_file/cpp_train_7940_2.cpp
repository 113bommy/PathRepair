#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int a[500101], b[500101], fl[500101];
int q[500101], qn;
void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &b[i]);
    fl[b[i]] = 1;
  }
  int fl2 = 0;
  for (int i = 2; i <= k; i++)
    if (a[b[i]] <= a[b[i - 1]] || a[b[i]] - a[b[i - 1]] < b[i] - b[i - 1]) {
      fl2 = 1;
      break;
    }
  if (fl2) {
    printf("-1\n");
    return;
  }
  for (int i = 1; i <= n; i++) a[i] -= i;
  q[0] = -1000000007;
  int last = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= q[qn]) {
      q[++qn] = a[i];
      if (fl[i]) last = qn;
    } else {
      int p = upper_bound(q + 1, q + 1 + qn, a[i]) - q;
      if (p > last) {
        q[p] = a[i];
        if (fl[i]) last = qn = p;
      }
    }
  }
  printf("%d\n", n - qn);
}
int main() {
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
