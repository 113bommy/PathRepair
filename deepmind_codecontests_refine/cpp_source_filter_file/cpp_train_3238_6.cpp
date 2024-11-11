#include <bits/stdc++.h>
using namespace std;
const int _ = 1e6 + 20;
int a[_], b[_], n, c[_], d[_];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int mi = -2e9, s = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] < 0) mi = max(mi, a[i]), s ^= 1;
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 0) {
      c[++c[0]] = i;
      continue;
    }
    if (s && a[i] == mi) {
      s = 0;
      c[++c[0]] = i;
      continue;
    }
    d[++d[0]] = i;
  }
  for (int i = 1; i < c[0]; ++i)
    cout << "1 " << c[i] << " " << c[i + 1] << endl;
  if (d[0]) cout << "2 " << c[c[0]] << endl;
  for (int i = 1; i < d[0]; ++i)
    cout << "1 " << d[i] << " " << d[i + 1] << endl;
  return 0;
}
