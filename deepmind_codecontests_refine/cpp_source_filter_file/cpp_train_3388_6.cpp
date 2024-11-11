#include <bits/stdc++.h>
using namespace std;
long long a[400000], pre[400000];
int main() {
  long long n, m, i, l, l1, r, r1, k1, k2, mx = 0;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + (a[i] == 0);
  }
  l = 1, r = 1;
  while (r <= n) {
    if (pre[r] - pre[l - 1] > m)
      l++;
    else
      r++;
    if (r <= n && mx < r - l && pre[r] - pre[l - 1] <= m)
      mx = r - l, l1 = l, r1 = r;
  }
  if (mx < r - l && pre[r] - pre[l - 1] <= m) mx = r - l, l1 = l, r1 = r;
  cout << mx << '\n';
  for (i = 1; i <= n; i++) {
    if (l1 <= i && i <= r1)
      cout << 1 << ' ';
    else
      cout << a[i] << ' ';
  }
}
