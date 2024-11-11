#include <bits/stdc++.h>
using namespace std;
int aa[1000006], bb[1000006], xt = 0, n, m, x = 1, y, ma = 0;
void check(int nt, int mt) {
  if (xt) return;
  m = mt, n = nt;
  y = n + m - ma - x;
  if (y < 1 || y > m || x > n) return;
  memset(bb, 0, sizeof(bb));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) bb[abs(i - x) + abs(j - y)]++;
  int s = 0;
  for (int i = 1; i <= ma; i++) {
    if (aa[i] != bb[i]) s++;
  }
  if (!s) xt = 1;
}
int main() {
  int t, a;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> a;
    aa[a]++;
    if (a > ma) ma = a;
  }
  for (int i = 1; i <= ma; i++) {
    if (aa[i] != 4 * i) {
      x = i;
      break;
    }
  }
  for (int i = 1; i * i <= t; i++) {
    if (t % i) continue;
    check(i, t / i);
    check(t / i, i);
    if (xt) break;
  }
  if (xt) {
    cout << n << " " << m << endl << x << " " << y << endl;
  } else
    cout << "-1" << endl;
}
