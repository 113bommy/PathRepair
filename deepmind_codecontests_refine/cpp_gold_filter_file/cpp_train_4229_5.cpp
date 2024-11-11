#include <bits/stdc++.h>
using namespace std;
long long n, k, a[100100], b[100100], s, m, i, j, l, h, mid;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (i = 0; i < n; i++) cin >> a[i], s += a[i];
  if (k > s) {
    cout << "-1\n";
    return 0;
  }
  l = 0, h = k;
  while (l < h) {
    mid = (l + h + 1) / 2;
    s = 0;
    for (i = 0; i < n; i++) s += min(a[i], mid);
    if (s > k)
      h = mid - 1;
    else
      l = mid;
  }
  for (i = 0; i < n; i++) k -= min(a[i], l);
  for (i = 0; i < n; i++)
    if (a[i] > l) b[m++] = i;
  for (i = k; i < m; i++) cout << b[i] + 1 << " ";
  for (i = 0; i < k; i++)
    if (a[b[i]] > l + 1) cout << b[i] + 1 << " ";
  cout << endl;
  return 0;
}
