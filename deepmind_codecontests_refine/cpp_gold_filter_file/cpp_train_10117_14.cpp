#include <bits/stdc++.h>
using namespace std;
int a[550000], t[900][900];
void upd(int x, int y) {
  a[x] += y;
  for (int i = 1; i < 900; i++) t[i][x % i] += y;
}
int calc(int x, int y) {
  if (x < 900) return t[x][y];
  int ans = 0;
  for (int i = y; i <= 500000; i += x) ans += a[i];
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  int q, opt, x, y;
  cin >> q;
  while (q--) {
    cin >> opt >> x >> y;
    if (opt == 1)
      upd(x, y);
    else
      cout << calc(x, y) << '\n';
  }
  return 0;
}
