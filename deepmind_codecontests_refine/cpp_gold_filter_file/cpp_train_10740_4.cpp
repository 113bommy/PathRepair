#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long i, j = 0, r = 200, p, q, k = 0, ans = 0, d, y = 0, x, h, flag = 0,
               n, m = 0, a = 1000000007, b = 1000000007, id, c, h1, h2, a1, b1,
               w;
  cin >> b >> w;
  if (b > 3 * w + 1 or w > 3 * b + 1) {
    cout << "NO" << endl;
    return;
  } else
    cout << "YES" << endl;
  long long xi;
  long long yi;
  if (b > w) {
    xi = 100000;
    yi = 100000;
  }
  long long xf;
  if (w > b) {
    swap(b, w);
    xi = 100001;
    yi = 100000;
    flag = 1;
  }
  if (w == b) {
    xi = 100000;
    yi = 100000;
  }
  for (i = 0; i < w; i++) {
    cout << xi << " " << yi << endl;
    xf = xi;
    xi++;
    cout << xi << " " << yi << endl;
    xi++;
  }
  xi = 100000;
  b -= w;
  k = 0;
  if (flag) xi++;
  for (i = 0; i < b; i++) {
    if (xi > xf) break;
    cout << xi << " " << yi + 1 << endl;
    xi++;
    xi++;
    k++;
  }
  xi = 100000;
  b -= k;
  if (flag) xi++;
  k = 0;
  for (i = 0; i < b; i++) {
    if (xi > xf) break;
    cout << xi << " " << yi - 1 << endl;
    xi++;
    xi++;
    k++;
  }
  b -= k;
  if (b == 0) return;
  xi = 100000;
  if (flag) xi++;
  if (b >= 1) {
    cout << xi - 1 << " " << yi << endl;
    b--;
  }
  return;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
