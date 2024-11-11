#include <bits/stdc++.h>
using namespace std;
int main() {
  int u, o = 0, l = 0, n, m, k;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m >> k;
  if (m > k) {
    u = m;
    m = k;
    k = u;
  }
  for (int i = m - 1; i < k - 1; i++) l = l + a[i];
  for (int i = m - 2; i > -1; i--) o = o + a[i];
  for (int j = n - 1; j >= k - 1; j--) {
    o = o + a[j];
  }
  if (o < l)
    cout << o;
  else
    cout << l;
  return 0;
}
