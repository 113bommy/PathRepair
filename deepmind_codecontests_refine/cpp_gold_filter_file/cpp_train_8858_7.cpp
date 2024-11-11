#include <bits/stdc++.h>
using namespace std;
int n, a[1006], res[1006], len1 = 1, len2 = 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    if (v != n) return cout << "NO", 0;
    a[u]++;
  }
  int dem = 0;
  for (int i = 1; i <= n; i++) {
    dem += a[i];
    if (dem > i) return cout << "NO", 0;
  }
  cout << "YES" << endl;
  res[1] = n;
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] == 0) {
      while (res[len2]) len2++;
      res[len2] = i;
      continue;
    }
    len1 += a[i];
    res[len1] = i;
  }
  for (int i = 1; i < n; i++) cout << res[i] << " " << res[i + 1] << endl;
  return 0;
}
