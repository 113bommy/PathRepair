#include <bits/stdc++.h>
using namespace std;
int n, luu[1005], dem;
struct toado {
  int x1, x2, x3, x4, x5;
} a[1005], vect[1005][1005];
toado vt(int i, int j) {
  return {a[j].x1 - a[i].x1, a[j].x2 - a[i].x2, a[j].x3 - a[i].x3,
          a[j].x4 - a[i].x4, a[j].x5 - a[i].x5};
}
bool check(toado x, toado y) {
  int tong =
      x.x1 * y.x1 + x.x2 * y.x2 + x.x3 * y.x3 + x.x4 * y.x4 + x.x5 * y.x5;
  return (tong <= 0);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = (1); i <= (n); ++i) {
    cin >> a[i].x1 >> a[i].x2 >> a[i].x3 >> a[i].x4 >> a[i].x5;
  }
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (n); ++j) vect[i][j] = vt(i, j);
  for (int i = (1); i <= (n); ++i) {
    bool fl = 0;
    for (int j = (1); j <= (n); ++j) {
      if (j == i) continue;
      for (int k = (1); k <= (n); ++k) {
        if (k == i || k == j) continue;
        if (!check(vect[i][j], vect[i][k])) {
          fl = 1;
          break;
        }
      }
      if (fl) break;
    }
    if (fl) continue;
    luu[++dem] = i;
  }
  cout << dem << '\n';
  for (int i = (1); i <= (dem); ++i) cout << luu[dem] << ' ';
  return 0;
}
