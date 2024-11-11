#include <bits/stdc++.h>
using namespace std;
const int kN = 5e5 + 5;
int n, a[kN], l[kN], r[kN], b[kN], cnt;
long long ans;
signed main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    l[i] = i - 1;
    r[i] = i + 1;
  }
  for (int i = 2; i < n;) {
    int L = l[i], R = r[i];
    if (a[L] >= a[i] && a[R] >= a[i]) {
      ans += min(a[L], a[R]);
      r[L] = R;
      l[R] = L;
      i = L;
    } else {
      i = R;
    }
  }
  for (int i = 1; i <= n; i = r[i]) {
    b[++cnt] = a[i];
  }
  sort(b + 1, b + 1 + cnt);
  for (int i = 1; i < cnt - 1; ++i) {
    ans += b[i];
  }
  printf("%lld\n", ans);
  return 0;
}
