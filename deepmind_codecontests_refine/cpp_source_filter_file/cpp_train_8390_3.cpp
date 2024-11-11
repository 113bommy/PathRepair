#include <bits/stdc++.h>
using namespace std;
using INT = long long;
const int NN = 202020;
INT a[NN], org[NN], b[NN];
int main() {
  INT n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) scanf("%I64d", org + i);
  int nn = 0;
  for (int i = 1; i <= n; i++) {
    if (org[i]) {
      for (int j = i; j <= n; j++) {
        a[++nn] = org[j];
      }
      break;
    }
  }
  n = nn;
  INT mx = 0;
  for (int i = 1; i <= n; i++) mx = max(mx, a[i]);
  if (mx >= k) {
    puts("0");
    return 0;
  }
  if (n == 2) {
    INT ans = (k - a[2] + a[1] - 1) / a[1];
    cout << ans << endl;
    return 0;
  }
  if (n == 3) {
    INT st = 0, ed = 2e9;
    while (st + 1 < ed) {
      INT md = (st + ed) / 2;
      INT fd = md * (md + 1) / 2;
      if (a[1] >= (k - fd + 1) / fd)
        ed = md;
      else if (fd * a[1] + md * a[2] + a[3] >= k)
        ed = md;
      else
        st = md;
    }
    cout << ed << endl;
    return 0;
  }
  INT ans = 0;
  mx = 0;
  while (1) {
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
      a[i] = b[i];
      mx = max(mx, a[i]);
    }
    ans++;
    if (mx >= k) {
      cout << ans << endl;
      return 0;
    }
  }
  return 0;
}
