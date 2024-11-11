#include <bits/stdc++.h>
using namespace std;
int a[1000], b[1000], c[200000];
int main() {
  int n, x;
  long long t, p;
  cin >> n;
  x = 0;
  p = 1;
  a[-1] = 2147483647;
  for (int nn = 0; nn < n; ++nn) {
    cin >> t;
    if (t == p * 2) {
      p *= 2;
      a[x - 1] -= a[x];
      x++;
    }
    if (t == p) {
      if (a[x] < a[x - 1])
        ++a[x];
      else
        ++b[x];
    } else
      ++b[x];
  }
  a[x - 1] -= a[x];
  int ans = 0;
  while (ans >= 0) {
    ans = 0;
    int tt = 0;
    for (int i = x; i >= 0; --i) {
      ans += a[i] - b[i];
      tt += a[i];
      if (ans < 0) break;
    }
    if (ans < 0) break;
    ++c[0];
    c[c[0]] = tt;
    int j = 0;
    while (a[j] == 0) ++j;
    --a[j];
    for (int i = 0; i <= j; ++i) ++b[i];
  }
  if (c[0] == 0)
    cout << "-1";
  else
    for (int i = c[0]; i > 0; --i) cout << c[i] << " ";
  cout << endl;
  return 0;
}
