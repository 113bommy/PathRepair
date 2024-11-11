#include <bits/stdc++.h>
using namespace std;
long long h[100000], p[100000], l, r;
int i, j, n, m;
long long getleft(int x) {
  int l = 0, r = m - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (p[mid] > x)
      r = mid;
    else
      l = mid;
  }
  if (p[l] > x)
    return p[l];
  else if (p[r] > x)
    return p[r];
  else
    return -1;
}
bool ok(long long t) {
  long long x1, x2, r = 0, q;
  for (int i = 0; i < n; i++) {
    long long x = t;
    q = getleft(r);
    if (q <= r || q >= h[i])
      r = max(r, h[i] + x);
    else if (t - (h[i] - q) < 0)
      return false;
    else {
      if ((t - h[i] + q) / 2 > 0)
        x2 = h[i] + (t - h[i] + q) / 2;
      else
        x2 = 0;
      x1 = max(h[i], h[i] + (t - 2 * (h[i] - q)));
      r = max(r, max(x1, x2));
    }
  }
  if (p[m - 1] > r) return false;
  return true;
}
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> h[i];
  for (i = 0; i < m; i++) cin >> p[i];
  l = 0;
  r = 100000000001;
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    if (ok(mid))
      r = mid;
    else
      l = mid;
  }
  if (ok(l))
    cout << l;
  else if (ok(r))
    cout << r;
}
