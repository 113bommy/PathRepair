#include <bits/stdc++.h>
using namespace std;
int n, m, a[51], b[51], res = 0, maxx = 0;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  cin >> m;
  for (int i = 0; i < m; ++i) cin >> b[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (!(b[j] % a[i])) maxx = max(maxx, b[j] / a[i]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (!(b[j] % a[i]) && b[j] / a[i] == maxx) ++res;
  cout << res;
  return 0;
}
